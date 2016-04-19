//
// Created by Jonathan Cahal on 4/14/16.
//

#include "Book.h"

// test
Book::Book() { 
	this->Book("Unknown", 0.00);
}

Book::Book(char *title, float price) {
	this->setTitle(title);
	this->setPrice(price);
}

char *Book::getTitle() {
	return this->title;
}

float Book::getPrice() {
	return this->price;
}

void Book::setTitle(char *title) {
	strcpy(this->title, title);
}

void Book::setPrice(float price) {
	this->price = price;
}