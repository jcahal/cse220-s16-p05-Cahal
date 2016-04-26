//
// Created by Jonathan Cahal on 4/20/16.
//

#ifndef P5_DATA_H
#define P5_DATA_H

#include <iostream>
#include <fstream>

#include "Catalog.h"
#include "ShoppingCart.h"

using namespace std;

void recommendationsList(Catalog *pCatalog);
void addToCatalog(Catalog *pCatalog);
void removeFromCatalog(Catalog *pCatalog);
void addToShoppingCart(ShoppingCart *pShoppingCart);
void checkOut(ShoppingCart *pShoppingCart);
void readData(Catalog *pCatalog);
void writeData(Catalog *pCatalog);

//=====================================================================================
// function readData() - This function imports a book file into a catalog
//=====================================================================================
void readData(Catalog *pCatalog) {
	char fName[255];

	cout << endl << endl << "IMPORT FILE" << endl;
	cout << "Please provide a catalog file for import, type q to return to the main menu: ";

	cin >> fName;

	if(fName[0] == 'n')
		return;

	ifstream ifCatalog(fName);

	if(ifCatalog.is_open()) {
		while(!ifCatalog.eof()) {
			char title[255];
			int id;
			double price;
			int inventory;

			ifCatalog.getline(title, 255);
			ifCatalog >> id;
			ifCatalog.ignore(2);
			ifCatalog >> price;
			ifCatalog >> inventory;

			ifCatalog.ignore();
			ifCatalog.ignore(255, '\n'); // for line space between books

			pCatalog->insertBook(new Book(id, title, price, inventory));
		}
	} else {
		cout << "File does not exist, exiting program..." << endl;
		return;
	}

	cout << "Import complete." << endl;

	char c;
	cout << "Press any key to return to the main menu: ";
	cin >> c;
}

//=====================================================================================
// function writeData() - This function exports a catalog to a book file
//=====================================================================================
void writeData(Catalog *pCatalog) {
	char fName[255];

	cout << "Enter an export file name: ";

	cin >> fName;

	ofstream ofCatalog(fName);

	if(ofCatalog.is_open()) {
		Book *book = pCatalog->getHead();
		while(book->getNext() != NULL) {
			ofCatalog << book->getTitle() << endl;
			ofCatalog << book->getID() << endl;
			ofCatalog << "$" << book->getPrice() << endl;
			ofCatalog << book->getInventory() << endl;
			ofCatalog << endl;
		}

	} else {
		cout << "Error opening file, exiting program..." << endl;
		return;
	}

	cout << "Export complete." << endl;

	char c;
	cout << "Press any key to return to the main menu: ";
	cin >> c;

}

//=====================================================================================
// function menu() - Simply prints out menu options
//=====================================================================================
void menu() {
	cout <<	endl << endl << "MENU" << endl;
	cout << "----" << endl;
	cout << "s: See our Recommendations!" << endl;
	cout << "c: Add a book to the catalog." << endl;
	cout << "r: Remove a book from the catalog." << endl;
	cout << "a: Add books to the shopping cart." << endl;
	cout << "b: Proceed to check out."<<endl;
	cout << "i: Import a book file." << endl;
	cout << "e: Export a book file." << endl;
	cout << "p: Display the catalog." << endl;
	cout << "q: Exit the store." << endl;
	cout << endl << "Please enter your choice (s, c, r, a, b, i, e, p, q) --> ";
}



#endif //P5_DATA_H