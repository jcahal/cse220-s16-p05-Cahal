//
// Created by Jonathan Cahal on 4/14/16.
// Modified by Austin @ 10:51

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
	this->head = 0;
	this->nBooks = 0;
}

ShoppingCart::~ShoppingCart() {
	freeBooks(this->head);
	std::cout << "ShoppingCart Destroyed" << std::endl;
}

void ShoppingCart::freeBooks(Book *book) {
	if(book == 0) {
		return;
	}
	freeBooks(book->getNext());
	delete book;
}

Book *ShoppingCart::getHead() {
	return this->getHead();
}

int ShoppingCart::getNumBooks() {
	return this->nBooks;
}

void ShoppingCart::setHead(Book *book) {
	this->head = book;
}

void ShoppingCart::setNumBooks(int nBooks) {
	this->nBooks = nBooks;
}

void ShoppingCart::insertBook(Book *book) {
	if(this->head == 0) {
		this->head = book;
	} else {
		book->setNext(this->head);
		this->head = book;
	}
	this->nBooks++;
}

void ShoppingCart::print() {
	Book *book = this->head;

	if(book == NULL) {
		std::cout << "Shopping cart Empty" << std::endl;
		return;
	}

	std::cout << "This shopping cart contains "<< this->nBooks << " books" << std::endl;
	while(book->getNext() != NULL) {
		std::cout << book->getTitle() << " { " << std::endl;
		std::cout << "\tID: " << book->getID() << "," << std::endl;
		std::cout << "\tPrice: $" << book->getPrice() << "," << std::endl;
		std::cout << "\tInventory: " << book->getInventory() << "," << std::endl;
		std::cout << "}" << std::endl;

		book = book->getNext();
	}
}