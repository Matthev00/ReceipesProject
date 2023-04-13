#include "DishWeight.h"

DishWeight::DishWeight(unsigned int amount, std::string unit)
{
    DishWeight::unit = unit;
    DishWeight::amount = amount;
}

std::string DishWeight::get_unit() const
{
    return unit;
}

void DishWeight::set_unit(const std::string unit)
{
    DishWeight::unit = unit;
}

unsigned int DishWeight::get_amount() const
{
    return amount;
}

void DishWeight::set_amount(const unsigned int amount)
{
    DishWeight::amount = amount;
}

bool DishWeight::operator==(const DishWeight& dw) const
{
    if (amount == dw.amount && unit == dw.get_unit()) {
        return true;
    }
    return false;
}
