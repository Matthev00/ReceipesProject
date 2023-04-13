#pragma once
#include <iostream>

class DishWeight
{
private:
	std::string unit = "g";
	unsigned int amount;
public:
	DishWeight(unsigned int, std::string = "g");
	std::string get_unit()const;
	void set_unit(const std::string);
	unsigned int get_amount()const;
	void set_amount(const unsigned int);
	bool operator==(const DishWeight&)const;
};
