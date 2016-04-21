//
// Created by Jonathan Cahal on 4/14/16.
//

#ifndef P5_CATALOG_H
#define P5_CATALOG_H

#include <iostream>

#include "Book.h"

class Catalog {
private:
	static int nBooks;
	Book *head;

public:
	Catalog();
	~Catalog();
	void freeBooks(Book *book = this->head);
	
	void insertBook(Book *book);
	void printBooks(Book *book = this->head);
};

#endif //P5_CATALOG_H
