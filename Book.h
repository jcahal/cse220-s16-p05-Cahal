//
// Created by Jonathan Cahal on 4/14/16.
//

#ifndef P5_BOOK_H
#define P5_BOOK_H

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

public:
	// constructors
	Book(); // default
	Book(int bookID, Category category, const char title[], double price, int inventory); // parametrized constructor
	virtual ~Book(); // destructor

	int getID();
	Category getCategory();
	char *getTitle();
	double getPrice();
	int getInventory();
	Book *getNext();

	void setID(int bookID);
	void setCategory(Category category);
	void setTitle(char *title);
	void setPrice(float price);
	void setInventory(int inventory);
};

#endif //P5_BOOK_H
