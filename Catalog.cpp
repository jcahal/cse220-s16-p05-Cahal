//
// Created by Jonathan Cahal on 4/14/16.
//

#include "Catalog.h"

Catalog::Catalog() {
	this->head = 0;
	this->nBooks = 0;
}

Catalog::~Catalog() {
	freeBooks();
}

void Catalog::freeBooks(Book *book = this->head) {
	if(book == 0) {
		return;
	}
	freeBooks(book->getNext());
	delete book;
}

void Catalog::insertBook(Book *book) {
	if(this->head == 0) {
		this->head = book;
	} else {
		book->getNext() = this->head;
		this->head = book;
	}
	this->nBooks++;
}

void Catalog::printBooks(Book *book = this->head) {
	std::cout << this->nBooks << " Total" << std::endl;
	while(book->getNext() != 0) {
		std::cout << "Title: " << book->getTitle() <<
	}
}