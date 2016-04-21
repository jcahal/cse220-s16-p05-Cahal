//
// Created by MacBook Pro on 4/21/16.
//

#include "Fiction.h"

Fiction::Fiction() {
    Fiction(-1, NULL, 0.00, 1, NULL, FICTION);
}

Fiction::Fiction(int bookID, const char *title, double price, int inventory, char *author, Category category) {
    this->setID(bookID);
    this->setTitle(title);
    this->setPrice(price);
    this->setInventory(inventory);
    this->setAuthor(author);
    this->setCategory(category);

}

virtual Fiction::~Fiction(){
    std::cout << "Fiction book destroyed" <<std::endl;
}

char *Fiction::getAuthor() {return this->author; }

void Fiction::setAuthor(char *author) {strcpy(this->author,author); }