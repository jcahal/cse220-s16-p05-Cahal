//
// Created by Jonathan Cahal on 4/14/16.
//

#ifndef P5_SHOPPINGCART_H
#define P5_SHOPPINGCART_H

#include "Book.h"

class ShoppingCart {
private:
	Book *books;
	int nBooks;

public:
	ShoppingCart();

	void insertBook();
};

#endif //P5_SHOPPINGCART_H
