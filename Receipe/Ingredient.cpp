#include "Ingredient.h"
#include <string>
#include <iostream>
using namespace std;

Ingredient::Ingredient()
{
}

Ingredient::Ingredient(string name,short amount, string unit)
{
	Ingredient::name = name;
	if (amount < 1) {
		throw "Amount has to be over 1.";
	}
	Ingredient::amount = amount;
	if (unit == "g" || unit == "ml" || unit == "spoons" || unit == "pieces") {
		Ingredient::unit = unit;
	}
	else {
		throw "Invalid unit!";
	}
}

string Ingredient::get_name() const
{
	return name;
}

void Ingredient::set_name(string new_name)
{
	name = new_name;
}


unsigned short Ingredient::get_amount() const
{
	return amount;
}

void Ingredient::set_amount(short new_amount)
{
	if (new_amount < 1) {
		throw "Amount has to be over 1.";
	}
	amount = new_amount;
}

string Ingredient::get_unit() const
{
	return unit;
}

void Ingredient::set_unit(string unit)
{
	if (unit == "g" || unit == "ml" || unit == "spoons" ||
		unit == "pieces" || unit== "spoon" || unit=="piece") {
		Ingredient::unit = unit;
	}
	else {
		throw "Invalid unit!";
	}
}

unsigned short Ingredient::count_mass() const
{
	if (unit == "g" || unit=="ml") {
		return amount;
	}
	else if (unit == "pieces" || unit == "piece") {
		return amount * 100;
	}
	else{
		return amount * 15;
	}
}

string Ingredient::info() const
{
	string info = to_string(amount) + " " + unit + " of " + name +'\n';
	return info;
}

bool Ingredient::operator==(Ingredient i)const
{
	if (name == i.name &&
		unit == i.unit &&
		amount == i.amount) return true;
	return false;
}

ostream& operator<<(ostream& output, const Ingredient& i)
{
	output << i.name << " " << i.amount << " " << i.unit << "\n";
	return output;
}

istream& operator>>(istream& input, Ingredient& i)
{
	string i_name, i_unit;
	short i_amount;
	input >> i_name >> i_amount >> i_unit;
	i.set_name(i_name);
	i.set_amount(i_amount);
	i.set_unit(i_unit);
	return input;
}
