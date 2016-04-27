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
void removeFromShoppingCart(ShoppingCart *pShoppingCart);
void addToShoppingCart(ShoppingCart *pShoppingCart, Catalog *pCatalog);
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
	cout << "a: Add books to the shopping cart." << endl;
	cout << "r: Remove a book from the catalog." << endl;
	cout << "x: Remove a book from the shopping cart." << endl;
	cout << "b: Proceed to check out."<<endl;
	cout << "i: Import a book file." << endl;
	cout << "e: Export a book file." << endl;
	cout << "p: Display the catalog." << endl;
	cout << "d: Display the shopping cart." << endl;
	cout << "$: to checkout" << endl;
	cout << "q: Exit the store." << endl;
	cout << endl << "Please enter your choice (s, c, r, a, b, i, e, p, d, $, q) --> ";
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
		case 'a':	addToShoppingCart(pShoppingCart, pCatalog);
			break;
		case 'r':	removeFromCatalog(pCatalog);
			break;
		case 'x':	removeFromShoppingCart(pShoppingCart);
			break;
		case 'b':	checkOut(pShoppingCart);
			break;
		case 'i':	readData(pCatalog);
			break;
		case 'e':	writeData(pCatalog);
			break;
		case 'p':	pCatalog->print();
			break;
		case 'd':	pShoppingCart->print();
			break;
		case '$':	pShoppingCart->checkout();
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
	char x;
	bool error =false;

	cout<<"\nADDING A NEW BOOK TO THE CATALOG"<<endl;
	cout<<"================================"<<endl;
	cout<<"Note: Before adding a new book to the catalog, would you like to see what we have already? (Y/N)"<<endl;
	cin>>x;
	x = tolower(x);
		switch (x) {
			case 'y':
				catalog->print();
				break;
			case 'n':
				break;
			default:
				cout << endl << "ERROR - Invalid input." << endl;
		}

	cout<<"Please enter the book ID: ";
	cin.ignore();
	cin>>bookID;
	cout<<"Please enter the name of book: ";
	cin.ignore();
	cin.getline(title,255);
	cout<<"Please enter the price of the book: ";
	cin>>price;
	cout<<"Please enter how many are in stock: ";
	cin>>inventory;

	bool valid = false;
	cout << "Enter the Category of the book: Textbook, Fiction, Magazine, or Other: ";
	do {

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
			cout<<"Attempting to add a textbook."<<endl;
			cout<<"Please enter textbook's ISBN number: "<<endl;
			cin>>ISBN;
			cout<<"Please enter the textbook's author: "<<endl;
			cin.getline(TextBookAuthor, 50);

			catalog->insertBook((Book *)(new Textbook(bookID, title, price, inventory, ISBN, TextBookAuthor, category)));
			cout<<"New textbook was added to the catalog."<<endl;
			break;
		}
		case BOOK: {
			cout<<"Attempting to add a book."<<endl;

			catalog->insertBook(new Book(bookID, title, price, inventory, category));
			cout<<"New book was added to the catalog."<<endl;
			break;
		}
		case FICTION: {
			cout<<"Attempting to add a fiction novel."<<endl;
			cout<<"Please enter name of author: "<<endl;
			cin.getline(author,50);

			catalog->insertBook((Book *)(new Fiction(bookID, title, price, inventory, author, category)));
			cout<<"New fiction novel was added to the catalog."<<endl;
			break;
		}
		case MAGAZINE: {
			cout<<"Attempting to add a magazine."<<endl;
			cout<<"Please enter Magazine issue: "<<endl;
			cin>>issue;

			catalog->insertBook((Book *)(new Magazine(bookID, title, price, inventory, issue, category)));
			cout<<"New magazine was added to the catalog."<<endl;
			break;
		}
		default:
			break;
	}

}

//=====================================================================================
// function recommendationsList()
//=====================================================================================
void recommendationsList(Catalog *pCatalog) {

	Book *b = pCatalog->getHead();

	if (b==0){
		cout<<"Empty Catalog."<<endl;

		char c;
		cout << "Press any key to continue: "<<endl;
		cin >> c;
		return;
	}

	int one = 0;
	int two = 0;
	int three = 0;
	char OneTitle[255];
	char TwoTitle[255];
	char ThreeTitle[255];

	while(b != NULL) {
		if(b->getInventory() > one) {
			three = two;
			strcpy(ThreeTitle, TwoTitle);
			two = one;
			strcpy(TwoTitle, OneTitle);
			one = (int)b->getInventory();
			strcpy(OneTitle, b->getTitle());
		}
		else if(b->getInventory() > two) {
			three = two;
			strcpy(ThreeTitle, TwoTitle);
			two = (int)b->getInventory();
			strcpy(TwoTitle,b->getTitle());
		}
		else if(b->getInventory() > three) {
			three = (int) b->getInventory();
			strcpy(ThreeTitle,b->getTitle());
		}
		b = b->getNext();
	}

		cout << "\n========================" << endl;
		cout << "OUR RECOMMENDATION LIST!" << endl;
		cout << "========================" << endl;
		cout << OneTitle << " is our #1 seller! " << endl;
		cout << TwoTitle << " is our #2 seller! " << endl;
		cout << ThreeTitle << " is our #3 seller! " << endl;

	char c;
	cout << "Press any key to continue: ";
	cin >> c;

}

void removeFromCatalog(Catalog *pCatalog) {
	int id;
	cout << "\n============================="  <<endl;
	cout<<    "REMOVE FROM CATALOG"<<endl;
	cout <<   "============================="  <<endl;

	cout<<"\nTo remove a book from our current catalog, please enter the item's ID as found in the catalog: ";
	cin.ignore();
	cin>>id;

	pCatalog->removeBook(id);

}

void removeFromShoppingCart(ShoppingCart *pShoppingCart) {
	int id;
	cout << "\n============================="  <<endl;
	cout<<    "REMOVE FROM SHOPPING CART"<<endl;
	cout <<   "============================="  <<endl;

	cout<<"\nTo remove a book from your current shopping cart, please enter the item's ID: ";
	cin.ignore();
	cin>>id;

	pShoppingCart->removeBook(id);

}

void addToShoppingCart(ShoppingCart *pShoppingCart, Catalog *pCatalog) {
	int id;
	cout << "\n============================="  <<endl;
	cout<<    "WELCOME TO YOUR SHOPPING CART"<<endl;
	cout <<   "============================="  <<endl;
	cout<<"If you have not already looked at our Top 3 Recommendations, consider taking one of them home! "<<endl;

	recommendationsList(pCatalog);

	cout<<"\nTo purchase from our current catalog, please enter the item's ID of the desired purchase as found in the catalog: ";
	//pCatalog->print();
	cin.ignore();
	cin>>id;
	//cin.ignore();

	Book *b = pCatalog->search(id);

	pShoppingCart->insertBook(b);
}

void checkOut(ShoppingCart *pShoppingCart) {
	pShoppingCart->print();
}


#endif //P5_DATA_H