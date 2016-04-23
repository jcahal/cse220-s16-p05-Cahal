//
// Created by Jonathan Cahal on 4/14/16.
//

#ifndef P5_CATALOG_H
#define P5_CATALOG_H

#include <iostream>
#include "Book.h"
#include "ANSI_Colors.h"

class Catalog {
private:
	int nBooks;
	Book *head;

public:
	Catalog();
	~Catalog();
	void freeBooks(Book *book);

	Book *getHead();
	int getNumBooks();
	void setHead(Book *book);
	void setNumBooks(int nBooks);
	void insertBook(Book *book);
	void removeBook(int id);
	void print();
};

#endif //P5_CATALOG_H
