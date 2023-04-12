#include "CppUnitTest.h"
#include "../Receipe/Ingredient.h"
#include "../Receipe/Ingredient.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IngredientTests
{
	TEST_CLASS(IngredientTests)
	{
	public:
		
		TEST_METHOD(constructor_typical)
		{
			Ingredient ingredient("cukier", 5, "spoons");
			string cuk = "cukier", uni = "spoons";
			Assert::AreEqual(cuk, ingredient.get_name());
			Assert::AreEqual(unsigned short(5), ingredient.get_amount());
			Assert::AreEqual(uni, ingredient.get_unit());
		}
		TEST_METHOD(constructor_negative_amount)
		{
			try {
				Ingredient ingerdient("cukier", -1, "spoons");
			}
			catch (const char* x){
				Assert::AreEqual("Amount has to be over 1.", x);
			}
		}
		TEST_METHOD(constructor_ivalid_unit)
		{
			try {
				Ingredient ingredient("cukier", 5, "asd");
			}
			catch (const char* x) {
				Assert::AreEqual("Invalid unit!", x);
			}
		}
		TEST_METHOD(set_name_typical)
		{
			Ingredient ingredient("cukier", 5, "spoons");
			string cuk = "cukier", new_name = "sól";
			Assert::AreEqual(cuk, ingredient.get_name());
			ingredient.set_name(new_name);
			Assert::AreEqual(new_name, ingredient.get_name());
		}
		TEST_METHOD(set_amount_typical)
		{
			Ingredient ingredient("cukier", 5, "spoons");
			Assert::AreEqual(unsigned short(5), ingredient.get_amount());
			ingredient.set_amount(9);
			Assert::AreEqual(unsigned short(9), ingredient.get_amount());
		}
		TEST_METHOD(set_amount_negative)
		{
			Ingredient ingredient("cukier", 5, "spoons");
			Assert::AreEqual(unsigned short(5), ingredient.get_amount());
			try {
				ingredient.set_amount(short(-5));
			}
			catch (const char* x) {
				Assert::AreEqual("Amount has to be over 1.", x);
			}
		}
		TEST_METHOD(set_unit_invalid)
		{
			Ingredient ingredient("cukier", 5, "spoons");
			string uni = "spoons", new_uni = "asds";
			Assert::AreEqual(uni, ingredient.get_unit());
			try {
				ingredient.set_unit(new_uni);
			}
			catch (const char* x) {
				Assert::AreEqual("Invalid unit!", x);
			}
		}
		TEST_METHOD(set_unit_typical)
		{
			Ingredient ingredient("cukier", 5, "spoons");
			string uni = "spoons", new_uni = "g";
			Assert::AreEqual(uni, ingredient.get_unit());
			ingredient.set_unit(new_uni);
			Assert::AreEqual(new_uni, ingredient.get_unit());
		}
		TEST_METHOD(count_mass_from_g)
		{
			Ingredient ingredient("cukier", 5, "g");
			Assert::AreEqual(unsigned short(5), ingredient.count_mass());
		}
		TEST_METHOD(count_mass_from_spoons)
		{
			Ingredient ingredient("cukier", 5, "spoons");
			Assert::AreEqual(unsigned short(15*5), ingredient.count_mass());
		}
		TEST_METHOD(count_mass_from_ml)
		{
			Ingredient ingredient("cukier", 5, "ml");
			Assert::AreEqual(unsigned short(5), ingredient.count_mass());
		}
		TEST_METHOD(count_mass_from_pieces)
		{
			Ingredient ingredient("cukier", 5, "pieces");
			Assert::AreEqual(unsigned short(100 * 5), ingredient.count_mass());
		}
		TEST_METHOD(info)
		{
			Ingredient ingredient("cukier", 5, "ml");
			string info = "5 ml of cukier\n";
			Assert::AreEqual(info, ingredient.info());
		}
	};
}
