#include <iostream>
#include "Ingredient.h"
#include "Receipe.h"
#include "IngredientsList.h"
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

int main(int ac, char *av[])
{
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
