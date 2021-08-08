#include "Xias.h"

#include <iostream>
#include <sstream>
#include <cstdint>
#include <chrono>

int main()
{
	const char* script =
		R"(
class ExampleClass {
	int m_ID = 93;
	public float m_Float;
}

struct Data {
	string Data;
}

namespace Foo {
	class Bar {
		ExampleClass m_Example;

		Bar() {
			// C's srand registered from C++
			srand(1872);
		}

		public Data GetData() { return new Data(); }
		public virtual int GenerateNumber() {
			// A random number function that we register from C++
			return rand();
		}

		public static virtual float SoManyKeywords(string String) { return 7.0; }
	}

	class Child : Bar {
		public override int GenerateNumber() { return 5; }
	}

	class ZealousChild : Bar {
		public static override float SoManyKeywords(string String) {
			int number = 83;
			float result = number * 2.5;
			return result;
		}

		public void DoNothing() {}
	}
}
)";

	std::vector<uint8_t> data;
	data.resize(10);
	uint8_t* pdata = data.data();
	*pdata = (uint8_t)Xias::Instructions::push_float;
	pdata++;
	*((float*)pdata) = 1000.7f;
	pdata += sizeof(float);

	*pdata = (uint8_t)Xias::Instructions::float_add_float_float;
	pdata++;
	*((float*)pdata) = 200.0f;
	pdata += sizeof(float);

	Xias::Vm xvm;

	xvm.callfunction(data);

}
