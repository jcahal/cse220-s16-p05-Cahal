#include <iostream>

#include "includes.h"

using namespace std;

//=====================================================================================
// function main()
//=====================================================================================
int main() {
	//Call the catalog which will bring us to import a file to start the program
	Catalog *catalog = new Catalog();
	ShoppingCart *pShoppingCart = new ShoppingCart();
	cout << endl << "Welcome to The Electronic Bookstore" << endl;

	char ch;
	do {
		menu();				// display choices
		cin >> ch;			// enter a choice from the keyboard
		ch = tolower(ch);	// convert to lower case
		branching(ch, catalog, pShoppingCart);		// branch to the chosen function
	}
	while (ch != 'q');			// 'q' for quit

	//catalog->print();
	delete pShoppingCart;
	delete catalog;

	return 0;
}
