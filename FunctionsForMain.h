//
// Created by Jonathan Cahal on 4/20/16.
//

#ifndef P5_DATA_H
#define P5_DATA_H

#include <iostream>
#include <fstream>

#include "Catalog.h"
#include "ShoppingCart.h"
#include "Book.h"
#include "Textbook.h"
#include "Magazine.h"
#include "Fiction.h"

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
	cout << "Please provide a catalog file for import, type q to return continue: ";

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

			Category category = BOOK;
			pCatalog->insertBook(new Book(id, title, price, inventory, category));
		}
	} else {
		cout << "File does not exist, exiting program..." << endl;
		return;
	}

	cout << "Import complete." << endl;

	char c;
	cout << "Press any key to continue: ";
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
	cout << "Press any key to continue: ";
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

//=====================================================================================
// function branching() - Process user input and branches program
//=====================================================================================
void branching(char c, Catalog *pCatalog, ShoppingCart *pShoppingCart) {		// branch to chosen function
	switch(c) {
		case 's':	recommendationsList(pCatalog);
			break;
		case 'c':	addToCatalog(pCatalog);
			break;
		case 'r':	removeFromCatalog(pCatalog);
			break;
		case 'a':	addToShoppingCart(pShoppingCart);
			break;
		case 'b':	checkOut(pShoppingCart);
			break;
		case 'i':	readData(pCatalog);
			break;
		case 'e':	writeData(pCatalog);
			break;
		case 'p':	pCatalog->print();
			break;
		case 'q':	cout << endl << "@Exiting the program..............." << endl;
			cin.get();	//type any key.
			break;
		default:	cout << endl << "@ERROR - Invalid input." << endl;
			cout << "@Try again....." << endl;
	}
}

//=====================================================================================
// function addToCatalog()
//=====================================================================================
void addToCatalog(Catalog *catalog){
	int bookID;
	char title[255];
	double price;
	int inventory;
	char bookType[50];
	Category category;

	char TextBookAuthor[50];
	int issue;
	int ISBN;
	char author[50];


	cout<<"ADDING A NEW BOOK TO THE CATALOG"<<endl;
	cout<<"================================"<<endl;
	cout<<"Note: Before adding a new book to the catalog, please look at what we already have..."<<endl;
	catalog->print();


	cout<<"Please enter the book ID: ";
	cin>>bookID;
	cout<<"Please enter the name of book: ";
	cin.ignore();
	cin.getline(title,255);
	cout<<"Please enter the price of the book: ";
	cin>>price;
	cout<<"Please enter how many are in stock: ";
	cin>>inventory;

	bool valid = false;
	do {
		cout << "Enter the Category of the book: Textbook, Fiction, Magazine, or Other: ";
		cin.getline(bookType, 50);

		if (strcmp(bookType, "Textbook") ==0) {
			category = TEXTBOOK;
			valid = true;
		}
		else if (strcmp(bookType, "Fiction") ==0) {
			category = FICTION;
			valid = true;
		}
		else if (strcmp(bookType, "Magazine") ==0) {
			category = MAGAZINE;
			valid = true;
		}
		else if (strcmp(bookType, "Other") ==0) {
			category = BOOK;
			valid = true;
		}
	} while(!valid);

	switch (category) {
		case TEXTBOOK: {
			cout<<"BookType is TEXTBOOK."<<endl;
			cout<<"Please enter textbook's ISBN number: "<<endl;
			cin>>ISBN;
			cout<<"Please enter the textbook's author: "<<endl;
			cin.getline(TextBookAuthor, 50);

			catalog->insertBook((Book *)(new Textbook(bookID, title, price, inventory, ISBN, TextBookAuthor, category)));
			break;
		}
		case BOOK: {
			cout<<"BookType is BOOK."<<endl;

			catalog->insertBook(new Book(bookID, title, price, inventory, category));
			break;
		}
		case FICTION: {
			cout<<"BookType is FICTION."<<endl;
			cout<<"Please enter name of author: "<<endl;
			cin.getline(author,50);

			catalog->insertBook((Book *)(new Fiction(bookID, title, price, inventory, author, category)));
			break;
		}
		case MAGAZINE: {
			cout<<"BookType is MAGAZINE."<<endl;
			cout<<"Please enter Magazine issue: "<<endl;
			cin>>issue;

			catalog->insertBook((Book *)(new Magazine(bookID, title, price, inventory, issue, category)));
			break;
		}
		default:
			break;
	}

}

void recommendationsList(Catalog *pCatalog) {
	Book *one, *two, *three;

	cout << pCatalog->getNumBooks() << endl;
	Book *b = pCatalog->getHead();
	one = b;
	two = b;
	three = b;

	while(b != NULL) {
		if(b->getInventory() > one->getInventory()) {
			one = b;
		}
		else if(b->getInventory() > two->getInventory()) {
			two = b;
		}
		else if(b->getInventory() > three->getInventory()) {
			three = b;
		}

		b = b->getNext();
	}

	cout<<"Our Recommendation List!"<<endl;
	cout<<one->getTitle()<<" Is our #1 Seller!"<<endl;
	cout<<two->getTitle()<<" Is our #2 Seller!"<<endl;
	cout<<three->getTitle()<<" Is our #3 Seller!"<<endl;

}

void removeFromCatalog(Catalog *pCatalog) {

}

void addToShoppingCart(ShoppingCart *pShoppingCart) {

}

void checkOut(ShoppingCart *pShoppingCart) {

}


#endif //P5_DATA_H