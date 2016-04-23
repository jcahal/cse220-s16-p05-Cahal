#include <iostream>

#include "includes.h"

using namespace std;

int main(int argc, char *argv[]) {

	Catalog *catalog = new Catalog();
	ShoppingCart *shoppingCart = new ShoppingCart();

	cout << endl << "Welcome to The Electronic Bookstore" << endl;

	char input;

	do {
		menu();

		cin >> input;

		branching(input, catalog, shoppingCart);

	} while(input != 'q');

	catalog->print();

	delete shoppingCart;
	delete catalog;

	return 0;
}