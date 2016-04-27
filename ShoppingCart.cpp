//
// Created by Jonathan Cahal on 4/14/16.
// Modified by Austin @ 10:51

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
	this->head = 0;
	this->nBooks = 0;
}

ShoppingCart::~ShoppingCart() {
	std::cout << "ShoppingCart Destroyed" << std::endl;
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

void ShoppingCart::removeBook(int id) {
	Book *node = this->head;

	if(node == NULL) {
		std::cout << "\nWARNING: Shopping cart empty. Cannot remove a book that doesn't exist. Returning to menu." << std::endl;
		std::cout <<   "=========================================================================================" << std::endl;
		return;
	}

	// check if head is the node to remove
	if(node->getID() == id) {
		this->head = node->getNext();
		this->nBooks--;
		return;
	}

	Book *prev = node; // make prev head
	node = node->getNext(); // move node past head

	while(node != NULL) {
		if(node->getID() == id) {
			prev->setNext(node->getNext());
			this->nBooks--;
			return;
		}

		prev = node;
		node = node->getNext();
	}

	std::cout << "\nWARNING: Book does not exist in shopping cart. Returning to menu." << std::endl; // if it gets this far, then it's not there
}

void ShoppingCart::print() {
	Book *book = this->head;
	Textbook *textbook;
	Magazine *magazine;
	Fiction *fiction;

	if(book == NULL) {
		std::cout << "\nShopping cart empty. Returning to menu." << std::endl;
		std::cout <<   "=======================================" << std::endl;
		return;
	}

	std::cout << "This shopping cart contains "<< this->nBooks << " books" << std::endl;
	while(book != NULL) {
		if(book->getID() == -1) { // if book has been removed from catalog
			std::cout << ANSI_COLOR_RED"This book has been removed from the catalog"ANSI_COLOR_RESET << std::endl;
			book = book->getNext(); // !don't forget to move the loop along before continuing
			continue;
		}
		std::cout << "Title: "<< book->getTitle() << std::endl;
		std::cout << "ID: " << book->getID() << std::endl;
		std::cout << "Price: $" << book->getPrice() << std::endl;
		std::cout << "In Stock: " << book->getInventory() << std::endl;

		switch(book->getCategory()) {
			case TEXTBOOK:
				textbook = (Textbook *)book;
				std::cout << "ISBN: " << textbook->getISBN() << std::endl;
				std::cout << "Author: " << textbook->getTextAuthor() << std::endl;
				break;
			case MAGAZINE:
				magazine = (Magazine *)book;
				std::cout << "Issue #: " << magazine->getIssue() << std::endl;
				break;
			case FICTION:
				fiction = (Fiction *)book;
				std::cout << "Author: " << fiction->getAuthor() << std::endl;
				break;
			default:
				break;
		}

		std::cout << std::endl;

		book = book->getNext();
	}

	char c;
	std::cout << "Press any key to continue: ";
	std::cin >> c;
}

void ShoppingCart::checkout() {
	double cost = 0.0;

	while(this->head != NULL) {
		cost += this->head->getPrice();
		this->head->setInventory(this->head->getInventory() - 1);
		this->removeBook(this->head->getID()); // this will make head point to head->getNext()
	}

	cost += cost * .09; // add 9% tax

	std::cout << "Total: " << cost << std::endl;
}