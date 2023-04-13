#pragma once
#include "Ingredient.h"
#include <iostream>
#include <vector>
#include "DishWeight.h"


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
	std::string iterator_unit = "g";
public:
	IngredientsList(std::vector<Ingredient> = std::vector<Ingredient>());
	std::string get_iterator_unit()const;
	void set_iterator_unit(const std::string&);
	std::vector<Ingredient> get_ingredients()const;
	Ingredient get_ingredient(unsigned int)const;
	DishWeight count_dish_weight()const;
	unsigned int count_number_of_ingredients()const;
	void add_ingredient(const Ingredient&);
	void remove_ingredient(const std::string);
	void save_to_file_nice_format(const std::string)const;
	void save_to_file(const std::string)const;
	void read_from_file(const std::string);
	void operator-=(const Ingredient&);
	void operator-=(const std::string&);
	IngredientsList operator+(const IngredientsList);
	void operator+=(const std::vector<Ingredient>&);
	void operator+=(const IngredientsList&);
	void operator+=(const Ingredient&);
	std::ostream& print_nice(std::ostream&, const IngredientsList&)const;
	friend std::ostream& operator<<(std::ostream&, const IngredientsList&);
	friend std::istream& operator>>(std::istream&, IngredientsList&);
	IngredientsListIterator begin(const std::string&);
	IngredientsListIterator end();
	IngredientsListIterator begin();
};