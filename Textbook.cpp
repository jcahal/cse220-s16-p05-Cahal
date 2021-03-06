//
// Created by MacBook Pro on 4/25/16.
//

#include "Textbook.h"

Textbook::Textbook() {
    Textbook(-1, NULL, 0.00, 1,0,NULL, TEXTBOOK);
}

Textbook::Textbook(int bookID, const char *title, double price, int inventory, int ISBN, char *TextBookAuthor, Category category)
        : Book(bookID,title,price,inventory, category)
{
    this->setISBN(ISBN);
    this->setTextAuthor(TextBookAuthor);
}


Textbook::~Textbook(){
    std::cout << "Textbook destroyed" << std::endl;
}

char *Textbook::getTextAuthor() {
    return this->TextBookAuthor;

}
int Textbook::getISBN() {
    return this->ISBN;
}

void Textbook::setISBN(int ISBN) {
    this->ISBN = ISBN;
}

void Textbook::setTextAuthor(char *TextBookAuthor) {
    strcpy(this->TextBookAuthor, TextBookAuthor);
}