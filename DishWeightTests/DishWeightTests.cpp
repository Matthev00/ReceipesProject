#include "CppUnitTest.h"
#include "../Receipe/DishWeight.h"
#include "../Receipe/DishWeight.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace DishWeightTests
{
	TEST_CLASS(DishWeightTests)
	{
	public:
		
		TEST_METHOD(constructor_empty_unit_and_getters)
		{
			DishWeight dw(30);
			Assert::AreEqual(unsigned int(30), dw.get_amount());
			Assert::AreEqual(std::string("g"), dw.get_unit());
		}
		TEST_METHOD(constructor_typical_and_getters)
		{
			DishWeight dw(30, "kg");
			Assert::AreEqual(unsigned int(30), dw.get_amount());
			Assert::AreEqual(std::string("kg"), dw.get_unit());
		}
		TEST_METHOD(unit_setter)
		{
			DishWeight dw(30);
			dw.set_unit("t");
			Assert::AreEqual(unsigned int(30), dw.get_amount());
			Assert::AreEqual(std::string("t"), dw.get_unit());
		}
		TEST_METHOD(amount_setter_typical)
		{
			DishWeight dw(30);
			dw.set_amount(100);
			Assert::AreEqual(unsigned int(100), dw.get_amount());
			Assert::AreEqual(std::string("g"), dw.get_unit());
		}
		TEST_METHOD(operator_equal_true)
		{
			DishWeight dw(30);
			DishWeight dw1(30);
			Assert::AreEqual(true, dw==dw1);
		}
		TEST_METHOD(operator_equal_false_true)
		{
			DishWeight dw(30);
			DishWeight dw1(30, "kg");
			Assert::AreEqual(false, dw == dw1);
		}
	};
}
