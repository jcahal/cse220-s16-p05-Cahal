//
// Created by Jonathan Cahal on 4/14/16.
//

#ifndef P5_BOOK_H
#define P5_BOOK_H

#include <string.h>

class Book {
private:
	char *title;
	float price;

public:
	Book();
	Book(char *title, float price);

	char *getTitle();
	float getPrice();
	void setTitle(char *title);
	void setPrice(float price);
};

#endif //P5_BOOK_H
