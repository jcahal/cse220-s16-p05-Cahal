//
// Created by Jonathan Cahal on 4/14/16.
//

#ifndef P5_CATALOG_H
#define P5_CATALOG_H

#include <iostream>
#include "Book.h"

class Catalog {
private:
	int nBooks;
	Book *head;

public:
	Catalog();
	~Catalog();
	void freeBooks(Book *book);
	
	void insertBook(Book *book);
	void print();
};

#endif //P5_CATALOG_H
