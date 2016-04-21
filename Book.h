//
// Created by Jonathan Cahal on 4/14/16.
//

#ifndef P5_BOOK_H
#define P5_BOOK_H

#include <iostream>
#include <cstring>

typedef enum {
	BOOK,
	MAGAZINE,
	FICTION,
	TEXTBOOK
} Category;

class Book {
private:
	int bookID;
	Category bookCategory;
	char title[255];
	double price;
	int inventory;
	Book *next;

protected:

public:
	// constructors
	Book(); // default
	Book(int bookID, const char title[], double price, int inventory, Category category = BOOK); // parametrized constructor
	virtual ~Book(); // destructor
										//Should change title[] to "const char *title" ??
	int getID();
	Category getCategory(); //I might have done these wrong, as they would go in the
	char *getTitle();		  // in the book.cpp file correct? (The return statements)
	double getPrice();
	int getInventory();
	Book *getNext();

	void setID(int bookID);
	void setCategory(Category category);
	void setTitle(const char *title); //Notice the const char *title... is this correct?
	void setPrice(double price);
	void setInventory(int inventory);
};

#endif //P5_BOOK_H
