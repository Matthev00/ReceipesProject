#pragma once
#include "Ingredient.h"
#include <iostream>
#include <vector>
#include "IngredientsList.h"


class Receipe
{
private:
	std::string name;
	IngredientsList ingredients;
	unsigned short preparation_time;
public:
	Receipe();
	Receipe(std::string, short, IngredientsList = IngredientsList());
	std::string get_name()const;
	void set_name(std::string);
	unsigned short get_preparation_time()const;
	void set_preparation_time(short);
	unsigned int count_dish_weight()const;
	unsigned int count_number_of_ingredients()const;
	void add_ingredient(Ingredient);
	void save_to_file(std::string)const;
	void read_from_file(std::string);
	friend std::ostream& operator<<(std::ostream& output, const Receipe& r);
	friend std::istream& operator>>(std::istream& input, Receipe& r);
};

