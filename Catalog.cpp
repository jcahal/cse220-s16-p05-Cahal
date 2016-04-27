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
	std::cout << ANSI_COLOR_RED"Catalog Destroyed"ANSI_COLOR_RESET << std::endl;
}

void Catalog::freeBooks(Book *book) {
	if(book == 0) {
		return;
	}
	freeBooks(book->getNext());
	delete book;
}

Book *Catalog::getHead() {
	return head;
}

int Catalog::getNumBooks() {
	return this->nBooks;
}

void Catalog::setHead(Book *book) {
	this->head = book;
}

void Catalog::setNumBooks(int nBooks) {
	this->nBooks = nBooks;
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

void Catalog::removeBook(int id) {
	Book *node = this->head;

	if(node == NULL) {
		std::cout << "Cannot remove, catalog Empty" << std::endl;
		return;
	}

	// check if head is the node to remove
	if(node->getID() == id) {
		this->head = node->getNext();
		node->setID(-1); // for checking in shopping cart
		delete node;
		this->nBooks--;
		return;
	}

	Book *prev = node; // make prev head
	node = node->getNext(); // move node past head

	while(node != NULL) {
		if(node->getID() == id) {
			prev->setNext(node->getNext());
			node->setID(-1); // for checking in shopping cart
			delete node;
			this->nBooks--;
			return;
		}

		prev = node;
		node = node->getNext();
	}

	std::cout << "Book does not exist" << std::endl; // if it gets this far, then it's not there
}

void Catalog::print() {
	Book *book = this->head;
	Textbook *textbook;
	Magazine *magazine;
	Fiction *fiction;

	if(book == NULL) {
		std::cout << "Cannot print, catalog Empty" << std::endl;
		return;
	}

	std::cout << "This catalog contains "<< this->nBooks << " books" << std::endl;
	while(book != NULL) {
		std::cout << book->getTitle() << std::endl;
		std::cout << book->getID() << std::endl;
		std::cout << book->getPrice() << std::endl;
		std::cout << book->getInventory() << std::endl;

		switch(book->getCategory()) {
			case TEXTBOOK:
				textbook = (Textbook *)book;
				std::cout << textbook->getISBN() << std::endl;
				break;
			case MAGAZINE:
				magazine = (Magazine *)book;
				std::cout << magazine->getIssue() << std::endl;
				break;
			case FICTION:
				fiction = (Fiction *)book;
				std::cout << fiction->getAuthor() << std::endl;
				break;
			default:
				break;
		}

		std::cout << std::endl; // line break between books

		book = book->getNext();
	}

	char c;
	std::cout << "Press any key to continue: ";
	std::cin >> c;
}

// searches catalog for a book, returns NULL if book not found
Book *Catalog::search(int bookID) {
	Book *book = this->getHead();

	while(book != NULL) {
		if(book->getID() == bookID)
			break;
		book = book->getNext();
	}

	return book;
}