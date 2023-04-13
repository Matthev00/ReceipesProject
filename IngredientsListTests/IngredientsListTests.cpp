#include "CppUnitTest.h"
#include "../Receipe/Ingredient.h"
#include "../Receipe/Ingredient.cpp"
#include "../Receipe/IngredientsList.h"
#include "../Receipe/IngredientsList.cpp"
#include "../Receipe/DishWeight.h"
#include "../Receipe/DishWeight.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IngredientLIstTests
{
	TEST_CLASS(IngredientLIstTests)
	{
	public:

		TEST_METHOD(constructor)
		{
			Ingredient i1("salt", 15, "g");
			Ingredient i2("sugar", 15, "g");
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			IngredientsList ingredient_list(ingredients);
			Assert::AreEqual(ingredient_list.count_number_of_ingredients(), unsigned int(1));
		}
		TEST_METHOD(count_dish_weight)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("sugar"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			ingredients.push_back(i2);
			IngredientsList ingredient_list(ingredients);
			DishWeight dw(30);
			Assert::AreEqual(true, dw==ingredient_list.count_dish_weight());
		}
		
		TEST_METHOD(get_ingredient_typical)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("sugar"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			ingredients.push_back(i2);
			IngredientsList ingredient_list(ingredients);
			Ingredient i3 = ingredient_list.get_ingredient(1);
			Assert::AreEqual(true, i2==i3);
		}

		TEST_METHOD(get_ingredient_out_of_range)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("sugar"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			ingredients.push_back(i2);
			IngredientsList ingredient_list(ingredients);
			try {
				Ingredient i3 = ingredient_list.get_ingredient(1);
			}
			catch (const char* x)
			{
				Assert::AreEqual("There are not as many ingredients.", x);
			}
		}
		
		TEST_METHOD(count_number_of_ingredients)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("sugar"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			ingredients.push_back(i2);
			IngredientsList ingredient_list(ingredients);
			Assert::AreEqual(unsigned int(2), ingredient_list.count_number_of_ingredients());
		}

		TEST_METHOD(count_number_of_ingredients_and_weight_empty_ingredients)
		{
			vector<Ingredient> ingredients;
			IngredientsList ingredient_list(ingredients);
			Assert::AreEqual(unsigned int(0), ingredient_list.count_number_of_ingredients());
			DishWeight dw(0);
			Assert::AreEqual(true, dw==ingredient_list.count_dish_weight());
		}

		TEST_METHOD(add_ingredient)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("sugar"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			IngredientsList ingredient_list(ingredients);
			Assert::AreEqual(unsigned int(1), ingredient_list.count_number_of_ingredients());
			ingredient_list.add_ingredient(i2);
			Assert::AreEqual(unsigned int(2), ingredient_list.count_number_of_ingredients());
		}

		TEST_METHOD(remove_ingredient)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("sugar"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			IngredientsList ingredient_list(ingredients);
			Assert::AreEqual(unsigned int(1), ingredient_list.count_number_of_ingredients());
			ingredient_list.remove_ingredient(std::string("salt"));
			Assert::AreEqual(unsigned int(0), ingredient_list.count_number_of_ingredients());
		}

		TEST_METHOD(remove_not_existing_ingredient)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("sugar"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			IngredientsList ingredient_list(ingredients);
			Assert::AreEqual(unsigned int(1), ingredient_list.count_number_of_ingredients());
			ingredient_list.remove_ingredient(std::string("sal"));
			Assert::AreEqual(unsigned int(1), ingredient_list.count_number_of_ingredients());
		}
		
		TEST_METHOD(plusequal_operator_one_element)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("sugar"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			IngredientsList ingredient_list(ingredients);
			Assert::AreEqual(unsigned int(1), ingredient_list.count_number_of_ingredients());
			ingredient_list += i2;
			Assert::AreEqual(unsigned int(2), ingredient_list.count_number_of_ingredients());
		}
		TEST_METHOD(plusequal_operator_vector)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("sugar"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			IngredientsList ingredient_list(ingredients);
			ingredients.push_back(i2);
			Assert::AreEqual(unsigned int(1), ingredient_list.count_number_of_ingredients());
			ingredient_list += ingredients;
			Assert::AreEqual(unsigned int(3), ingredient_list.count_number_of_ingredients());
		}

		TEST_METHOD(plusequal_operator_IngredientList)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("sugar"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			IngredientsList ingredient_list(ingredients);
			ingredients.push_back(i2);
			Assert::AreEqual(unsigned int(1), ingredient_list.count_number_of_ingredients());
			IngredientsList ingredient_list_2(ingredients);
			ingredient_list += ingredient_list_2;
			Assert::AreEqual(unsigned int(3), ingredient_list.count_number_of_ingredients());
		}

		TEST_METHOD(minusequal_operator_string)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("sugar"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			IngredientsList ingredient_list(ingredients);
			Assert::AreEqual(unsigned int(1), ingredient_list.count_number_of_ingredients());
			ingredient_list -= std::string("salt");
			Assert::AreEqual(unsigned int(0), ingredient_list.count_number_of_ingredients());
		}

		TEST_METHOD(minusequal_operator_Ingredient_object)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("sugar"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			IngredientsList ingredient_list(ingredients);
			Assert::AreEqual(unsigned int(1), ingredient_list.count_number_of_ingredients());
			ingredient_list -= i1;
			Assert::AreEqual(unsigned int(0), ingredient_list.count_number_of_ingredients());
		}
		TEST_METHOD(iterator_typical)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("milk"), 50, std::string("ml"));
			Ingredient i3(std::string("suger"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			IngredientsList ingredient_list(ingredients);
			ingredient_list += i2;
			ingredient_list += i3;
			int counter = 0;
			std::vector<Ingredient> x=ingredient_list.get_ingredients();
			IngredientsListIterator z(x.begin(), x.end(), "g");
			for (auto it = ingredient_list.begin("g"); it != ingredient_list.end(); ++it)
			{
				counter++;
			}
			Assert::AreEqual(2, counter);
			Assert::AreEqual((*z).get_name(), std::string("salt"));
			++z;
			Assert::AreEqual((*z).get_name(), std::string("suger"));
		}

		TEST_METHOD(iterator_typical_incorrect_unit)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("milk"), 50, std::string("ml"));
			Ingredient i3(std::string("suger"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			IngredientsList ingredient_list(ingredients);
			ingredient_list += i2;
			ingredient_list += i3;
			int counter = 0;
			try 
			{
				for (auto it = ingredient_list.begin("incorrect"); it != ingredient_list.end(); ++it)
				{
					counter++;
				}
			}
			catch (const char* x)
			{
				Assert::AreEqual("Invalid unit!", x);
			}
		}
		TEST_METHOD(iterator_for_each_Ingredient_typical)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("milk"), 50, std::string("ml"));
			Ingredient i3(std::string("suger"), 15, std::string("g"));
			Ingredient i4(std::string("water"), 15, std::string("ml"));
			Ingredient i5(std::string("suger"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			IngredientsList ingredient_list(ingredients);
			ingredient_list += i2;
			ingredient_list += i3;
			ingredient_list += i4;
			ingredient_list += i5;
			ingredient_list.set_iterator_unit("ml");
			int counter = 0;
			for (auto& ingredient : ingredient_list)
			{
				counter++;
			}
			Assert::AreEqual(2, counter);
		}
		TEST_METHOD(iterator_for_each_Ingredient_first_and_last)
		{
			Ingredient i1(std::string("salt"), 15, std::string("g"));
			Ingredient i2(std::string("milk"), 50, std::string("ml"));
			Ingredient i3(std::string("suger"), 15, std::string("g"));
			Ingredient i4(std::string("water"), 15, std::string("ml"));
			Ingredient i5(std::string("suger"), 15, std::string("g"));
			vector<Ingredient> ingredients;
			ingredients.push_back(i1);
			IngredientsList ingredient_list(ingredients);
			ingredient_list += i2;
			ingredient_list += i3;
			ingredient_list += i4;
			ingredient_list += i5;
			ingredient_list.set_iterator_unit("g");
			int counter = 0;
			for (auto& ingredient : ingredient_list)
			{
				counter++;
			}
			Assert::AreEqual(3, counter);
		}
	};
}