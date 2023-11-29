#include "pch.h"
#include "CppUnitTest.h"
#include "../Project9.1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91A
{
	TEST_CLASS(UnitTest91A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Specialty specialty = MATH_ECONOMICS;
            const char* str = specialtiesToString(specialty);
            Assert::AreEqual("Mathematics and economics", str);

		}
	};
}
