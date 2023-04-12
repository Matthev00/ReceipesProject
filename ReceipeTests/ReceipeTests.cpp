#include "../Receipe/Receipe.h"
#include "../Receipe/Receipe.cpp"
#include "CppUnitTest.h"
#include "../Receipe/Ingredient.h"
#include "../Receipe/Ingredient.cpp"
#include "../Receipe/IngredientsList.h"
#include "../Receipe/IngredientsList.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ReceipeTests
{
	TEST_CLASS(ReceipeTests)
	{
	public:
		
		TEST_METHOD(constructor_typical)
		{
			Ingredient ingredient("cukier", 5, "spoons");
			vector < Ingredient> ingredients;
			ingredients.push_back(ingredient);
			IngredientsList ingredients_list(ingredients);
			Receipe receipe("przepis", 35, ingredients_list);
			Assert::AreEqual(string("przepis"), receipe.get_name());
			Assert::AreEqual(unsigned short(35), receipe.get_preparation_time());
		}
		TEST_METHOD(constructor_negative_time)
		{
			Ingredient ingredient("cukier", 5, "spoons");
			vector < Ingredient> ingredients;
			ingredients.push_back(ingredient);
			IngredientsList ingredients_list(ingredients);
			try {
				Receipe receipe("przepis", -5, ingredients_list);
			}
			catch (const char* x) {
				Assert::AreEqual("Value can not be negative.", x);
			}
		}
		TEST_METHOD(constructor_empty_ingredients)
		{
			Receipe receipe(std::string("przepis"), 35);
			Assert::AreEqual(string("przepis"), receipe.get_name());
			Assert::AreEqual(unsigned short(35), receipe.get_preparation_time());
		}
		TEST_METHOD(set_name)
		{
			Receipe receipe("przepis", 35);
			Assert::AreEqual(string("przepis"), receipe.get_name());
			receipe.set_name("przepis2");
			Assert::AreEqual(string("przepis2"), receipe.get_name());
		}
		TEST_METHOD(set_preparation_typical)
		{
			Receipe receipe("przepis", 35);
			Assert::AreEqual(unsigned short(35), receipe.get_preparation_time());
			receipe.set_preparation_time(unsigned short(44));
			Assert::AreEqual(unsigned short(44), receipe.get_preparation_time());
		}
		TEST_METHOD(set_preparation_negative)
		{
			Receipe receipe("przepis", 35);
			Assert::AreEqual(unsigned short(35), receipe.get_preparation_time());
			try {
				receipe.set_preparation_time(44);
			}
			catch (const char* x){
				Assert::AreEqual("Value can not be negative.", x);
			}
		}
		TEST_METHOD(count_dish_weight_typical)
		{
			Ingredient ingredient("cukier", 5, "spoons");
			Ingredient ingredient1("sól", 5, "spoons");
			Ingredient ingredient2("banan", 1, "pieces");
			Ingredient ingredient3("mleko", 250, "ml");
			vector < Ingredient> ingredients;
			ingredients.push_back(ingredient);
			ingredients.push_back(ingredient1);
			ingredients.push_back(ingredient2);
			ingredients.push_back(ingredient3);
			IngredientsList ingredients_list(ingredients);
			Receipe receipe("przepis", 35, ingredients_list);
			Assert::AreEqual(string("przepis"), receipe.get_name());
			Assert::AreEqual(unsigned short(35), receipe.get_preparation_time());
			Assert::AreEqual(unsigned int(500), receipe.count_dish_weight());
		}
		TEST_METHOD(count_dish_weight_empty_ingredients)
		{
			Receipe receipe("przepis", 35);
			Assert::AreEqual(string("przepis"), receipe.get_name());
			Assert::AreEqual(unsigned short(35), receipe.get_preparation_time());
			Assert::AreEqual(unsigned int(0), receipe.count_dish_weight());
		}
		TEST_METHOD(count_number_of_ingredients_typical)
		{
			Ingredient ingredient("cukier", 5, "spoons");
			Ingredient ingredient1("sól", 5, "spoons");
			Ingredient ingredient2("banan", 1, "pieces");
			Ingredient ingredient3("mleko", 250, "ml");
			vector < Ingredient> ingredients;
			ingredients.push_back(ingredient);
			ingredients.push_back(ingredient1);
			ingredients.push_back(ingredient2);
			ingredients.push_back(ingredient3);
			IngredientsList ingredients_list(ingredients);
			Receipe receipe("przepis", 35, ingredients_list);
			Assert::AreEqual(string("przepis"), receipe.get_name());
			Assert::AreEqual(unsigned short(35), receipe.get_preparation_time());
			Assert::AreEqual(unsigned int(4), receipe.count_number_of_ingredients());
		}
		TEST_METHOD(count_number_of_ingredients_empty_ingredients)
		{
			Receipe receipe("przepis", 35);
			Assert::AreEqual(string("przepis"), receipe.get_name());
			Assert::AreEqual(unsigned short(35), receipe.get_preparation_time());
			Assert::AreEqual(unsigned int(0), receipe.count_number_of_ingredients());
		}
		TEST_METHOD(add_ingredient)
		{
			Ingredient ingredient("cukier", 5, "spoons");
			Ingredient ingredient1("sól", 5, "spoons");
			vector < Ingredient> ingredients;
			ingredients.push_back(ingredient);
			IngredientsList ingredients_list(ingredients);
			Receipe receipe("przepis", 35, ingredients_list);
			Assert::AreEqual(unsigned int(1), receipe.count_number_of_ingredients());
			Assert::AreEqual(unsigned int(75), receipe.count_dish_weight());
			receipe.add_ingredient(ingredient1);
			Assert::AreEqual(unsigned int(2), receipe.count_number_of_ingredients());
			Assert::AreEqual(unsigned int(150), receipe.count_dish_weight());
		}
	};
}
