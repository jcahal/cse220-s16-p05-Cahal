#include <iostream>

#include "includes.h"

using namespace std;

//=====================================================================================
// function main()
//=====================================================================================
int main() {

	/*
	 * I left the block below because it is an interesting show of how memory works.
	 *
	 * If you run the program you will see on the first cout to foo->getID is 65.
	 * Then the object foo points to is deleted.
	 * But then when you call foo->getID again it still comes back 64!?
	 *
	 * This is because even though the object was deleted (the memory was given back for use elsewhere)
	 * the data was not changed. So, when you go to that data and interpret as an int it shows 65.
	 *
	 * And then just for fun cast it as a char and you get a 'A' which in ASCII is 65,
	 * or 0100001 in 8 bit(1 byte) binary :)
	 *
	 * This all boils down to us needing to set a Books id to some special value (lets say -1) on removal
	 * from the Catalog just in case the book is still in the shopping cart, so we can ignore it on print()
	 * and checkout()
	 */

	Book *b = new Book(65, "Foo Bar", 6.75, 8, BOOK);
	Book *foo = b;
	cout << foo->getID() << endl;
	delete b;
	cout << foo->getID() << endl;
	cout << (char)foo->getID() << endl;


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
