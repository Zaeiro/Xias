#pragma once

#include "common.h"
#include "types.h"
#include "bytecode.h"
#include "instructions.h"
#include "object.h"

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
		x_long m_StackSize;

		std::unordered_map<std::string, x_ulong> m_ClassNames;
		std::vector<x_class> m_Classes;

		std::vector<x_object*> m_GrayStack;
		x_object* m_Objects = nullptr;

		size_t m_BytesAllocated;
		size_t m_NextGC;
	public:
		Vm();
		~Vm();
		
		void RegisterFunction(const std::string&, NativeFn function);
		void RegisterVoidFunction(const std::string&, VoidNativeFn function);

		StringObject* TakeString(char* chars, x_ulong length);
		StringObject* CopyString(const char* chars, x_ulong length);

		InstanceObject* NewInstance(x_class xClass);

		void AddGlobal(const std::string& name, Value& value);
		Value GetGlobal(const std::string& name);
		
		void CallFunction(Bytecode& bytecode);

		void CollectGarbage();

		template <typename... TArgs>
		Value CallStaticMethod(x_method method, TArgs... args)
		{
#ifdef X_DEBUG
			if (sp != &m_Stack[0])
			{
				Error("Stack pointer was not at the front!");
			}
			if (m_FrameCount != 0)
			{
				Error("There are residual stack frames!");
			}
			if (method->Arity != sizeof...(args))
			{
				Error("Incorrect number of arguments provided!");
			}
#endif
			push(method);
			push({ args... });

			CallFunction(method);
			return Run();
		}
		template <typename... TArgs>
		Value CallMemberMethod(x_object* object, x_member_method id, TArgs... args)
		{
#ifdef X_DEBUG
			if (sp != &m_Stack[0])
			{
				Error("Stack pointer was not at the front!");
			}
			if (m_FrameCount != 0)
			{
				Error("There are residual stack frames!");
			}
			if (((InstanceObject*)(object))->Class->Functions[id]->Arity != sizeof...(args))
			{
				Error("Incorrect number of arguments provided!");
			}
#endif
			x_method method = ((InstanceObject*)(object))->Class->Functions[id];

			push(method);
			push({ args... });

			CallFunction(method);
			return Run();
		}
	private:
		void Error(const char* msg);

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
		NativeObject* NewNative(NativeFn function);
		VoidNativeObject* NewVoidNative(VoidNativeFn function);

		void CallFunction(FunctionObject* function);

		inline void push(Value& value);

		Value RunMethod(x_method method);
		Value Run();
	};

}
