#pragma once

#include "common.h"
#include "types.h"
#include "bytecode.h"
#include "instructions.h"
#include "object.h"
#include "compilation_unit.h"

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

		std::vector<x_object*> m_GrayStack;
		x_object* m_Objects = nullptr;

		std::vector<x_object*> m_PinnedObjects;

		size_t m_BytesAllocated;
		size_t m_NextGC;
	public:
		Vm();
		~Vm();
		
		bool Compile(const CompilationUnit& compilationUnit);

		void RegisterFunction(const std::string&, NativeFn function);
		void RegisterVoidFunction(const std::string&, VoidNativeFn function);

		StringObject* TakeString(char* chars, x_ulong length);
		StringObject* CopyString(const char* chars, x_ulong length);
		StringObject* CopyString(const std::string& string);

		InstanceObject* NewInstance(x_class xClass);

		void AddGlobal(const std::string& name, Value& value);
		Value GetGlobal(const std::string& name);
		
		x_class GetClass(const std::string& name);

		void CallFunction(Bytecode& bytecode);

		void CollectGarbage();

		x_method GetStaticMethod(x_class xClass, std::string signature)
		{
			auto method = xClass->FunctionIndices.find(signature);
			if (method != xClass->FunctionIndices.end())
				return xClass->Functions[method->second];
			else
				return nullptr;
		}

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
#endif
			if (method->Arity != sizeof...(args))
			{
				Error("CallStaticMethod: Incorrect number of arguments provided!");
				return 0;
			}

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
#endif
			if (((InstanceObject*)(object))->Class->Functions[id]->Arity != sizeof...(args))
			{
				Error("CallMemberMethod: Incorrect number of arguments provided!");
				return 0;
			}
			x_method method = ((InstanceObject*)(object))->Class->Functions[id];

			push(method);
			push({ args... });

			CallFunction(method);
			return Run();
		}
	private:
		void Error(const char* msg);
		void Error(const std::string& msg);
		void CompilationError(x_class xClass, const char* msg);
		void CompilationError(x_class xClass, const std::string& msg);

		void RegisterClass(const ClassInfo& classInfo);
		void CompileClass(const ClassInfo& classInfo);
		void AddField(x_class xClass, const std::string& name);
		x_ulong FindField(x_class xClass, const std::string& name);
		void AddMethod(x_class xClass, x_method method);
		void CompileField(x_ulong fieldID, const FieldInfo& fieldInfo, x_method method);
		x_method CompileStatement(const Statement& statement);
		void CompileStatement(const Statement& statement, x_method method);
		XType CompileExpression(const Expression& expression, x_method method);

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

		x_object* FindPinnedObject(x_object* object);
		void PinObject(x_object* object);
		// Avoids checking if the supplied object is already present.
		void ForcePinObject(x_object* object);
		void UnPinObject(x_object* object);

		template<typename T>
		T* AllocObject(ObjectType type);
		StringObject* AllocateString(char* chars, x_ulong length);
		FunctionObject* NewFunction();
		FunctionObject* DuplicateFunction(FunctionObject* oldFunction);
		NativeObject* NewNative(NativeFn function);
		VoidNativeObject* NewVoidNative(VoidNativeFn function);

		x_class AddClass(const std::string& name);
		void RemoveClass(x_class xClass);

		void CallFunction(FunctionObject* function);

		void push(Value& value);

		Value RunMethod(x_method method);
		Value Run();
	};

}
