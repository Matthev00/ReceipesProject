#include "IngredientsList.h"
#include <iostream>
#include <fstream>


IngredientsList::IngredientsList(std::vector<Ingredient> ingredients)
{
	IngredientsList::ingredients = ingredients;
}

std::vector<Ingredient> IngredientsList::get_ingredients() const
{
    return ingredients;
}

Ingredient IngredientsList::get_ingredient(unsigned int position) const
{
    if (position >= count_number_of_ingredients()) {
        throw "There are not as many ingredients.";
    }
    return ingredients[position];
}

unsigned int IngredientsList::count_dish_weight() const
{
    int dish_weight = 0;
    for (int i = 0; i < ingredients.size(); ++i)
    {
        dish_weight += ingredients[i].count_mass();
    }
    return dish_weight;
}

unsigned int IngredientsList::count_number_of_ingredients() const
{
    return ingredients.size();
}

void IngredientsList::add_ingredient(Ingredient& ingredient)
{
    ingredients.push_back(ingredient);
}

void IngredientsList::remove_ingredient(std::string ingredient)
{
    for (int i = 0; i < ingredients.size(); ++i)
    {
        if (ingredients[i].get_name() == ingredient) {
            ingredients.erase(ingredients.begin() + i);
        }
    }
}

void IngredientsList::save_to_file_nice_format(std::string file_name) const
{
    std::fstream out;
    try {
        out.open(file_name, std::ios::out);
    }
    catch (std::ifstream::failure x) {
        std::cout << x.what() << std::endl;
    }
    print_nice(out, *this);
    out.close();
}

void IngredientsList::save_to_file(std::string file_name) const
{
    std::fstream out;
    try {
        out.open(file_name, std::ios::out);
    }
    catch (std::ifstream::failure x) {
        std::cout << x.what() << std::endl;
    }
    out << *this;
    out.close();
}

void IngredientsList::read_from_file(std::string file_name)
{
    std::fstream in;
    try {
        in.open(file_name, std::ios::in);
    }
    catch (std::ifstream::failure x) {
        std::cout << x.what() << std::endl;
    }
    in >> *this;
    in.close();
}

void IngredientsList::operator+=(Ingredient& ingredient)
{
    ingredients.push_back(ingredient);
}

std::ostream& IngredientsList::print_nice(std::ostream& output, const IngredientsList& il)const
{
    output << "Number of Ingredients in the list ";
    output << il.count_number_of_ingredients() << ":\n";
    for (unsigned int i = 0; i < il.count_number_of_ingredients(); ++i) {
        Ingredient ingredient = il.ingredients[i];
        output << ingredient.info();
    }
    return output;
}

void IngredientsList::operator-=(Ingredient& ingredient)
{
    for (int i = 0; i < ingredients.size(); ++i)
    {
        if (ingredients[i] == ingredient) {
            ingredients.erase(ingredients.begin() + i);
        }
    }
}

void IngredientsList::operator-=(std::string ingredient)
{
    for (int i = 0; i < ingredients.size(); ++i)
    {
        if (ingredients[i].get_name() == ingredient) {
            ingredients.erase(ingredients.begin() + i);
        }
    }
}

IngredientsList IngredientsList::operator+(IngredientsList ingredient_list_to_add)
{
    return *this + ingredient_list_to_add.ingredients;
}

void IngredientsList::operator+=(std::vector<Ingredient>& ingredients_to_add)
{
    ingredients.insert(ingredients.end(),
        ingredients_to_add.begin(),
        ingredients_to_add.end());
}

void IngredientsList::operator+=(IngredientsList& ingredient_list_to_add)
{
    *this += ingredient_list_to_add.ingredients;
}

std::ostream& operator<<(std::ostream& output, const IngredientsList& il)
{
    output << il.count_number_of_ingredients() << ":\n";
    for (unsigned int i = 0; i < il.count_number_of_ingredients(); ++i) {
        Ingredient ingredient = il.ingredients[i];
        output << ingredient;
    }
    return output;
}

std::istream& operator>>(std::istream& input, IngredientsList& il)
{
    short n = 0;
    char ch;
    input >> n >> ch;
    if (n < 1) {
        throw "Invalid number of ingredients.";
    }
    if (ch != ':') {
        throw "Missing ':'.";
    }
    for (int i = 0; i < n; i++) {
        Ingredient ingredient;
        input >> ingredient;
        il+=ingredient;
    }
    return input;
}

IngredientsListIterator IngredientsList::begin(std::string unit) 
{
    if (unit != "g" && unit != "ml" && unit != "spoons" && unit != "pieces"){
        throw "Invalid unit!";
    }
    auto it = ingredients.begin();
    auto end = ingredients.end();
    while (it != end && it->get_unit() != unit) {
        ++it;
    }
    return IngredientsListIterator(it, end, unit);
}

IngredientsListIterator IngredientsList::end() 
{
    return IngredientsListIterator(ingredients.end(), ingredients.end(), "");
}

IngredientsListIterator::IngredientsListIterator(std::vector<Ingredient>::iterator it, std::vector<Ingredient>::iterator end, std::string unit)
{
    IngredientsListIterator::it = it;
    IngredientsListIterator::unit = unit;
    IngredientsListIterator::end = end;
}

bool IngredientsListIterator::operator!=(const IngredientsListIterator& other) const
{
    return it != other.it;
}

Ingredient& IngredientsListIterator::operator*() const
{
    return *it;
}

IngredientsListIterator& IngredientsListIterator::operator++()
{
    do 
    {
        ++it;
    } while (it != end && it->get_unit() != unit);
    return *this;
}
