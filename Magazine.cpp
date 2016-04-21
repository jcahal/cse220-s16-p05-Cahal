//
// Created by MacBook Pro on 4/19/16.
//

#include "Magazine.h"

Magazine::Magazine() {
    this->Magazine(-1, NULL, 0.00, 1, 0, MAGAZINE);
}

Magazine::Magazine(int bookID, const char *title, double price, int inventory, int issue, Category category =MAGAZINE) {
    this->setID(bookID);
    this->setCategory(category);
    this->setTitle(title);
    this->setPrice(price);
    this->setInventory(inventory);
}


virtual Magazine::~Magazine(){
    std::cout << "Magazine destroyed" << endl;
}


int Magazine::getIssue() {return this->issue; }

void Magazine::setIssue(int issue) {this->issue = issue;};