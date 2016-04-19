//
// Created by Jonathan Cahal on 4/14/16.
//

#ifndef P5_CATALOG_H
#define P5_CATALOG_H

#include "Book.h"

class Catalog {
private:
	static int nBooks;
	Book *head;

public:
	Catalog();
	
	void insertBook(Book book);
};

#endif //P5_CATALOG_H
