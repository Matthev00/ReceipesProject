#pragma once
#include <iostream>

class Ingredient
{
private:
	std::string name, unit;
	unsigned short amount;
public:
	Ingredient();
	Ingredient(std::string, short, std::string);
	std::string get_name() const;
	void set_name(std::string);
	unsigned short get_amount()const;
	void set_amount(short);
	std::string get_unit()const;
	void set_unit(std::string);
	unsigned short count_mass()const;
	std::string info()const;
	friend std::ostream& operator<<(std::ostream& output, const Ingredient& i);
	friend std::istream& operator>>(std::istream& input, Ingredient& i);
	bool operator==(Ingredient)const;
};