//
// Created by MacBook Pro on 4/19/16.
//

#include "Magazine.h"

Magazine::Magazine() {
    Magazine(-1, NULL, 0.00, 1, 0, MAGAZINE);
}

Magazine::Magazine(int bookID, const char *title, double price, int inventory, int issue, Category category)
        : Book(bookID,title,price,inventory, category)
{
    this->setIssue(issue);
}


Magazine::~Magazine(){
    std::cout << "Magazine destroyed" << std::endl;
}


int Magazine::getIssue() {return this->issue; }

void Magazine::setIssue(int issue) {this->issue = issue;};