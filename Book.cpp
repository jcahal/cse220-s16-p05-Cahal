//
// Created by Jonathan Cahal on 4/14/16.
//

#include "Book.h"

Book::Book() {
	this->Book(-1, NULL, 0.00, 1, BOOK);
}

Book::Book(int bookID, const char title[], double price, int inventory, Category category = BOOK) {
	this->setID(bookID);
	this->setCategory(category);
	this->setTitle(title);
	this->setPrice(price);
	this->setInventory(inventory);
	this->next = 0;
}

virtual Book::~Book() {
	std::cout << "Book destroyed" << endl;
}

int Book::getID() {
	return this->bookID;
}

Category Book::getCategory() {
	return this->bookCategory;
}

char *Book::getTitle() {
	return this->title;
}

double Book::getPrice() {
	return this->price;
}

int Book::getInventory() {
	return this->inventory;
}

Book *Book::getNext() {
	return this->next;
}

void Book::setID(int bookID) {
	this->bookID = bookID;
}

void Book::setCategory(Category category) {
	this->bookCategory = category;
}

void Book::setTitle(const char *title) {
	strcpy(this->title, title);
}

void Book::setPrice(float price) {
	this->price = price;
}

void Book::setInventory(int inventory) {
	this->inventory = inventory;
}