//
// Created by Jonathan Cahal on 4/14/16.
//

#include "Catalog.h"

Catalog::Catalog() {
	this->head = 0;
	this->nBooks = 0;
}

Catalog::~Catalog() {
	freeBooks(this->head);
	std::cout << "Catalog Destroyed" << std::endl;
}

void Catalog::freeBooks(Book *book) {
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
		book->setNext(this->head);
		this->head = book;
	}
	this->nBooks++;
}

void Catalog::print() {
	Book *book = this->head;

	if(book == NULL) {
		std::cout << "Catalog Empty" << std::endl;
		return;
	}

	std::cout << "This catalog contains "<< this->nBooks << " books" << std::endl;
	while(book->getNext() != NULL) {
		std::cout << book->getTitle() << " { " << std::endl;
		std::cout << "\tID: " << book->getID() << "," << std::endl;
		std::cout << "\tPrice: $" << book->getPrice() << "," << std::endl;
		std::cout << "\tInventory: " << book->getInventory() << "," << std::endl;
		std::cout << "}" << std::endl;

		book = book->getNext();
	}
}