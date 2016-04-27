//
// Created by Jonathan Cahal on 4/27/16.
//

#ifndef P5_ITEM_H
#define P5_ITEM_H

#include "Book.h"

class Item {
private:
	Book *book;
	Item *next;

public:
	Item(Book *book);
	~Item();

	Book *getBook();
	Item *getNext();
	void setBook(Book *book);
	void setNext(Item *next);

};

#endif //P5_ITEM_H
