//
// Created by Jonathan Cahal on 4/27/16.
//

#include "Item.h"

Item::Item(Book *book) {
	this->book = book;
	this->next = 0;
}

Item::~Item() {
	std::cout << "Item destroyed" << std::endl;
}

Book *Item::getBook() {
	return this->book;
}

Item *Item::getNext() {
	return this->next;
}

void Item::setBook(Book *book) {
	this->book = book;
}

void Item::setNext(Item *next) {
	this->next = next;
}