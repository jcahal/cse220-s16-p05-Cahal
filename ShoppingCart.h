//
// Created by Jonathan Cahal on 4/14/16.
//

#ifndef P5_SHOPPINGCART_H
#define P5_SHOPPINGCART_H

#include <iostream>
#include "Book.h"

class ShoppingCart {
private:
	int nBooks;
	Book *head;

public:
	ShoppingCart();
	~ShoppingCart();
	void freeBooks(Book *book);

	Book *getHead();
	int getNumBooks();
	void setHead(Book *book);
	void setNumBooks(int nBooks);
	void insertBook(Book *book);
	void print();
};

#endif //P5_SHOPPINGCART_H
