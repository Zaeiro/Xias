#include "vm.h"

#include "types.h"
#include "object.h"
#include "messages.h"
#include "compilation_unit.h"
#include "utils.h"
#include "XiasLexer.h"
#include "XiasParser.h"
#include "XiasVisitor.h"
#include "XiasErrorHandler.h"

#include "antlr4-runtime.h"

#include <iostream>
#include <memory>
#include <cstring>
#include <cmath>

#define AS_DOUBLE(value) (value->as.Double)
#define AS_FLOAT(value) (value->as.Float)
#define AS_INT(value) (value->as.Int)
#define AS_UINT(value) (value->as.UInt)
#define AS_BOOL(value) (value->as.Bool)
#define AS_OBJ(value) (value->as.Object)

#define LEFT_OPERAND(type) ((sp - 2)->as.type)
#define RIGHT_OPERAND(type) ((sp - 1)->as.type)
#define UNARY_OPERAND(type) ((sp - 1)->as.type)

#define READ_CONSTANT(type) frame->Function->Code.Constants[(++frame->ip)->Data].as.type;
#define READ_CONST() frame->Function->Code.Constants[(++frame->ip)->Data] 
#define READ_SHORT() (++frame->ip)->Data

#define DEC() (sp--)
#define POP() (*(--sp))

#define GC_HEAP_GROW_FACTOR 1.75f

#ifdef DEBUG_LOG_GC 
#define ALLOCATE_OBJ(type, objectType) \
	AllocObject<type>(objectType); \
	printf("allocate %zu bytes for %s\n", sizeof(type), #objectType);
#else
#define ALLOCATE_OBJ(type, objectType) AllocObject<type>(objectType)
#endif

namespace Xias {

	std::string format(const std::string& format, const std::vector<std::string> args)
	{
		size_t size = 0;
		std::vector<std::tuple<size_t, size_t, size_t>> locations;
		size_t last = 0;
		size_t location = 0;
		while ((location = format.find('{', location)) != std::string::npos)
		{
			bool isValid = false;
			size_t digit = location + 1;
			if (std::isdigit(format[digit]))
			{
				digit++;
				while (digit != format.size())
				{
					if (std::isdigit(format[digit]))
					{
						digit++;
						continue;
					}
					else if (format[digit] == '}')
					{
						last = digit;
						isValid = true;
						break;
					}
					else
						break;
				}
				if (isValid)
				{
					size_t arg = std::strtoull(&format[location + 1], nullptr, 10);
					if (arg < args.size())
						locations.push_back({ location, arg, last });
				}
			}
			location = digit + 1;
		}

		if (!locations.empty())
		{
			size_t firstNonToken = 0;
			for (const auto& loc : locations)
			{
				size += std::get<0>(loc) - firstNonToken;
				size += args[std::get<1>(loc)].size();
				firstNonToken = std::get<2>(loc) + 1;
			}
			size += format.size() - std::get<2>(locations.back()) - 1;

			std::string result;
			result.reserve(size);
			firstNonToken = 0;
			for (const auto& loc : locations)
			{
				result.append(&format[firstNonToken], std::get<0>(loc) - firstNonToken);
				result += args[std::get<1>(loc)];
				firstNonToken = std::get<2>(loc) + 1;
			}
			result.append(&format[firstNonToken], format.size() - std::get<2>(locations.back()) - 1);
			return result;
		}

		return format;
	}

	static std::vector<std::pair<CompilationMessage::Severity, std::string>> ErrorCodes = {
		{ CompilationMessage::Severity::Fatal, "Cannot implicitly convert type '{0}' to '{1}'" },
		{ CompilationMessage::Severity::Fatal, "Operator '{0}' cannot be applied to operands of type '{1}' and '{2}'" },
		{ CompilationMessage::Severity::Fatal, "Operator '{0}' cannot be applied to operand of type '{1}'" },
		{ CompilationMessage::Severity::Fatal, "Cannot convert type '{0}' to '{1}'" },
		{ CompilationMessage::Severity::Fatal, "The type '{0}' already contains a definition for '{1}'" }, // 4
		{ CompilationMessage::Severity::Fatal, "The type '{0}' already defines a member called '{1}' with the same parameter types" },
		{ CompilationMessage::Severity::Fatal, "'{0}': member names cannot be the same as their enclosing type" },
		{ CompilationMessage::Severity::Fatal, "Duplicate '{0}' modifier" },
		{ CompilationMessage::Severity::Fatal, "The modifier '{0}' is not valid for this item" },
		{ CompilationMessage::Severity::Fatal, "Unknown item when applying modifiers" }, // 9
		{ CompilationMessage::Severity::Fatal, "More than one protection modifier" },
		{ CompilationMessage::Severity::Fatal, "Elements defined in a namespace cannot be explicitly declared as private or protected" },
		{ CompilationMessage::Severity::Fatal, "'{0}' does not contain a definition for '{1}'" },
		{ CompilationMessage::Severity::Fatal, "'{0}' is inaccessible due to its protection level" },
		{ CompilationMessage::Severity::Fatal, "Unkown compiler error" }, // 14
		{ CompilationMessage::Severity::Fatal, "Non-invocable member '{0}' cannot be used like a method" },
		{ CompilationMessage::Severity::Fatal, "No method found matching the signature '{0}'" },
		{ CompilationMessage::Severity::Fatal, "The type or namespace '{0}' could not be found, you may be missing a using directive" },
		{ CompilationMessage::Severity::Fatal, "A local named '{0}' cannot be declared in this scope because that name is used in an enclosing local scope to define a local or parameter" },
		{ CompilationMessage::Severity::Fatal, "'{0}' cannot be used as a class name" }, // 19
		{ CompilationMessage::Severity::Fatal, "The parameter name '{0}' is a duplicate" },
		{ CompilationMessage::Severity::Fatal, "The name '{0}' does not exist in the current context" },
		{ CompilationMessage::Severity::Fatal, "The name '{0}' is not allowed" },
		{ CompilationMessage::Severity::Fatal, "Arrays are not yet supported" },
		{ CompilationMessage::Severity::Fatal, "The left-hand side of an assignment must be a variable, property or indexer" }, // 24
		{ CompilationMessage::Severity::Fatal, "Cannot convert method group '{0}' to type '{1}'. Did you intend to invoke the method?" },
		{ CompilationMessage::Severity::Fatal, "'{0}' is a type, which is not valid in the current context" },
		{ CompilationMessage::Severity::Fatal, "Cannot implicitly convert type 'void' to '{0}'" },
		{ CompilationMessage::Severity::Fatal, "'{0}' is a namespace but used like a variable" },
		{ CompilationMessage::Severity::Fatal, "Cannot assign to an rvalue" }, // 29
		{ CompilationMessage::Severity::Fatal, "Types '{0}' and '{1}' are not compatible" },
		{ CompilationMessage::Severity::Fatal, "Type of conditional expression cannot be determined because '{0}' and '{1}' implicitly convert to one another" },
		{ CompilationMessage::Severity::Fatal, "Type of conditional expression cannot be determined because there is no implicit conversion between '{0}' and '{1}'" },
		{ CompilationMessage::Severity::Fatal, "Method must have a return type" },
		{ CompilationMessage::Severity::Fatal, "'{0}' is a namespace but used like a type" }, // 34
		{ CompilationMessage::Severity::Fatal, "The operand of an increment or decrement operator must be a variable, property or indexer" },
		{ CompilationMessage::Severity::Fatal, "Type '{0}' already defines a member called '{1}' with the same parameter types" },

	};

	Vm::Vm()
	{
		m_FrameCount = 0;
		m_Frames.resize(64);
		m_Stack.resize(64);
		m_StackSize = 64;
		sp = m_Stack.data();
		m_StackBack = sp;
		m_GlobalNamespace = AddInfo(nullptr, nullptr, InfoHierarchyMember::Namespace);

		m_BytesAllocated = 0;
		m_NextGC = 1024 * 4;

		AddClass("double");
		AddClass("float");
		AddClass("int");
		AddClass("uint");
		AddClass("bool");
		AddClass("Object");
		AddClass("String");

		m_Compiler = Compiler(this);
	}

	Vm::~Vm()
	{
		FreeObjects();
	}

	bool Vm::Compile(const std::string& filepath)
	{
		std::ifstream stream;
		stream.open(filepath);

		antlr4::ANTLRInputStream input(stream);
		XiasLexer lexer(&input);
		antlr4::CommonTokenStream tokens(&lexer);
		XiasParser parser(&tokens);
		const Ref<antlr4::ANTLRErrorStrategy> handler = std::static_pointer_cast<antlr4::ANTLRErrorStrategy>(std::make_shared<XiasErrorHandler>());
		parser.setErrorHandler(handler);
		XiasParser::Compilation_unitContext* tree = parser.compilation_unit();
		stream.close();

		XiasVisitor visitor;
		std::shared_ptr<CompilationUnit> unitInfo = visitor.visitCompilation_unit(tree).as<std::shared_ptr<CompilationUnit>>();
		if (LogMessages(unitInfo->m_Messages))
		{
			GenerateClassInfo(*unitInfo);
			//m_CompilationUnits.emplace_back(unitInfo);
			Compile(*unitInfo);
		}

		m_CurrentCompilationUnit++;
		return false;
	}

	bool Vm::Compile(CompilationUnit& compilationUnit)
	{
		for (ClassInfo& cInfo : compilationUnit.m_Classes)
		{
			RegisterClass(cInfo);
			if (!LogMessages())
				MarkClassForRemoval(GetClass(cInfo.m_Name));
		}

		for (ClassInfo& cInfo : compilationUnit.m_Classes)
		{
			SetParent(cInfo);
			if (!LogMessages())
				MarkClassForRemoval(GetClass(cInfo.m_Name));
		}

		for (ClassInfo& cInfo : compilationUnit.m_Classes)
		{
			CompileClass(cInfo);
			if (!LogMessages())
				MarkClassForRemoval(GetClass(cInfo.m_Name));
		}

		RemoveClasses();
		return true;
	}

	void Vm::RegisterFunction(const std::string& name, NativeFn function)
	{
		push(OBJ_VAL(NewNative(function)));
		AddGlobal(name, m_Stack[0]);
		DEC();
	}

	void Vm::RegisterVoidFunction(const std::string& name, VoidNativeFn function)
	{
		push(OBJ_VAL(NewVoidNative(function)));
		AddGlobal(name, m_Stack[0]);
		DEC();
	}

	StringObject* Vm::TakeString(char* chars, x_ulong length)
	{
		StringObject* interned = FindInternedString(chars, length);
		if (interned)
		{
			delete[] chars;
			return interned;
		}

		return AllocateString(chars, length);
	}

	StringObject* Vm::CopyString(const char* chars, x_ulong length)
	{
		StringObject* interned = FindInternedString(chars, length);
		if (interned) return interned;

		char* heapChars = AllocArray<char>(length + 1);
		std::memcpy(heapChars, chars, length);
		heapChars[length] = '\0';
		return AllocateString(heapChars, length);
	}

	StringObject* Vm::CopyString(const std::string& string)
	{
		size_t length = string.size();
		StringObject* interned = FindInternedString(string.c_str(), length);
		if (interned) return interned;

		char* heapChars = AllocArray<char>(length + 1);
		std::memcpy(heapChars, string.c_str(), length);
		heapChars[length] = '\0';
		return AllocateString(heapChars, length);
	}

	InstanceObject* Vm::NewInstance(x_class xClass)
	{
		InstanceObject* native = ALLOCATE_OBJ(InstanceObject, ObjectType::instance_object);
		native->Class = xClass;
		native->Members.resize(xClass->MemberCount);
		return native;
	}

	void Vm::AddGlobal(const std::string& name, Value& value)
	{
		m_GlobalNames.insert({ name, m_Globals.size() });
		m_Globals.emplace_back(value);
	}

	Value Vm::GetGlobal(const std::string& name)
	{
		auto iter = m_GlobalNames.find(name);
		if (iter != m_GlobalNames.end())
			return m_Globals[iter->second];
		Error("GetGlobal: Global not found!");
		return Value{ 0U };
	}

	std::shared_ptr<InfoHierarchyMember> Vm::FindInfo(const std::string& qualifiedName, size_t compilationUnitID)
	{
		return FindInfoImpl(m_GlobalNamespace, SplitQualifiedName(qualifiedName), compilationUnitID);
	}

	std::shared_ptr<InfoHierarchyMember> Vm::FindInfo(std::shared_ptr<std::string> qualifiedName, size_t compilationUnitID)
	{
		return FindInfoImpl(m_GlobalNamespace, SplitQualifiedName(qualifiedName), compilationUnitID);
	}

	std::shared_ptr<InfoHierarchyMember> Vm::FindMemberInfo(std::shared_ptr<InfoHierarchyMember> info, std::string_view name, size_t compilationUnitID)
	{
		if (compilationUnitID == -1) compilationUnitID = m_CurrentCompilationUnit;
		auto range = info->m_Children.equal_range(name);
		for (auto it = range.first; it != range.second; ++it)
		{
			// TODO: Each compilation unit should have a set of other units it may access
			// This would represent include directives
			if (it->second->m_CompilationUnitID == compilationUnitID)
			{
				return it->second;
			}
		}
		return AddInfo(nullptr, nullptr, InfoHierarchyMember::NotFound);
	}

	std::shared_ptr<InfoHierarchyMember> Vm::FindAccessibleMemberInfo(std::shared_ptr<InfoHierarchyMember> info, std::string_view name, size_t compilationUnitID)
	{
		if (compilationUnitID == -1) compilationUnitID = m_CurrentCompilationUnit;
		if (name.empty()) return info;
		std::vector<std::string_view> names = SplitQualifiedName(name);
		while (info)
		{
			std::shared_ptr<InfoHierarchyMember> searchedInfo = FindMemberInfo(info, names[0], compilationUnitID);
			if (searchedInfo->m_Category != InfoHierarchyMember::NotFound)
			{
				info = searchedInfo;
				break;
			}
			else
				info = info->m_Parent;
		}
		if (info)
			return FindInfoImpl(info->m_Parent, names, compilationUnitID);
		else
			return AddInfo(nullptr, nullptr, InfoHierarchyMember::NotFound);
	}

	std::vector<std::string_view> Vm::SplitQualifiedName(std::shared_ptr<std::string> name)
	{
		return SplitQualifiedName(*name);
	}

	std::vector<std::string_view> Vm::SplitQualifiedName(std::string_view name)
	{
		std::vector<std::string_view> names;
		if (name.empty()) return names;
		size_t begin = 0, delimiter;
		while ((delimiter = name.find(".", begin)) != std::string::npos)
		{
			names.push_back(name.substr(begin, delimiter - begin));
			begin = delimiter + 1;
		}
		names.push_back(name.substr(begin, name.size() - begin));
		return names;
	}

	std::vector<std::string_view> Vm::SplitViewSignature(std::string_view signature)
	{
		std::vector<std::string_view> names;
		size_t begin = 0, delimiter;
		while ((delimiter = signature.find(";", begin)) != std::string::npos)
		{
			names.push_back(signature.substr(begin, delimiter - begin));
			begin = delimiter + 1;
		}
		return names;
	}

	std::vector<std::string_view> Vm::QualifyInfo(std::shared_ptr<InfoHierarchyMember> info)
	{
		std::vector<std::string_view> reverseNames;
		std::vector<std::string_view> names;
		while (info && info->m_Name)
		{
			reverseNames.push_back(std::string_view(*info->m_Name));
			info = info->m_Parent;
		}
		names.reserve(reverseNames.size());
		for (int i = (int)reverseNames.size() - 1; i >= 0; i--)
			names.push_back(reverseNames[i]);
		return names;
	}

	x_class Vm::GetClass(const std::string& name)
	{
		std::string n;
		if (name == "I") n = "int";
		else if (name == "U") n = "uint";
		else if (name == "D") n = "double";
		else if (name == "G") n = "float";
		else if (name == "B") n = "bool";
		else if (name == "S") n = "String";
		else if (name == "O") n = "Object";
		else if (name == "V") n = "void";

		if (n.empty())
		{
			auto iter = m_ClassNames.find(name);
			if (iter != m_ClassNames.end())
				return m_Classes[iter->second];
			return nullptr;
		}
		else
		{
			auto iter = m_ClassNames.find(n);
			if (iter != m_ClassNames.end())
				return m_Classes[iter->second];
			return nullptr;
		}
	}

	//MemberInfo Vm::GetMemberInfo(const std::string& xClass, const std::string& name)
	//{
	//	for (const CompilationUnit& unit : m_CompilationUnits)
	//	{
	//		for (const ClassInfo& cInfo : unit.m_Classes)
	//		{
	//			for (const MemberInfo& mInfo : cInfo.m_Members)
	//			{
	//				if (mInfo.m_Name == name)
	//					return mInfo;
	//			}
	//		}
	//	}
	//	return MemberInfo();
	//}

	Member Vm::GetMember(x_class xClass, const std::string& name)
	{
		Member m;
		m.m_Type = Member::Category::NotFound;
		auto iter = m_ClassInfo.find(xClass->Name);
		if (iter != m_ClassInfo.end())
		{
			auto memberIter = iter->second.m_Members.find(name);
			if (memberIter != iter->second.m_Members.end())
			{
				return memberIter->second;
			}
		}
		return m;
	}

	bool Vm::IsClassDescendent(const std::string& parent, const std::string& descendent)
	{
		std::shared_ptr<InfoHierarchyMember> p, d;
		p = FindInfo(parent, m_CurrentCompilationUnit);
		d = FindInfo(descendent, m_CurrentCompilationUnit);
		if (p->m_Category != InfoHierarchyMember::Class || d->m_Category != InfoHierarchyMember::Class)
			return false;
		while (true)
		{
			if (p == d)
				return true;
			if (d->m_Category != InfoHierarchyMember::Class)
				return false;
			d = d->m_Parent;
		}
	}

	std::vector<std::string> Vm::SplitSignature(std::string signature)
	{
		std::vector<std::string> tokens;

		size_t begin = 0, delimiter;
		while ((delimiter = signature.find(";", begin)) != std::string::npos)
		{
			tokens.emplace_back(signature.substr(begin, delimiter - begin));
			begin = delimiter + 1;
		}
		//tokens.emplace_back(signature.substr(begin));
		return tokens;
	}

	std::string Vm::GetMethodName(std::string signature)
	{
		return SplitSignature(signature)[1];
	}

	std::string Vm::CompleteSignature(const std::string& signature)
	{
		std::vector<std::string> elements = SplitSignature(signature);
		for (x_class xClass : m_Classes)
		{
			for (auto& [methodSignature, methodIndex] : xClass->FunctionIndices)
			{
				std::vector<std::string> candidateElements = SplitSignature(methodSignature);
				if (candidateElements.size() != elements.size())
					continue;
				bool valid = true;
				for (int i = 1; i < candidateElements.size(); i++)
				{
					if (elements[i] != candidateElements[i])
					{
						valid = false;
						break;
					}
				}
				if (valid) return methodSignature;
			}
		}
		return std::string();
	}

	void Vm::CallFunction(Bytecode& bytecode)
	{
		// Creating function to hold supplied bytecode
		FunctionObject* function = NewFunction();
		function->Code = bytecode;
#ifdef X_DEBUG
		if (sp != &m_Stack[0])
		{
			Error("CallFunction: Stack pointer was not at the front!");
		}
		if (m_FrameCount != 0)
		{
			Error("CallFunction: There are residual stack frames!");
		}
#endif
		RunMethod(function);
	}

	void Vm::CollectGarbage()
	{
#ifdef DEBUG_LOG_GC
		size_t before = m_BytesAllocated;
		std::printf("-- gc begin\n");
		std::printf("   %zu bytes currently allocated\n", before);
#endif

		MarkRoots();
		TraceReferences();
		RemoveInterned();
		Sweep();

		m_NextGC = (size_t)(m_BytesAllocated * GC_HEAP_GROW_FACTOR);

#ifdef DEBUG_LOG_GC
		printf("-- gc end\n");
		printf("   collected %zu bytes (from %zu to %zu)\n", before - m_BytesAllocated, before, m_BytesAllocated);
		printf("   next gc at %zu\n", m_NextGC);
#endif
	}

	x_method Vm::GetImplicitConversion(x_class from, x_class to)
	{
		if (from == nullptr || to == nullptr)
			return nullptr;

		std::string castName = to->Name + ";();" + from->Name + ';';
		auto c1 = from->ImplicitCastIndices.find(castName);
		auto c2 = to->ImplicitCastIndices.find(castName);
		if (c1 != from->ImplicitCastIndices.end())
		{
			if (c2 != to->ImplicitCastIndices.end())
				return nullptr;
			return from->Functions[c1->second];
		}
		else
		{
			if (c2 != to->ImplicitCastIndices.end())
				return to->Functions[c2->second];
			return nullptr;
		}
	}

	void Vm::FreeObjects()
	{
		x_object* obj = m_Objects;
		while (obj != nullptr)
		{
			x_object* next = obj->Next;
			FreeObject(obj);
			obj = next;
		}

		for (const auto& pair : m_ClassNames)
		{
			delete m_Classes[pair.second];
		}
	}

	void Vm::FreeObject(x_object* object)
	{
#ifdef DEBUG_LOG_GC
		printf("%p free type %d\n", (void*)object, object->Type);
#endif

		switch (object->Type)
		{
			case ObjectType::string_object:
			{
				StringObject* string = (StringObject*)object;
				DeallocArray(string->Chars, string->Size);
				Dealloc(string);
				break;
			}
			case ObjectType::instance_object:
			{
				InstanceObject* instance = (InstanceObject*)object;
				Dealloc(instance);
				break;
			}
			case ObjectType::function_object:
			{
				FunctionObject* function = (FunctionObject*)object;
				Dealloc(function);
				break;
			}
			case ObjectType::native_function_object:
			{
				NativeObject* function = (NativeObject*)object;
				Dealloc(function);
				break;
			}
			case ObjectType::void_native_function_object:
			{
				VoidNativeObject* function = (VoidNativeObject*)object;
				Dealloc(function);
				break;
			}
			default:
			{
				Error("FreeObject: Unknown object type!");
			}
		}
	}

	void Vm::AddMessage(std::shared_ptr<InfoHierarchyMember> origin, x_ulong errorID, std::vector<std::string> params)
	{
		auto& message = m_Messages.emplace_back();
		message.Line = origin->m_Location.m_Line;
		message.Column = origin->m_Location.m_Column;
		message.ErrorID = errorID;
		message.Params = params;
	}

	bool Vm::LogMessages()
	{
		bool result = LogMessages(m_Messages);
		m_Messages.clear();
		return result;
	}

	bool Vm::LogMessages(std::vector<CompilationMessage>& messages)
	{
		bool success = true;
		for (CompilationMessage& msg : messages)
		{
			LogMessage(msg);
			if (ErrorCodes[msg.ErrorID].first == CompilationMessage::Severity::Fatal)
				success = false;
		}
		return success;
	}

	void Vm::LogMessage(CompilationMessage& message)
	{
		auto& msg = ErrorCodes[message.ErrorID];
		switch (msg.first)
		{
			case CompilationMessage::Severity::Fatal: std::cout << "Error "; break;
			case CompilationMessage::Severity::Warning: std::cout << "Warning "; break;
			case CompilationMessage::Severity::Hint: std::cout << "Hint "; break;
		}
		std::cout << format("(line {0}, col {1}): ", { std::to_string(message.Line), std::to_string(message.Column) });
		std::cout << format(msg.second, message.Params) << std::endl;
	}

	void Vm::Error(const char* msg)
	{
		std::cerr << sp - &m_Stack[0] << " : " << msg << std::endl;
	}

	void Vm::Error(const std::string& msg)
	{
		std::cerr << sp - &m_Stack[0] << " : " << msg << std::endl;
	}

	void Vm::CompilationError(x_class xClass, const char* msg)
	{
		std::cerr << "Error compiling class \"" << xClass->Name << "\" : " << msg << std::endl;
		RemoveClass(xClass);
	}

	void Vm::CompilationError(x_class xClass, const std::string& msg)
	{
		std::cerr << "Error compiling class \"" << xClass->Name << "\" : " << msg << std::endl;
		RemoveClass(xClass);
	}

	void Vm::RegisterClass(ClassInfo& classInfo)
	{
		x_class xClass = AddClass(classInfo.m_QualifiedName);
		xClass->MemberCount = classInfo.m_Fields.size();
		auto info = FindInfo(classInfo.m_QualifiedName);
		info->m_Class = xClass;
		xClass->Info = info;

		for (auto iter = info->m_Children.begin(); iter != info->m_Children.end(); iter++)
		{
			std::string_view name = iter->first;
			std::shared_ptr<InfoHierarchyMember> member = iter->second;
			switch (member->m_Category)
			{
				case InfoHierarchyMember::Field:
				case InfoHierarchyMember::Property:
				case InfoHierarchyMember::Indexer:
					break;
				case InfoHierarchyMember::Method:
				case InfoHierarchyMember::Constructor:
				case InfoHierarchyMember::ImplicitConversion:
				{
					std::shared_ptr<std::string> oldName = member->m_Name;
					std::vector<std::string_view> original = SplitViewSignature(*member->m_Name);
					std::shared_ptr<std::string> sig = QualifySignature(info, *member->m_Name);
					std::vector<std::string_view> tokens = SplitViewSignature(*sig);
					for (int i = (original[0] == "void" ? 2 : 0); i < tokens.size(); i++)
					{
						if (i != 1)
						{
							std::string_view token = tokens[i];
							if (token == "<unknown_type>")
							{
								AddMessage(member, no_type_or_namespace, { (std::string)original[i] });
							}
						}
					}
					std::shared_ptr<std::string> newName = std::make_unique<std::string>();
					if (original[0] == "void") tokens[0] = "void";
					for (auto strView : tokens)
					{
						*newName += strView;
						*newName += ';';
					}
					if (*oldName == *newName)
						break;
					iter = info->m_Children.erase(iter);
					info->m_Children.emplace(std::string_view(*newName), member);
					member->m_Name = newName;

					switch (member->m_Category)
					{
						case InfoHierarchyMember::Method:
						{
							for (MethodInfo& mInfo : classInfo.m_Methods)
								if (mInfo.m_Signature == *oldName)
								{
									mInfo.m_Signature = *newName;
									break;
								}
							break;
						}
						case InfoHierarchyMember::Constructor:
						{
							for (ConstructorInfo& mInfo : classInfo.m_Constructors)
								if (mInfo.m_Signature == *oldName)
								{
									mInfo.m_Signature = *newName;
									break;
								}
							break;
						}
						case InfoHierarchyMember::ImplicitConversion:
						{
							for (CastOperatorInfo& mInfo : classInfo.m_Casts)
								if (mInfo.m_Signature == *oldName)
								{
									mInfo.m_Signature = *newName;
									break;
								}
							break;
						}
					}
					break;
				}
				default:
					break;
			}
		}

		for (auto [name, member] : info->m_Children)
		{
			switch (member->m_Category)
			{
				case InfoHierarchyMember::Field:
				case InfoHierarchyMember::Property:
				case InfoHierarchyMember::Indexer:
					break;
				case InfoHierarchyMember::Method:
				{
					FunctionObject* method = NewFunction();
					ScopedPin methodPin = PinObject((x_object*)method);
					method->Signature = CopyString(*member->m_Name);
					std::vector<std::string_view> signature = SplitViewSignature(*member->m_Name);
					method->Arity = (int)signature.size() - 2;
					AddMethod(xClass, method);
					break;
				}
				case InfoHierarchyMember::Constructor:
				{
					FunctionObject* ctor = NewFunction();
					ScopedPin ctorPin = PinObject((x_object*)ctor);
					ctor->Signature = CopyString(*member->m_Name);
					std::vector<std::string_view> signature = SplitViewSignature(*member->m_Name);
					ctor->Arity = (int)signature.size() - 2;
					AddMethod(xClass, ctor);
					break;
				}
				case InfoHierarchyMember::ImplicitConversion:
				{
					FunctionObject* method = NewFunction();
					ScopedPin methodPin = PinObject((x_object*)method);
					method->Signature = CopyString(*member->m_Name);
					method->Arity = 1;
					AddImplicitCast(xClass, method);
					break;
				}
				default:
					break;
			}
		}

		for (const FieldInfo& fInfo : classInfo.m_Fields)
		{
			AddField(xClass, fInfo.m_Name);
		}

		//if (classInfo.m_Constructors.size())
		//{
		//	for (const ConstructorInfo& ctorInfo : classInfo.m_Constructors)
		//	{
		//		FunctionObject* ctor = NewFunction();
		//		ScopedPin ctorPin = PinObject((x_object*)ctor);
		//		ctor->Signature = CopyString(ctorInfo.m_Signature);
		//		ctor->Arity = ctorInfo.m_Parameters.size();
		//		AddMethod(xClass, ctor);
		//	}
		//}
		//else
		//{
		//	FunctionObject* ctor = NewFunction();
		//	ScopedPin ctorPin = PinObject((x_object*)ctor);
		//	ctor->Signature = CopyString(";<>;");
		//	AddMethod(xClass, ctor);
		//}

		//for (const MethodInfo& methodInfo : classInfo.m_Methods)
		//{
		//	FunctionObject* method = NewFunction();
		//	ScopedPin methodPin = PinObject((x_object*)method);
		//	method->Signature = CopyString(methodInfo.m_Signature);
		//	method->Arity = methodInfo.m_Parameters.size();
		//	AddMethod(xClass, method);
		//}

		//for (const OperatorInfo& operatorInfo : classInfo.m_Operators)
		//{
		//	FunctionObject* method = NewFunction();
		//	ScopedPin methodPin = PinObject((x_object*)method);
		//	method->Signature = CopyString(operatorInfo.m_Signature);
		//	method->Arity = operatorInfo.m_Parameters.size();
		//	AddMethod(xClass, method);
		//}

		//for (const CastOperatorInfo& operatorInfo : classInfo.m_Casts)
		//{
		//	FunctionObject* method = NewFunction();
		//	ScopedPin methodPin = PinObject((x_object*)method);
		//	method->Signature = CopyString(operatorInfo.m_Signature);
		//	method->Arity = 1;
		//	if (operatorInfo.m_Type == CastOperatorInfo::Implicit)
		//		AddImplicitCast(xClass, method);
		//	else
		//		AddMethod(xClass, method);
		//}
	}

	void Vm::SetParent(ClassInfo& classInfo)
	{
		size_t functionCount = 0;
		x_class xClass = GetClass(classInfo.m_QualifiedName);
		if (!xClass)
		{
			Error("SetParent: Could not find class \"" + classInfo.m_QualifiedName + "\"!");
			return;
		}

		for (auto& parent : classInfo.m_Parents)
		{
			if (xClass->Parent)
			{
				Error("SetParent: Class \"" + classInfo.m_QualifiedName + "\" already has a parent!");
				return;
			}
			x_class parentClass = GetClass(parent);
			if (!parentClass)
			{
				Error("SetParent: Could not find class \"" + parent + "\"!");
				return;
			}
			xClass->Parent = parentClass;
		}

		if (!xClass->Parent)
		{
			xClass->Parent = m_Compiler.objectClass;
		}
	}

	void Vm::CompileClass(ClassInfo& classInfo)
	{
		size_t functionCount = 0;
		x_class xClass = GetClass(classInfo.m_QualifiedName);
		if (!xClass)
		{
			Error("CompileClass: Could not find class \"" + classInfo.m_QualifiedName + "\"!");
			return;
		}

		FunctionObject* defaultInit = NewFunction();
		ScopedPin initPin = PinObject((x_object*)defaultInit);
		defaultInit->Signature = CopyString(";<>;");
		defaultInit->Code.Code.emplace_back(Instruction::create_instance);
		auto iter = m_ClassNames.find(classInfo.m_QualifiedName);
		if (iter == m_ClassNames.end())
		{
			CompilationError(xClass, "CompileClass: Could not find class!");
			return;
		}
		defaultInit->Code.Code.emplace_back(iter->second);

		Statement defaultInitBody;
		defaultInitBody.m_Type = Statement::block;
		for (const FieldInfo& fInfo : classInfo.m_Fields)
		{
			//x_class fClass = GetClass(fInfo.m_Type);
			//if (!fClass)
			//{
			//	CompilationError(xClass, "CompileClass: Could not find class '" + fInfo.m_Type + "'!");
			//	return;
			//}
			Statement& statementExpression = defaultInitBody.m_Children.emplace_back();
			statementExpression.m_Type = Statement::statement_expression;
			Expression& expression = statementExpression.m_Expressions.emplace_back();
			expression.m_Type = Expression::expression;
			Expression& assignment = expression.m_Children.emplace_back();
			assignment.m_Type = Expression::assignment;
			Expression& left = assignment.m_Children.emplace_back();
			left.m_Type = Expression::primary_no_array_creation_base;
			left.m_Line = fInfo.m_Location.m_Line;
			left.m_Column = fInfo.m_Location.m_Column;
			Expression& name = left.m_Children.emplace_back();
			name.m_Type = Expression::simple_name;
			name.m_Data.emplace_back(fInfo.m_Name);
			if (fInfo.m_VariableInitializer.m_Children.size() > 0)
			{
				// TODO: Array initializers
				assignment.m_Children.emplace_back(fInfo.m_VariableInitializer.m_Children[0]);
			}
			else
			{
				Expression& right = assignment.m_Children.emplace_back();
				right.m_Type = Expression::primary_no_array_creation_base;
				Expression& defaultValue = right.m_Children.emplace_back();
				defaultValue.m_Type = Expression::default_value;
				defaultValue.m_Data.emplace_back(fInfo.m_Type);
			}
		}

		//for (const FieldInfo& fInfo : classInfo.m_Fields)
		//{
		//	x_ulong fieldID = FindField(xClass, fInfo.m_Name);
		//	if (fieldID == -1)
		//	{
		//		CompilationError(xClass, "CompileClass: Could not find field \"" + fInfo.m_Name + "\"!");
		//		return;
		//	}
		//	CompileField(fieldID, fInfo, defaultInit);
		//}

		Compile(xClass, defaultInit, {}, defaultInitBody);

		for (ConstructorInfo& mInfo : classInfo.m_Constructors)
		{
			x_method presentctor = GetMethod(xClass, mInfo.m_Signature);
			x_method ctor = DuplicateFunction(defaultInit);
			ScopedPin ctorPin = PinObject((x_object*)ctor);
			ctor->Signature = presentctor->Signature;
			ctor->Arity = presentctor->Arity;
			Compile(xClass, ctor, mInfo.m_Parameters, mInfo.m_Body);
			ctor->Code.Code.emplace_back(Instruction::func_return);
			DuplicateFunction(ctor, presentctor);
		}

		for (MethodInfo& mInfo : classInfo.m_Methods)
		{
			x_method presentMethod = GetMethod(xClass, mInfo.m_Signature);
			x_method method = NewFunction();
			ScopedPin methodPin = PinObject((x_object*)method);
			method->Signature = presentMethod->Signature;
			method->Arity = presentMethod->Arity;
			Compile(xClass, method, mInfo.m_Parameters, mInfo.m_Body);
			DuplicateFunction(method, presentMethod);
		}

		//for (OperatorInfo& mInfo : classInfo.m_Operators)
		//{
		//	FunctionObject* method = NewFunction();
		//	ScopedPin methodPin = PinObject((x_object*)method);
		//	method->Signature = CopyString(mInfo.m_Signature);
		//	method->Arity = mInfo.m_Parameters.size();
		//	if (!Compile(xClass, method, mInfo.m_Body))
		//		return;
		//	x_method presentMethod = GetMethod(xClass, mInfo.m_Signature);
		//	DuplicateFunction(method, presentMethod);
		//}

		for (CastOperatorInfo& mInfo : classInfo.m_Casts)
		{
			x_method presentMethod = GetMethod(xClass, mInfo.m_Signature);
			x_method method = NewFunction();
			ScopedPin methodPin = PinObject((x_object*)method);
			method->Signature = presentMethod->Signature;
			method->Arity = presentMethod->Arity;
			Compile(xClass, method, mInfo.m_Parameters, mInfo.m_Body);
			DuplicateFunction(method, presentMethod);
		}
	}

	void Vm::AddField(x_class xClass, const std::string& name)
	{
		xClass->MemberIndices.emplace(name, xClass->MemberIndices.size());
	}

	x_ulong Vm::FindField(x_class xClass, const std::string& name)
	{
		auto iter = xClass->MemberIndices.find(name);
		if (iter == xClass->MemberIndices.end())
			return -1;
		else
			return iter->second;
	}

	void Vm::AddMethod(x_class xClass, x_method method)
	{
		xClass->FunctionIndices.emplace(method->Signature->Chars, xClass->Functions.size());
		xClass->Functions.emplace_back(method);
	}

	void Vm::AddImplicitCast(x_class xClass, x_method method)
	{
		xClass->FunctionIndices.emplace(method->Signature->Chars, xClass->Functions.size());
		xClass->ImplicitCastIndices.emplace(method->Signature->Chars, xClass->Functions.size());
		xClass->Functions.emplace_back(method);
	}

	bool Vm::Compile(x_class xClass, x_method method, const std::vector<ParameterInfo>& parameters, Statement& block)
	{
		std::vector<CompilationMessage> messages = m_Compiler.Compile(xClass, method, parameters, block);
		bool success = LogMessages(messages);
		if (!success)
			MarkClassForRemoval(xClass);
		return success;
	}

	void Vm::GenerateClassInfo(const CompilationUnit& unit)
	{
		for (const auto& nspace : unit.m_GlobalNamespace->m_Namespaces)
		{
			AddNamespace(m_GlobalNamespace, *nspace.second);
		}

		for (const auto& cInfo : unit.m_Classes)
		{
			size_t length = cInfo.m_QualifiedName.find_last_of('.');
			std::string qualifiers = cInfo.m_QualifiedName.substr(0, length == std::string::npos ? 0 : length);
			std::shared_ptr<InfoHierarchyMember> newClass = AddInfo(FindInfo(qualifiers, m_CurrentCompilationUnit),
				std::make_shared<std::string>(cInfo.m_Name), InfoHierarchyMember::Class);
			for (auto& member : cInfo.m_Fields)
			{
				std::shared_ptr<InfoHierarchyMember> xMember = AddInfo(newClass,
					std::make_shared<std::string>(member.m_Name), InfoHierarchyMember::Field);
				xMember->m_Modifiers = std::make_unique<Modifiers>(member.m_Modifiers);
				xMember->m_Location = member.m_Location;
			}
			for (auto& member : cInfo.m_Properties)
			{
				std::shared_ptr<InfoHierarchyMember> xMember = AddInfo(newClass,
					std::make_shared<std::string>(member.m_Name), InfoHierarchyMember::Property);
				xMember->m_Modifiers = std::make_unique<Modifiers>(member.m_Modifiers);
				xMember->m_Location = member.m_Location;
			}
			for (auto& member : cInfo.m_Methods)
			{
				std::shared_ptr<InfoHierarchyMember> xMember = AddInfo(newClass,
					std::make_shared<std::string>(member.m_Signature), InfoHierarchyMember::Method);
				xMember->m_Modifiers = std::make_unique<Modifiers>(member.m_Modifiers);
				xMember->m_Location = member.m_Location;
			}
			for (auto& member : cInfo.m_Casts)
			{
				std::shared_ptr<InfoHierarchyMember> xMember = AddInfo(newClass,
					std::make_shared<std::string>(member.m_Signature), InfoHierarchyMember::ImplicitConversion);
				xMember->m_Modifiers = std::make_unique<Modifiers>(member.m_Modifiers);
				xMember->m_Location = member.m_Location;
			}
			for (auto& member : cInfo.m_Constructors)
			{
				std::shared_ptr<InfoHierarchyMember> xMember = AddInfo(newClass,
					std::make_shared<std::string>(member.m_Signature), InfoHierarchyMember::Constructor);
				xMember->m_Modifiers = std::make_unique<Modifiers>(member.m_Modifiers);
				xMember->m_Location = member.m_Location;
			}
			if (cInfo.m_Constructors.empty())
			{
				std::shared_ptr<InfoHierarchyMember> xMember = AddInfo(newClass,
					std::make_shared<std::string>(";<>;"), InfoHierarchyMember::Constructor);
				xMember->m_Modifiers = std::make_unique<Modifiers>();
				xMember->m_Modifiers->m_Access = AccessModifier::Public;
				xMember->m_Location = cInfo.m_Location;
			}
		}

		for (auto& xClass : unit.m_Classes)
		{
			ClassCompilationInfo cInfo;
			for (auto& member : xClass.m_Fields)
			{
				Member xMember;
				xMember.m_ContainingClass = xClass.m_QualifiedName;
				xMember.m_Modifiers = member.m_Modifiers;
				xMember.m_Type = Member::Category::Field;
				xMember.m_Data = member.m_Type;
				cInfo.m_Members.emplace(member.m_Name, xMember);
			}
			for (auto& member : xClass.m_Properties)
			{
				Member xMember;
				xMember.m_ContainingClass = xClass.m_QualifiedName;
				xMember.m_Modifiers = member.m_Modifiers;
				xMember.m_Type = Member::Category::Property;
				xMember.m_Data = member.m_Type;
				cInfo.m_Members.emplace(member.m_Name, xMember);
			}
			for (auto& member : xClass.m_Methods)
			{
				Member xMember;
				xMember.m_ContainingClass = xClass.m_QualifiedName;
				xMember.m_Modifiers = member.m_Modifiers;
				xMember.m_Type = Member::Category::Method;
				xMember.m_Data = member.m_Type;
				cInfo.m_Members.emplace(member.m_Name, xMember);
			}
			for (auto& member : xClass.m_Casts)
			{
				Member xMember;
				xMember.m_ContainingClass = xClass.m_QualifiedName;
				xMember.m_Modifiers = member.m_Modifiers;
				xMember.m_Type = Member::Category::Method;
				std::string name = GetMethodName(member.m_Signature);
				cInfo.m_Members.emplace(name, xMember);
			}
			for (auto& member : xClass.m_Constructors)
			{
				Member xMember;
				xMember.m_ContainingClass = xClass.m_QualifiedName;
				xMember.m_Modifiers = member.m_Modifiers;
				xMember.m_Type = Member::Category::Constructor;
				std::string name = GetMethodName(member.m_Signature);
				cInfo.m_Members.emplace(name, xMember);
			}
			m_ClassInfo.emplace(xClass.m_QualifiedName, cInfo);
		}
	}

	void Vm::AddNamespace(std::shared_ptr<InfoHierarchyMember> parent, const NamespaceInfo& info)
	{
		std::shared_ptr<InfoHierarchyMember> newInfo = AddInfo(parent,
			std::make_shared<std::string>(info.m_Name), InfoHierarchyMember::Namespace);
		for (const auto& nspace : info.m_Namespaces)
		{
			AddNamespace(newInfo, *nspace.second);
		}
	}

	std::shared_ptr<InfoHierarchyMember> Vm::AddInfo(std::shared_ptr<InfoHierarchyMember> parent,
		std::shared_ptr<std::string> name, InfoHierarchyMember::Category category)
	{
		std::shared_ptr<InfoHierarchyMember> info = std::make_shared<InfoHierarchyMember>();
		info->m_Parent = parent;
		info->m_Name = name;
		info->m_Class = nullptr;
		info->m_Modifiers = nullptr;
		info->m_CompilationUnitID = m_CurrentCompilationUnit;
		info->m_Category = category;
		if (parent)
			parent->m_Children.emplace(std::string_view(*info->m_Name), info);
		return info;
	}

	std::shared_ptr<InfoHierarchyMember> Vm::FindInfoImpl(std::shared_ptr<InfoHierarchyMember> parent, std::vector<std::string_view> names, size_t compilationUnitID)
	{
		if (compilationUnitID == -1) compilationUnitID = m_CurrentCompilationUnit;
		if (names.empty()) return parent;
		std::shared_ptr<InfoHierarchyMember> info = parent;
		for (auto name : names)
		{
			info = FindMemberInfo(info, name, compilationUnitID);
			if (info->m_Category == InfoHierarchyMember::NotFound)
				return info;
		}
		return info;
	}

	std::shared_ptr<std::string> Vm::QualifySignature(std::shared_ptr<InfoHierarchyMember> owner, const std::string& signature, size_t compilationUnitID)
	{
		if (compilationUnitID == -1) compilationUnitID = m_CurrentCompilationUnit;
		std::shared_ptr<std::string> qualified = std::make_unique<std::string>();
		std::vector<std::string_view> tokens = SplitViewSignature(signature);
		std::vector<std::shared_ptr<InfoHierarchyMember>> infos;
		for (int i = 0; i < tokens.size(); i++)
		{
			if (i != 1)
			{
				if (i == 0 && tokens[0].empty())
					infos.push_back(AddInfo(nullptr, nullptr, InfoHierarchyMember::NotFound));
				else
					infos.push_back(FindAccessibleMemberInfo(owner, tokens[i], compilationUnitID));
			}
		}
		int index = 0;
		for (int i = 0; i < infos.size() + 1; i++)
		{
			if (i == 1)
			{
				*qualified += tokens[1];
				*qualified += ';';
			}
			else
			{
				size_t newSize = qualified->size();
				std::vector<std::string_view> names;
				if (infos[index]->m_Category != InfoHierarchyMember::NotFound)
					names = QualifyInfo(infos[index]);
				else
				{
					if (i == 0 && tokens[0].empty())
						names.push_back("");
					else
						names.push_back("<unknown_type>");
				}
				for (std::string_view name : names)
					newSize += name.size() + 1;
				qualified->reserve(newSize);
				for (std::string_view name : names)
				{
					*qualified += name;
					*qualified += '.';
				}
				qualified->back() = ';';
				index++;
			}
		}
		return qualified;
	}

	//void Vm::CompileField(x_ulong fieldID, const FieldInfo& fieldInfo, x_method method)
	//{
	//	if (fieldInfo.m_VariableInitializer.m_Children.size() > 0)
	//		CompileExpression(fieldInfo.m_VariableInitializer, method);
	//	else
	//		method->Code.Code.emplace_back(Instruction::literal_nullptr);

	//	method->Code.Code.emplace_back(Instruction::set_field);
	//	method->Code.Code.emplace_back(fieldID);
	//}

	//x_method Vm::CompileStatement(const Statement& statement)
	//{
	//	FunctionObject* method = NewFunction();
	//	CompileStatement(statement, method);
	//	return method;
	//}

	//void Vm::CompileStatement(const Statement& statement, x_method method)
	//{
	//	//Compiler::Compile(this, statement, method);
	//}

	//XType Vm::CompileExpression(const Expression& expression, x_method method)
	//{
	//	//Compiler::Compile(this, expression, method);
	//	return XType::Instance; // ???
	//}

	StringObject* Vm::FindInternedString(const char* chars, x_ulong length)
	{
		for (StringObject* string : m_InternedStrings)
		{
			if (length == string->Size &&
				std::memcmp(chars, string->Chars, length) == 0)
			{
				return string;
			}
		}
		return nullptr;
	}

	void Vm::MarkRoots()
	{
		for (int i = 0; i < sp - m_Stack.data(); i++)
		{
			if (m_Stack[i].Type == ValueType::Object)
				MarkObject(m_Stack[i].as.Object);
		}

		for (auto const& [key, val] : m_GlobalNames)
		{
			if (m_Globals[val].Type == ValueType::Object)
				MarkObject(m_Globals[val].as.Object);
		}

		for (x_class xClass : m_Classes)
		{
			for (FunctionObject* function : xClass->Functions)
			{
				MarkObject((x_object*)function);
			}
		}

		for (x_object* object : m_PinnedObjects)
		{
			MarkObject(object);
		}
	}

	void Vm::TraceReferences()
	{
		for (int i = 0; i < m_GrayStack.size(); i++)
		{
			BlackenObject(m_GrayStack[i]);
		}
		m_GrayStack.clear();
	}

	void Vm::RemoveInterned()
	{
		for (auto iter = m_InternedStrings.begin(); iter != m_InternedStrings.end();)
		{
			if (!(*iter)->Object.IsMarked)
			{
				iter = m_InternedStrings.erase(iter);
			}
			else
			{
				iter++;
			}
		}
	}

	void Vm::Sweep()
	{
		x_object* previous = nullptr;
		x_object* object = m_Objects;
		while (object != nullptr)
		{
			if (object->IsMarked)
			{
				object->IsMarked = false;
				previous = object;
				object = object->Next;
			}
			else
			{
				x_object* unreached = object;
				object = object->Next;
				if (previous != nullptr)
					previous->Next = object;
				else
					m_Objects = object;

				FreeObject(unreached);
			}
		}
	}

	void Vm::BlackenObject(x_object* object)
	{
		switch (object->Type)
		{
			case ObjectType::native_function_object: break;
			case ObjectType::void_native_function_object: break;
			case ObjectType::instance_object:
			{
				InstanceObject* instance = (InstanceObject*)object;
				for (const Value& value : instance->Members)
				{
					if (value.Type == ValueType::Object)
						MarkObject(value.as.Object);
				}
				break;
			}
			case ObjectType::function_object:
			{
				FunctionObject* function = (FunctionObject*)object;
				MarkObject((x_object*)function->Signature);
				for (Value value : function->Code.Constants)
				{
					if (value.Type == ValueType::Object)
						MarkObject(value.as.Object);
				}

				break;
			}
			case ObjectType::string_object: break;
			default:
			{
				Error("Blackenobject: Unknown object type!");
			}
		}
#ifdef DEBUG_LOG_GC
		printf("%p blacken ", (void*)object);
		printf("\n");
#endif
	}

	void Vm::MarkObject(x_object* object)
	{
		if (object == nullptr) return;
		if (object->IsMarked) return;
		object->IsMarked = true;

		m_GrayStack.emplace_back(object);
#ifdef DEBUG_LOG_GC
		printf("%p mark ", (void*)object);
		// TODO: A function that prints any object type
		printf("\n");
#endif
	}

	x_object* Vm::FindPinnedObject(x_object* object)
	{
		x_object* value;
		auto iter = std::find(m_PinnedObjects.rbegin(), m_PinnedObjects.rend(), object);
		if (iter != m_PinnedObjects.rend())
			value = *iter;
		else
			value = nullptr;
		return value;
	}

	Vm::ScopedPin Vm::PinObject(x_object* object)
	{
		ForcePinObject(object);
		return ScopedPin(this, object);
	}

	void Vm::ForcePinObject(x_object* object)
	{
		m_PinnedObjects.emplace_back(object);
	}

	void Vm::UnPinObject(x_object* object)
	{
		std::remove(m_PinnedObjects.rbegin(), m_PinnedObjects.rend(), object);
	}

	template<typename T>
	inline T* Vm::Alloc()
	{
#ifdef DEBUG_STRESS_GC
		CollectGarbage();
#else
		if (m_BytesAllocated + sizeof(T) > m_NextGC) { CollectGarbage(); }
#endif
		m_BytesAllocated += sizeof(T);
		return new T();
	}

	template<typename T>
	inline T* Vm::AllocArray(x_ulong count)
	{
		m_BytesAllocated += sizeof(T) * count;
#ifdef DEBUG_STRESS_GC
		CollectGarbage();
#else
		if (m_BytesAllocated > m_NextGC) { CollectGarbage(); }
#endif
		return new T[count]();
	}

	template<typename T>
	void Vm::Dealloc(T* ptr)
	{
		m_BytesAllocated -= sizeof(T);
		delete ptr;
	}

	template<typename T>
	void Vm::DeallocArray(T* ptr, x_ulong size)
	{
		m_BytesAllocated -= sizeof(T) * size;
		delete[] ptr;
	}

	template<typename T>
	T* Vm::AllocObject(ObjectType type)
	{
		T* obj = Alloc<T>();
		obj->Object.Type = type;
		obj->Object.IsMarked = false;

		obj->Object.Next = m_Objects;
		m_Objects = &obj->Object;
		return obj;
	}

	StringObject* Vm::AllocateString(char* chars, x_ulong length)
	{
		StringObject* string = ALLOCATE_OBJ(StringObject, ObjectType::string_object);
		string->Size = length;
		string->Chars = chars;
		m_InternedStrings.emplace(string);
		return string;
	}

	FunctionObject* Vm::NewFunction()
	{
		FunctionObject* function = ALLOCATE_OBJ(FunctionObject, ObjectType::function_object);
		function->Arity = 0;
		function->RequiredStackSize = 0;
		// function->Code is default initalized
		function->LocalCount = 0;
		function->Signature = nullptr;
		return function;
	}

	void Vm::DuplicateFunction(x_method oldFunction, x_method newFunction)
	{
		newFunction->Arity = oldFunction->Arity;
		newFunction->RequiredStackSize = oldFunction->RequiredStackSize;
		newFunction->Code = oldFunction->Code;
		newFunction->LocalCount = oldFunction->LocalCount;
		newFunction->Signature = oldFunction->Signature;
	}

	FunctionObject* Vm::DuplicateFunction(x_method oldFunction)
	{
		FunctionObject* function = NewFunction();
		DuplicateFunction(oldFunction, function);
		return function;
	}

	NativeObject* Vm::NewNative(NativeFn function)
	{
		NativeObject* native = ALLOCATE_OBJ(NativeObject, ObjectType::native_function_object);
		native->Function = function;
		return native;
	}

	VoidNativeObject* Vm::NewVoidNative(VoidNativeFn function)
	{
		VoidNativeObject* native = ALLOCATE_OBJ(VoidNativeObject, ObjectType::void_native_function_object);
		native->Function = function;
		return native;
	}

	x_class Vm::AddClass(const std::string& name)
	{
		x_class xClass = new _x_class();
		m_ClassNames.emplace(name, m_Classes.size());
		xClass = m_Classes.emplace_back(xClass);
		xClass->Name = name;
		return xClass;
	}

	void Vm::MarkClassForRemoval(x_class xClass)
	{
		if (xClass == nullptr) return;
		for (x_class c : m_ClassesToRemove)
			if (c == xClass) return;
		m_ClassesToRemove.push_back(xClass);
	}

	bool Vm::RemoveClasses()
	{
		if (m_ClassesToRemove.empty())
			return false;
		for (x_class xClass : m_ClassesToRemove)
			RemoveClass(xClass);
		m_ClassesToRemove.clear();
		return true;
	}

	void Vm::RemoveClass(x_class xClass)
	{
		if (!xClass)
		{
			Error("RemoveClass: nullptr given as parameter");
			return;
		}
		auto iter = m_ClassNames.find(xClass->Name);
		if (iter == m_ClassNames.end())
		{
			Error("RemoveClass: Parameter is an orphaned class");
			return;
		}
		x_ulong classID = iter->second;
		x_class foundClass = m_Classes[classID];
		if (xClass != foundClass)
		{
			Error("RemoveClass: Attempting to remove \"" + xClass->Name + "\", an ambigious class!");
			return;
		}
		xClass->Info->m_Class = nullptr;

		m_ClassNames.erase(iter);
		delete xClass;
		m_Classes.erase(m_Classes.begin() + classID);
		for (auto& [name, id] : m_ClassNames)
			if (id > classID)
				id--;
	}

	void Vm::CallFunction(FunctionObject* function)
	{
		m_StackSize += function->RequiredStackSize;
		size_t stackCapacity = m_Stack.capacity();
		if (m_StackSize > stackCapacity)
		{
			Value* oldStack = m_Stack.data();

			size_t stackMax = m_Stack.max_size();
			if (stackCapacity > stackMax / 2)
			{
				// Growth would overflow
				m_Stack.reserve(m_Stack.max_size());
#ifdef DEBUG_LOG_GC
				printf("reached max stack size\n");
#endif
			}
			else if (stackCapacity * 2 < m_StackSize)
			{
				// Find the next highest power of two
				// From The Aggregate Magic Algorithms
				// http://aggregate.org/MAGIC/
				size_t size = m_StackSize;
				size |= (size >> 1);
				size |= (size >> 2);
				size |= (size >> 4);
				size |= (size >> 8);
				size |= (size >> 16);
				size |= (size >> 32);
				m_Stack.reserve(size + 1);
#ifdef DEBUG_LOG_GC
				printf("resized stack from %zu to %zu\n", stackCapacity, size + 1);
#endif
			}
			else
			{
				m_Stack.reserve(stackCapacity * 2);
#ifdef DEBUG_LOG_GC
				printf("doubled stack from %zu to %zu\n", stackCapacity, stackCapacity * 2);
#endif
			}

			sp = m_Stack.data() + (sp - oldStack);
			for (int i = 0; i < m_FrameCount; i++)
			{
				CallFrame* frame = &m_Frames[i];
				frame->fp = m_Stack.data() + (frame->fp - oldStack);
			}
		}
		CallFrame* newFrame = &m_Frames[m_FrameCount++];
		newFrame->Function = function;
		newFrame->ip = function->Code.Code.data();
		newFrame->fp = sp - function->Arity - 1;
		newFrame->Locals.reserve(function->LocalCount);
	}

	void Vm::push(Value value)
	{
		*sp++ = value;
	}

	Value Vm::RunMethod(x_method method)
	{
		push(OBJ_VAL(method));
		CallFunction(method);
		return Run();
	}

	Value Vm::Run()
	{
		CallFrame* frame = &m_Frames[m_FrameCount - 1];

		//sp = &m_Stack[1];
		OpType* ie = &(*frame->Function->Code.Code.begin()) + frame->Function->Code.Code.size();
		if (frame->ip == ie)
			return 0;

		while (frame->ip != ie)
		{
#ifdef X_DEBUG
			if (frame->ip >= ie)
			{
				Error("Overpassed function end!");
			}
#endif
			switch (frame->ip->Op)
			{
				// Arithmetic
				case Instruction::double_negate: { UNARY_OPERAND(Double) = -UNARY_OPERAND(Double); break; }
				case Instruction::double_inc: { UNARY_OPERAND(Double)++; break; }
				case Instruction::double_dec: { UNARY_OPERAND(Double)--; break; }
				case Instruction::double_add: { LEFT_OPERAND(Double) += RIGHT_OPERAND(Double); DEC(); break; }
				case Instruction::double_sub: { LEFT_OPERAND(Double) -= RIGHT_OPERAND(Double); DEC(); break; }
				case Instruction::double_mul: { LEFT_OPERAND(Double) *= RIGHT_OPERAND(Double); DEC(); break; }
				case Instruction::double_div: { LEFT_OPERAND(Double) /= RIGHT_OPERAND(Double); DEC(); break; }
				case Instruction::double_mod:
				{
					LEFT_OPERAND(Double) = (x_double)std::fmod(LEFT_OPERAND(Double), RIGHT_OPERAND(Double));
					DEC();
					break;
				}
				case Instruction::double_pow:
				{
					LEFT_OPERAND(Double) = (x_double)std::pow(LEFT_OPERAND(Double), RIGHT_OPERAND(Double));
					DEC();
					break;
				}
				case Instruction::float_negate: { UNARY_OPERAND(Float) = -UNARY_OPERAND(Float); break; }
				case Instruction::float_inc: { UNARY_OPERAND(Float)++; break; }
				case Instruction::float_dec: { UNARY_OPERAND(Float)--; break; }
				case Instruction::float_add: { LEFT_OPERAND(Float) += RIGHT_OPERAND(Float); DEC(); break; }
				case Instruction::float_sub: { LEFT_OPERAND(Float) -= RIGHT_OPERAND(Float); DEC(); break; }
				case Instruction::float_mul: { LEFT_OPERAND(Float) *= RIGHT_OPERAND(Float); DEC(); break; }
				case Instruction::float_div: { LEFT_OPERAND(Float) /= RIGHT_OPERAND(Float); DEC(); break; }
				case Instruction::float_mod:
				{
					LEFT_OPERAND(Float) = (x_float)std::fmod(LEFT_OPERAND(Float), RIGHT_OPERAND(Float));
					DEC();
					break;
				}
				case Instruction::float_pow:
				{
					LEFT_OPERAND(Float) = (x_float)std::pow(LEFT_OPERAND(Float), RIGHT_OPERAND(Float));
					DEC();
					break;
				}
				case Instruction::int_negate: { UNARY_OPERAND(Int) = -UNARY_OPERAND(Int); break; }
				case Instruction::int_inc: { UNARY_OPERAND(Int)++; break; }
				case Instruction::int_dec: { UNARY_OPERAND(Int)--; break; }
				case Instruction::int_add: { LEFT_OPERAND(Int) += RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_sub: { LEFT_OPERAND(Int) -= RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_mul: { LEFT_OPERAND(Int) *= RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_div: { LEFT_OPERAND(Int) /= RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_mod: { LEFT_OPERAND(Int) %= RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_pow:
				{
					LEFT_OPERAND(Int) = (x_long)std::pow(LEFT_OPERAND(Int), RIGHT_OPERAND(Int));
					DEC();
					break;
				}
				case Instruction::int_shift_left: { LEFT_OPERAND(Int) = LEFT_OPERAND(Int) << RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_shift_right: { LEFT_OPERAND(Int) = LEFT_OPERAND(Int) >> RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_bit_and: { LEFT_OPERAND(Int) = LEFT_OPERAND(Int) & RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_bit_or: { LEFT_OPERAND(Int) = LEFT_OPERAND(Int) | RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::int_bit_xor: { LEFT_OPERAND(Int) = LEFT_OPERAND(Int) ^ RIGHT_OPERAND(Int); DEC(); break; }
				case Instruction::uint_inc: { UNARY_OPERAND(UInt)++; break; }
				case Instruction::uint_dec: { UNARY_OPERAND(UInt)--; break; }
				case Instruction::uint_add: { LEFT_OPERAND(UInt) += RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_sub: { LEFT_OPERAND(UInt) -= RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_mul: { LEFT_OPERAND(UInt) *= RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_div: { LEFT_OPERAND(UInt) /= RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_mod: { LEFT_OPERAND(UInt) %= RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_pow:
				{
					LEFT_OPERAND(UInt) = (x_ulong)std::pow(LEFT_OPERAND(UInt), RIGHT_OPERAND(UInt));
					DEC();
					break;
				}
				case Instruction::uint_shift_left: { LEFT_OPERAND(UInt) = LEFT_OPERAND(UInt) << RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_shift_right: { LEFT_OPERAND(UInt) = LEFT_OPERAND(UInt) >> RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_bit_and: { LEFT_OPERAND(UInt) = LEFT_OPERAND(UInt) & RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_bit_or: { LEFT_OPERAND(UInt) = LEFT_OPERAND(UInt) | RIGHT_OPERAND(UInt); DEC(); break; }
				case Instruction::uint_bit_xor: { LEFT_OPERAND(UInt) = LEFT_OPERAND(UInt) ^ RIGHT_OPERAND(UInt); DEC(); break; }

				case Instruction::bool_negate: { UNARY_OPERAND(Bool) = !UNARY_OPERAND(Bool); break; }
				case Instruction::bool_and: { LEFT_OPERAND(Bool) = LEFT_OPERAND(Bool) & RIGHT_OPERAND(Bool); break; }
				case Instruction::bool_or: { LEFT_OPERAND(Bool) = LEFT_OPERAND(Bool) | RIGHT_OPERAND(Bool); break; }
				case Instruction::bool_xor: { LEFT_OPERAND(Bool) = LEFT_OPERAND(Bool) ^ RIGHT_OPERAND(Bool); break; }

				// String operations
				case Instruction::string_add:
				{
					StringObject* left = ((StringObject*)LEFT_OPERAND(Object));
					StringObject* right = ((StringObject*)RIGHT_OPERAND(Object));
					x_ulong length = left->Size + right->Size;
					char* chars = AllocArray<char>(length + 1);
					std::memcpy(chars, left->Chars, left->Size);
					std::memcpy(chars + left->Size, right->Chars, right->Size);
					chars[length] = '\0';
					LEFT_OPERAND(Object) = (x_object*)TakeString(chars, length);
					DEC();
					break;
				}
				case Instruction::string_size:
				{
					StringObject* string = ((StringObject*)UNARY_OPERAND(Object));
					UNARY_OPERAND(UInt) = string->Size;
					(sp - 1)->Type = ValueType::UInt;
					break;
				}

				// Casting
#ifdef COMPLETE_TYPING
				case Instruction::double_from_int: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(Int); (sp - 1)->Type = ValueType::Double; break; }
				case Instruction::double_from_uint: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(UInt); (sp - 1)->Type = ValueType::Double; break; }
				case Instruction::double_from_float: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(Float); (sp - 1)->Type = ValueType::Double; break; }
				case Instruction::float_from_int: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(Int); (sp - 1)->Type = ValueType::Float; break; }
				case Instruction::float_from_uint: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(UInt); (sp - 1)->Type = ValueType::Float; break; }
				case Instruction::float_from_double: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(Double); (sp - 1)->Type = ValueType::Float; break; }
				case Instruction::int_from_uint: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(UInt); (sp - 1)->Type = ValueType::Int; break; }
				case Instruction::int_from_double: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(Double); (sp - 1)->Type = ValueType::Int; break; }
				case Instruction::int_from_float: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(Float); (sp - 1)->Type = ValueType::Int; break; }
				case Instruction::uint_from_int: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Int); (sp - 1)->Type = ValueType::UInt; break; }
				case Instruction::uint_from_double: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Double); (sp - 1)->Type = ValueType::UInt; break; }
				case Instruction::uint_from_float: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Float); (sp - 1)->Type = ValueType::UInt; break; }
#else
				case Instruction::double_from_int: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(Int); break; }
				case Instruction::double_from_uint: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(UInt); break; }
				case Instruction::double_from_float: { UNARY_OPERAND(Double) = (x_double)UNARY_OPERAND(Float); break; }
				case Instruction::float_from_int: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(Int); break; }
				case Instruction::float_from_uint: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(UInt); break; }
				case Instruction::float_from_double: { UNARY_OPERAND(Float) = (x_float)UNARY_OPERAND(Double); break; }
				case Instruction::int_from_uint: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(UInt); break; }
				case Instruction::int_from_double: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(Double); break; }
				case Instruction::int_from_float: { UNARY_OPERAND(Int) = (x_long)UNARY_OPERAND(Float); break; }
				case Instruction::uint_from_int: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Int); break; }
				case Instruction::uint_from_double: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Double); break; }
				case Instruction::uint_from_float: { UNARY_OPERAND(UInt) = (x_ulong)UNARY_OPERAND(Float); break; }
#endif
				// Trueness testing
#ifdef COMPLETE_TYPING
				case Instruction::bool_from_double: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Double) == true; (sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::bool_from_float: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Float) == true; (sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::bool_from_int: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Int) == true; (sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::bool_from_uint: { UNARY_OPERAND(Bool) = UNARY_OPERAND(UInt) == true; (sp - 1)->Type = ValueType::Bool; break; }
#else
				case Instruction::bool_from_double: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Double) == true; break; }
				case Instruction::bool_from_float: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Float) == true; break; }
				case Instruction::bool_from_int: { UNARY_OPERAND(Bool) = UNARY_OPERAND(Int) == true; break; }
				case Instruction::bool_from_uint: { UNARY_OPERAND(Bool) = UNARY_OPERAND(UInt) == true; break; }
#endif
				case Instruction::bool_from_string:
				{
					StringObject* string = (StringObject*)UNARY_OPERAND(Object);
					UNARY_OPERAND(Bool) = string->Size > 0;
					(sp - 1)->Type = ValueType::Bool;
					break;
				}

				// Comparisons
#ifdef COMPLETE_TYPING
				case Instruction::double_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) == RIGHT_OPERAND(Double)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::double_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) != RIGHT_OPERAND(Double)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::double_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) > RIGHT_OPERAND(Double)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::double_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) < RIGHT_OPERAND(Double)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::double_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) >= RIGHT_OPERAND(Double)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::double_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) <= RIGHT_OPERAND(Double)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::float_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) == RIGHT_OPERAND(Float)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::float_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) != RIGHT_OPERAND(Float)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::float_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) > RIGHT_OPERAND(Float)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::float_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) < RIGHT_OPERAND(Float)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::float_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) >= RIGHT_OPERAND(Float)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::float_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) <= RIGHT_OPERAND(Float)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::int_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) == RIGHT_OPERAND(Int)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::int_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) != RIGHT_OPERAND(Int)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::int_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) > RIGHT_OPERAND(Int)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::int_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) < RIGHT_OPERAND(Int)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::int_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) >= RIGHT_OPERAND(Int)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::int_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) <= RIGHT_OPERAND(Int)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::uint_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) == RIGHT_OPERAND(UInt)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::uint_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) != RIGHT_OPERAND(UInt)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::uint_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) > RIGHT_OPERAND(UInt)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::uint_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) < RIGHT_OPERAND(UInt)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::uint_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) >= RIGHT_OPERAND(UInt)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
				case Instruction::uint_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) <= RIGHT_OPERAND(UInt)); DEC();
					(sp - 1)->Type = ValueType::Bool; break; }
#else
				case Instruction::double_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) == RIGHT_OPERAND(Double)); DEC(); break; }
				case Instruction::double_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) != RIGHT_OPERAND(Double)); DEC(); break; }
				case Instruction::double_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) > RIGHT_OPERAND(Double)); DEC(); break; }
				case Instruction::double_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) < RIGHT_OPERAND(Double)); DEC(); break; }
				case Instruction::double_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) >= RIGHT_OPERAND(Double)); DEC(); break; }
				case Instruction::double_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Double) <= RIGHT_OPERAND(Double)); DEC(); break; }
				case Instruction::float_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) == RIGHT_OPERAND(Float)); DEC(); break; }
				case Instruction::float_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) != RIGHT_OPERAND(Float)); DEC(); break; }
				case Instruction::float_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) > RIGHT_OPERAND(Float)); DEC(); break; }
				case Instruction::float_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) < RIGHT_OPERAND(Float)); DEC(); break; }
				case Instruction::float_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) >= RIGHT_OPERAND(Float)); DEC(); break; }
				case Instruction::float_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Float) <= RIGHT_OPERAND(Float)); DEC(); break; }
				case Instruction::int_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) == RIGHT_OPERAND(Int)); DEC(); break; }
				case Instruction::int_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) != RIGHT_OPERAND(Int)); DEC(); break; }
				case Instruction::int_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) > RIGHT_OPERAND(Int)); DEC(); break; }
				case Instruction::int_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) < RIGHT_OPERAND(Int)); DEC(); break; }
				case Instruction::int_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) >= RIGHT_OPERAND(Int)); DEC(); break; }
				case Instruction::int_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Int) <= RIGHT_OPERAND(Int)); DEC(); break; }
				case Instruction::uint_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) == RIGHT_OPERAND(UInt)); DEC(); break; }
				case Instruction::uint_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) != RIGHT_OPERAND(UInt)); DEC(); break; }
				case Instruction::uint_greater: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) > RIGHT_OPERAND(UInt)); DEC(); break; }
				case Instruction::uint_less: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) < RIGHT_OPERAND(UInt)); DEC(); break; }
				case Instruction::uint_greater_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) >= RIGHT_OPERAND(UInt)); DEC(); break; }
				case Instruction::uint_less_or_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(UInt) <= RIGHT_OPERAND(UInt)); DEC(); break; }
#endif
				case Instruction::bool_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Bool) == RIGHT_OPERAND(Bool)); DEC(); break; }
				case Instruction::bool_not_equal: { LEFT_OPERAND(Bool) = (LEFT_OPERAND(Bool) != RIGHT_OPERAND(Bool)); DEC(); break; }

				case Instruction::string_equal:
				{
					StringObject* left = ((StringObject*)LEFT_OPERAND(Object));
					StringObject* right = ((StringObject*)RIGHT_OPERAND(Object));
					LEFT_OPERAND(Bool) = left == right;
					DEC();
					(sp - 1)->Type = ValueType::Bool;
					break;
				}
				case Instruction::string_not_equal:
				{
					StringObject* left = ((StringObject*)LEFT_OPERAND(Object));
					StringObject* right = ((StringObject*)RIGHT_OPERAND(Object));
					LEFT_OPERAND(Bool) = left != right;
					DEC();
					(sp - 1)->Type = ValueType::Bool;
					break;
				}

				case Instruction::bit_flip: { UNARY_OPERAND(UInt) = ~UNARY_OPERAND(UInt); break; }

				// Control flow
				case Instruction::jump_if_true:
				{
					_x_short offset = READ_SHORT();
					if (UNARY_OPERAND(Bool) == true)
						frame->ip += offset;
					DEC();
					break;
				}
				case Instruction::jump_if_true_chain:
				{
					_x_short offset = READ_SHORT();
					if (UNARY_OPERAND(Bool) == true)
						frame->ip += offset;
					break;
					// NOTE: Doesn't decrement the stack pointer
				}
				case Instruction::jump_if_false:
				{
					_x_short offset = READ_SHORT();
					if (UNARY_OPERAND(Bool) == false)
						frame->ip += offset;
					DEC();
					break;
				}
				case Instruction::jump_if_false_chain:
				{
					_x_short offset = READ_SHORT();
					if (UNARY_OPERAND(Bool) == false)
						frame->ip += offset;
					break;
					// NOTE: Doesn't decrement the stack pointer
				}
				case Instruction::jump:
				{
					_x_short offset = READ_SHORT();
					frame->ip += offset;
					break;
				}
				case Instruction::loop:
				{
					_x_short offset = READ_SHORT();
					frame->ip -= offset;
					break;
				}

				// Functions
				case Instruction::func_call:
				{
					_x_short argCount = READ_SHORT();
					Value* callable = (sp - (argCount + 1));
					switch (OBJ_TYPE(callable))
					{
						case ObjectType::function_object:
						{
							CallFunction((FunctionObject*)(AS_OBJ(callable)));
							frame = &m_Frames[m_FrameCount - 1];
							break;
						}
						case ObjectType::native_function_object:
						{
							NativeObject* native = (NativeObject*)(AS_OBJ(callable));
							sp -= argCount + 1;
							push(native->Function(this, argCount, sp + 1));
							break;
						}
						case ObjectType::void_native_function_object:
						{
							VoidNativeObject* native = (VoidNativeObject*)(AS_OBJ(callable));
							native->Function(this, argCount, sp - argCount);
							sp -= argCount + 1;
							break;
						}
						default:
						{
							Error("Can not call supplied object.");
							break;
						}
					}
					break;
				}
				case Instruction::func_return:
				{
					Value result = POP();
					m_FrameCount--;
					sp = frame->fp;
					m_StackSize -= frame->Function->RequiredStackSize;
					if (m_FrameCount == 0)
					{
						return result;
					}

					push(result);
					frame = &m_Frames[m_FrameCount - 1];
					break;
				}
				case Instruction::func_return_void:
				{
					m_FrameCount--;
					sp = frame->fp;
					m_StackSize -= frame->Function->RequiredStackSize;
					if (m_FrameCount == 0)
					{
						return 0;
					}

					frame = &m_Frames[m_FrameCount - 1];
					break;
				}

				// Variables
				case Instruction::set_global:
				{
					_x_short address = READ_SHORT();
					m_Globals[address] = POP();
					break;
				}
				case Instruction::get_global:
				{
					_x_short address = READ_SHORT();
					push(m_Globals[address]);
					break;
				}
				case Instruction::set_local:
				{
					_x_short slot = READ_SHORT();
					frame->fp[slot] = POP();
					break;
				}
				case Instruction::get_local:
				{
					_x_short slot = READ_SHORT();
					push(frame->fp[slot]);
					break;
				}

				case Instruction::get_field:
				{
					InstanceObject* instance = (InstanceObject*)UNARY_OPERAND(Object);
					push(instance->Members[READ_SHORT()]);
					break;
				}
				case Instruction::set_field:
				{
					InstanceObject* instance = (InstanceObject*)LEFT_OPERAND(Object);
					instance->Members[READ_SHORT()] = POP();
					break;
				}
				case Instruction::get_member_field:
				{
					InstanceObject* instance = (InstanceObject*)AS_OBJ(frame->fp);
					push(instance->Members[READ_SHORT()]);
					break;
				}
				case Instruction::set_member_field:
				{
					InstanceObject* instance = (InstanceObject*)AS_OBJ(frame->fp);
					instance->Members[READ_SHORT()] = POP();
					break;
				}

				case Instruction::member_method_call:
				{
					_x_short argCount = READ_SHORT();
					_x_short functionID = READ_SHORT();
					InstanceObject* instance = (InstanceObject*)AS_OBJ((sp - (argCount + 1)));
					FunctionObject* function = (instance->Class->Functions[functionID]);
					CallFunction(function);
					frame = &m_Frames[m_FrameCount - 1];
					break;
				}
				case Instruction::static_method_call:
				{
					_x_short classID = READ_SHORT();
					_x_short argCount = READ_SHORT();
					_x_short functionID = READ_SHORT();
					x_class xClass = m_Classes[classID];
					CallFunction(xClass->Functions[functionID]);
					frame = &m_Frames[m_FrameCount - 1];
					break;
				}
				case Instruction::create_instance:
				{
					_x_short classID = READ_SHORT();
					push(Value{ NewInstance(m_Classes[classID]) });
					break;
				}

				// Stack Usage
				case Instruction::push_value: { push(READ_CONST()); break; }
				case Instruction::push_size:
				{
					x_ulong size = READ_CONSTANT(UInt);
					std::memcpy(sp, &READ_CONST(), size * sizeof(Value));
					sp += size;
					break;
				}
				case Instruction::pop_value: { DEC(); break; }
				case Instruction::pop_size:
				{
					x_ulong size = READ_CONSTANT(UInt);
					sp -= size;
					break;
				}

				case Instruction::duplicate:
				{
					push(*(sp - 1));
					break;
				}
				
				case Instruction::literal_true: push(Value{ true }); break;
				case Instruction::literal_false: push(Value{ false }); break;
				case Instruction::literal_nullptr: push(Value{ (x_object*)nullptr }); break;

				// Printing
				case Instruction::print_int: { std::cout << UNARY_OPERAND(Int) << std::endl; break; }
				case Instruction::print_uint: { std::cout << UNARY_OPERAND(UInt) << std::endl; break; }
				case Instruction::print_double: { std::cout << UNARY_OPERAND(Double) << std::endl; break; }
				case Instruction::print_float: { std::cout << UNARY_OPERAND(Float) << std::endl; break; }
				case Instruction::print_bool: { std::cout << UNARY_OPERAND(Bool) << std::endl; break; }
				case Instruction::print_string: { std::cout << ((StringObject*)UNARY_OPERAND(Object))->Chars << std::endl; break; }
				default: Error("Unknown instruction!"); break;
			}
			frame->ip++;
		}

		return Value(0);
	}

	Vm::ScopedPin::ScopedPin(Vm* xvm, x_object* object)
	{
		m_XVM = xvm;
		m_Object = object;
	}

	Vm::ScopedPin::~ScopedPin()
	{
		m_XVM->UnPinObject(m_Object);
	}
}

#undef LEFT_OPERAND
#undef RIGHT_OPERAND
#undef UNARY_OPERAND

#undef READ_CONSTANT
#undef READ_CONST
#undef READ_SHORT

#undef DEC
#undef POP

#undef ALLOCATE_OBJ
