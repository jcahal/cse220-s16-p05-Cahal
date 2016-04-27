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
#include "Item.h"
#include "ANSI_Colors.h"

class ShoppingCart {
private:
	int nItems;
	Item *head;

public:
	ShoppingCart();
	~ShoppingCart();
	void freeItems(Item *item);

	Item *getHead();
	int getNumItems();
	void setHead(Item *item);
	void setNumItems(int nItems);
	void insertItem(Item *item);
	void removeItem(int id);
	void print();
	void checkout();
};

#endif //P5_SHOPPINGCART_H
