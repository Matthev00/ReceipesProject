#pragma once
#include "Ingredient.h"
#include <iostream>
#include <vector>


class IngredientsListIterator {
private:
	std::vector<Ingredient>::iterator it;
	std::vector<Ingredient>::iterator end;
	std::string unit;
public:
	IngredientsListIterator(
		std::vector<Ingredient>::iterator it,
		std::vector<Ingredient>::iterator end,
		std::string unit
	);
	bool operator!=(const IngredientsListIterator& other) const;
	Ingredient& operator*() const;
	IngredientsListIterator& operator++();
};
class IngredientsList
{
private:
	std::vector<Ingredient> ingredients;
public:
	IngredientsList(std::vector<Ingredient> = std::vector<Ingredient>());
	std::vector<Ingredient> get_ingredients()const;
	Ingredient get_ingredient(unsigned int)const;
	unsigned int count_dish_weight()const;
	unsigned int count_number_of_ingredients()const;
	void add_ingredient(Ingredient&);
	void remove_ingredient(std::string);
	void save_to_file_nice_format(std::string)const;
	void save_to_file(std::string)const;
	void read_from_file(std::string);
	void operator-=(Ingredient&);
	void operator-=(std::string);
	IngredientsList operator+(IngredientsList);
	void operator+=(std::vector<Ingredient>&);
	void operator+=(IngredientsList&);
	void operator+=(Ingredient&);
	std::ostream& print_nice(std::ostream&, const IngredientsList&)const;
	friend std::ostream& operator<<(std::ostream&, const IngredientsList&);
	friend std::istream& operator>>(std::istream&, IngredientsList&);
	IngredientsListIterator begin(std::string);
	IngredientsListIterator end();
}; 