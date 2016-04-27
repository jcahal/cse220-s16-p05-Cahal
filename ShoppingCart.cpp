//
// Created by Jonathan Cahal on 4/14/16.
// Modified by Austin @ 10:51

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() {
	this->head = 0;
	this->nItems = 0;
}

ShoppingCart::~ShoppingCart() {
	freeItems(this->head);
	std::cout << "ShoppingCart Destroyed" << std::endl;
}

void ShoppingCart::freeItems(Item *item) {
	while(item != NULL) {
		freeItems(item->getNext());
	}
	delete item;
}

Item *ShoppingCart::getHead() {
	return this->getHead();
}

int ShoppingCart::getNumItems() {
	return this->nItems;
}

void ShoppingCart::setHead(Item *item) {
	this->head = item;
}

void ShoppingCart::setNumItems(int nItems) {
	this->nItems = nItems;
}

void ShoppingCart::insertItem(Item *item) {
	if(this->head == 0) {
		this->head = item;
	} else {
		item->setNext(this->head);
		this->head = item;
	}
	this->nItems++;
}

void ShoppingCart::removeItem(int id) {
	Item *node = this->head;

	if(node == NULL) {
		std::cout << "\nWARNING: Shopping cart empty. Cannot remove a book that doesn't exist. Returning to menu." << std::endl;
		std::cout <<   "=========================================================================================" << std::endl;
		return;
	}

	// check if head is the node to remove
	if(node->getBook()->getID() == id) {
		this->head = node->getNext();
		delete node;
		this->nItems--;
		return;
	}

	Item *prev = node; // make prev head
	node = node->getNext(); // move node past head

	while(node != NULL) {
		if(node->getBook()->getID() == id) {
			prev->setNext(node->getNext());
			delete node;
			this->nItems--;
			return;
		}

		prev = node;
		node = node->getNext();
	}

	std::cout << "\nWARNING: Book does not exist in shopping cart. Returning to menu." << std::endl; // if it gets this far, then it's not there
}

void ShoppingCart::print() {
	Item *item = this->head;
	Textbook *textbook;
	Magazine *magazine;
	Fiction *fiction;

	if(item == NULL) {
		std::cout << "\nShopping cart empty. Returning to menu." << std::endl;
		std::cout <<   "=======================================" << std::endl;
		return;
	}

	std::cout << "This shopping cart contains "<< this->nItems << " books" << std::endl;
	while(item != NULL) {
		Book *book = item->getBook();

		// this stuff didn't seem to work 100%. It skips the book but doesn't print the msg
		if(book->getPrice() < 0) { // if book has been removed from catalog
			std::cout << ANSI_COLOR_RED"This book has been removed from the catalog"ANSI_COLOR_RESET << std::endl;
			item = item->getNext(); // !don't forget to move the loop along before continuing
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

		item = item->getNext();
	}

	char c;
	std::cout << "Press any key to continue: ";
	std::cin >> c;
}

void ShoppingCart::checkout() {
	double cost = 0.0;

	while(this->head != NULL) {
		cost += this->head->getBook()->getPrice();
		this->head->getBook()->setInventory(this->head->getBook()->getInventory() - 1);
		this->removeItem(this->head->getBook()->getID()); // this will make head point to head->getNext()
	}

	cost += cost * .09; // add 9% tax

	std::cout << "Total: " << cost << std::endl;
}