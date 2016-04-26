//
// Created by MacBook Pro on 4/21/16.
//

#include "Fiction.h"

Fiction::Fiction() {
    Fiction(-1, NULL, 0.00, 1, NULL, FICTION);
}

Fiction::Fiction(int bookID, const char *title, double price, int inventory, char *author, Category category)
    : Book(bookID,title,price,inventory, category)
    {
        this->setAuthor(author);
    }

Fiction::~Fiction(){
    std::cout << "Fiction book destroyed" <<std::endl;
}

char *Fiction::getAuthor() {return this->author; }

void Fiction::setAuthor(char *author) {strcpy(this->author,author); }