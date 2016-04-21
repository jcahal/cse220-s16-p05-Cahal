//
// Created by Jonathan Cahal on 4/20/16.
//

#ifndef P5_DATA_H
#define P5_DATA_H

#include <iostream>
#include <fstream>

#include "Catalog.h"

using namespace std;

void readData(Catalog *pCatalog) {
	char catalog[255];

	cout << "Welcome to The Electronic Bookstore" << endl;
	cout << "Please provide a catalog file for import: ";

	cin >> catalog;

	ifstream ifCatalog(catalog);

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

			cout << "Import complete." << endl;
		}
	} else {
		cout << "File does not exist" << endl;
	}
}

void writeData() {

}

#endif //P5_DATA_H
