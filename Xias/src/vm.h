#pragma once

#include "common.h"
#include "types.h"
#include "bytecode.h"
#include "instructions.h"
#include "object.h"
#include "compilation_unit.h"
#include "compiler.h"

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

namespace Xias {

	struct FunctionObject;

	struct CallFrame
	{
		FunctionObject* Function;
		OpType* ip;
		Value* fp;
		std::vector<Value> Locals;
	};

	class Vm
	{
		std::vector<CallFrame> m_Frames;
		int m_FrameCount;

		std::unordered_set<StringObject*> m_InternedStrings;

		std::unordered_map<std::string, x_ulong> m_GlobalNames;
		std::vector<Value> m_Globals;
		std::vector<Value> m_Stack;
		Value* sp = nullptr;
		Value* m_StackBack = nullptr;
		x_ulong m_StackSize;

		std::unordered_map<std::string, x_ulong> m_ClassNames;
		std::vector<x_class> m_Classes;
		std::unordered_map<std::string, ClassCompilationInfo> m_ClassInfo;

		std::vector<x_object*> m_GrayStack;
		x_object* m_Objects = nullptr;

		std::vector<x_object*> m_PinnedObjects;

		size_t m_BytesAllocated;
		size_t m_NextGC;

		std::vector<CompilationUnit> m_CompilationUnits;
		Compiler m_Compiler;
	public:
		Vm();
		~Vm();
		
		bool Compile(const std::string& filepath);
		bool Compile(CompilationUnit& compilationUnit);

		void RegisterFunction(const std::string&, NativeFn function);
		void RegisterVoidFunction(const std::string&, VoidNativeFn function);

		StringObject* TakeString(char* chars, x_ulong length);
		StringObject* CopyString(const char* chars, x_ulong length);
		StringObject* CopyString(const std::string& string);

		InstanceObject* NewInstance(x_class xClass);

		void AddGlobal(const std::string& name, Value& value);
		Value GetGlobal(const std::string& name);
		
		x_class GetClass(const std::string& name);
		//MemberInfo GetMemberInfo(const std::string& xClass, const std::string& name);
		Member GetMember(x_class xClass, const std::string& name);
		bool IsClassDescendent(const std::string& parent, const std::string& descendent);

		std::vector<std::string> SplitSignature(std::string signature);
		std::string GetMethodName(std::string signature);

		// Expects a signature without a return type.
		// Returns an empty string if no method of the given signature exists.
		// Returns a complete signature if a method is found.
		std::string CompleteSignature(const std::string& signature);

		void CallFunction(Bytecode& bytecode);

		void CollectGarbage();

		x_method GetMethod(x_class xClass, std::string signature)
		{
			auto method = xClass->FunctionIndices.find(signature);
			if (method != xClass->FunctionIndices.end())
				return xClass->Functions[method->second];
			else
				return nullptr;
		}

		x_method GetImplicitCast(x_class xClass, std::string signature)
		{
			auto method = xClass->ImplicitCastIndices.find(signature);
			if (method != xClass->ImplicitCastIndices.end())
				return xClass->Functions[method->second];
			else
				return nullptr;
		}

		x_method GetImplicitConversion(x_class from, x_class to);

		template <typename... TArgs>
		Value CallStaticMethod(x_method method, TArgs... args)
		{
#ifdef X_DEBUG
			if (sp != &m_Stack[0])
			{
				Error("CallStaticMethod: Stack pointer was not at the front!");
				return 0;
			}
			if (m_FrameCount != 0)
			{
				Error("CallStaticMethod: There are residual stack frames!");
				return 0;
			}
			if (method == nullptr)
			{
				Error("CallStaticMethod: Supplied method is null!");
				return 0;
			}
			if (method->Arity != sizeof...(args))
			{
				Error("CallStaticMethod: Incorrect number of arguments provided!");
				return 0;
			}
#endif

			push(Value{ (x_object*)method });
			push({ Value{ args }... });

			CallFunction(method);
			return Run();
		}
		template <typename... TArgs>
		Value CallMemberMethod(x_object* object, x_member_method id, TArgs... args)
		{
#ifdef X_DEBUG
			if (sp != &m_Stack[0])
			{
				Error("CallMemberMethod: Stack pointer was not at the front!");
				return 0;
			}
			if (m_FrameCount != 0)
			{
				Error("CallMemberMethod: There are residual stack frames!");
				return 0;
			}
			if (object == nullptr)
			{
				Error("CallMemberMethod: Supplied object is null!");
				return 0;
			}
			if (((InstanceObject*)(object))->Class->Functions.size() <= id)
			{
				Error("CallMemberMethod: Can not find member method!");
				return 0;
			}
			if (((InstanceObject*)(object))->Class->Functions[id]->Arity != sizeof...(args))
			{
				Error("CallMemberMethod: Incorrect number of arguments provided!");
				return 0;
			}
#endif
			x_method method = ((InstanceObject*)(object))->Class->Functions[id];

			push(method);
			push({ args... });

			CallFunction(method);
			return Run();
		}
	private:
		bool LogMessages(std::vector<CompilationMessage>& messages);
		void LogMessage(CompilationMessage& message);
		void Error(const char* msg);
		void Error(const std::string& msg);
		void CompilationError(x_class xClass, const char* msg);
		void CompilationError(x_class xClass, const std::string& msg);

		void RegisterClass(const ClassInfo& classInfo);
		void SetParent(const ClassInfo& classInfo);
		void CompileClass(ClassInfo& classInfo);
		void AddField(x_class xClass, const std::string& name);
		x_ulong FindField(x_class xClass, const std::string& name);
		void AddMethod(x_class xClass, x_method method);
		void AddImplicitCast(x_class xClass, x_method method);
		bool Compile(x_class xClass, x_method method, Statement& block);
		void GenerateClassInfo(const CompilationUnit& unit);
		//void CompileField(x_ulong fieldID, const FieldInfo& fieldInfo, x_method method);
		//x_method CompileStatement(const Statement& statement);
		//void CompileStatement(const Statement& statement, x_method method);
		//XType CompileExpression(const Expression& expression, x_method method);

		template<typename T>
		inline T* Alloc();
		template<typename T>
		inline T* AllocArray(x_ulong count);
		template<typename T>
		void Dealloc(T* ptr);
		template<typename T>
		void DeallocArray(T* ptr, x_ulong size);

		StringObject* FindInternedString(const char* chars, x_ulong length);

		void FreeObjects();
		void FreeObject(x_object* object);
		void MarkRoots();
		void TraceReferences();
		void RemoveInterned();
		void Sweep();
		void BlackenObject(x_object* object);
		void MarkObject(x_object* object);

		template<typename T>
		T* AllocObject(ObjectType type);
		StringObject* AllocateString(char* chars, x_ulong length);
		FunctionObject* NewFunction();
		void DuplicateFunction(x_method oldFunction, x_method newFunction);
		FunctionObject* DuplicateFunction(x_method oldFunction);
		NativeObject* NewNative(NativeFn function);
		VoidNativeObject* NewVoidNative(VoidNativeFn function);

		x_class AddClass(const std::string& name);
		void RemoveClass(x_class xClass);

		void CallFunction(FunctionObject* function);

		void push(Value& value);

		Value RunMethod(x_method method);
		Value Run();
	private:
		struct ScopedPin
		{
			ScopedPin(Vm* xvm, x_object* object);
			~ScopedPin();
		private:
			Vm* m_XVM;
			x_object* m_Object;
		};
	protected:
		x_object* FindPinnedObject(x_object* object);
		ScopedPin PinObject(x_object* object);
		// Does not check if the supplied object is already present.
		void ForcePinObject(x_object* object);
		void UnPinObject(x_object* object);
	};

}
