//
// Created by Jonathan Cahal on 4/14/16.
//

#ifndef P5_SHOPPINGCART_H
#define P5_SHOPPINGCART_H

#include <iostream>
#include "Book.h"
#include "Magazine.h"
#include "Textbook.h"
#include "Fiction.h"
#include "ANSI_Colors.h"

class ShoppingCart {
private:
	int nBooks;
	Book *head;

public:
	ShoppingCart();
	~ShoppingCart();

	Book *getHead();
	int getNumBooks();
	void setHead(Book *book);
	void setNumBooks(int nBooks);
	void insertBook(Book *book);
	void removeBook(int id);
	void print();
	void checkout();
};

#endif //P5_SHOPPINGCART_H
