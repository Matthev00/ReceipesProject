#include <iostream>
#include "Receipe.h"
#include <fstream>
using namespace std;

Receipe::Receipe()
{
}

Receipe::Receipe(string name, short preparation_time, IngredientsList ingredient_list)
{
    Receipe::name = name;
    if (preparation_time < 0) {
        throw "Value can not be negative.";
    }
    Receipe::preparation_time = preparation_time;
    Receipe::ingredients = ingredient_list;
}

string Receipe::get_name() const
{
    return name;
}

void Receipe::set_name(string new_name)
{
    name = new_name;
}

unsigned short Receipe::get_preparation_time() const
{
    return preparation_time;
}

void Receipe::set_preparation_time(short new_preparation_time)
{
    if (new_preparation_time < 0) {
        throw "Value can not be negative.";
    }
    preparation_time = new_preparation_time;
}

unsigned int Receipe::count_dish_weight()const
{
    return ingredients.count_dish_weight();
}

unsigned int Receipe::count_number_of_ingredients() const
{
    return ingredients.count_number_of_ingredients();
}

void Receipe::add_ingredient(Ingredient ingredient)
{
    ingredients += ingredient;
}

void Receipe::save_to_file(std::string file_name) const
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

void Receipe::read_from_file(std::string file_name)
{
    std::fstream in;
    try {
        in.open(file_name, std::ios::in);
    }
    catch (std::ifstream::failure x) {
        std::cout << x.what() << std::endl;
        return;
    }
    in >> *this;
    in.close();
}

ostream& operator<<(ostream& output, const Receipe& r)
{
    output << r.name << " " << r.preparation_time << " ";
    output << r.ingredients;
    return output;
}

istream& operator>>(istream& input, Receipe& r)
{
    short r_preparation_time;
    string r_name;
    input >> r_name >> r_preparation_time;
    r.set_name(r_name);
    r.set_preparation_time(r_preparation_time);
    input >> r.ingredients;
    return input;
}
