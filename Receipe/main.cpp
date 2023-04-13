#include <iostream>
#include "Ingredient.h"
#include "Receipe.h"
#include "IngredientsList.h"
#include "DishWeight.h"
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

int main(int ac, char *av[])
{
	//Przyk³ad U¿ycia iteratora w for zakresowy
	Ingredient i1(std::string("salt"), 15, std::string("g"));
	Ingredient i2(std::string("milk"), 50, std::string("ml"));
	Ingredient i3(std::string("suger"), 15, std::string("g"));
	vector<Ingredient> ingredients;
	ingredients.push_back(i1);
	IngredientsList ingredient_list(ingredients);
	ingredient_list += i2;
	ingredient_list += i3;
	ingredient_list.set_iterator_unit("ml");
	for (auto& ingredient : ingredient_list)
	{
		cout << ingredient.get_name() << endl;
	}
	cout << "-----------------------------------------" << endl;
	short n;
	vector<Receipe> receipes = vector<Receipe>();
	if (ac == 3) {
		fstream in, out;
		in.open(string(av[1]), ios::in);
		out.open(string(av[2]), ios::out);
		in >> n;
		if (n < 1) {
			return 0;
		}
		for (short i = 0; i < n; ++i) {
			Receipe receipe;
			try {
				in >> receipe;
			}
			catch (const char* x) {
				cout << "Message: " << x << endl;
			}
			receipes.push_back(receipe);
		}

		out << n << '\n';
		for (short i = 0; i < receipes.size(); ++i) {
			out << receipes[i] << endl;
		}
		in.close();
		out.close();
	}
	else {
		cout << "Amount of receipes:\n";
		cin >> n;
		if (n < 1) {
			return 0;
		}
		for (short i = 0; i < n; ++i) {
			Receipe receipe;
			try {
				cin >> receipe;
			}
			catch (const char* x) {
				cout << "Message: " << x << endl;
			}
			receipes.push_back(receipe);
		}
		cout << "-------------------------------" << endl;
		for (short i = 0; i < receipes.size(); ++i) {
			cout << receipes[i] << endl;
		}
	}
}
