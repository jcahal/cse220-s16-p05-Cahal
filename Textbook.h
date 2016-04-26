//
// Created by MacBook Pro on 4/25/16.
//

#ifndef CSE220_PROJECT5_TEXTBOOK_H
#define CSE220_PROJECT5_TEXTBOOK_H

#include <iostream>
#include "Book.h"

class Textbook: public Book {
private:
    int ISBN;
    char TextBookAuthor[50];


public:
    Textbook();
    Textbook(int bookID, const char *title, double price, int inventory, int ISBN, char *TextBookAuthor, Category category);


    virtual ~Textbook(); //destructor

    char getTextAuthor();

    void setTextAuthor(char *TextBookAuthor);

    int getISBN();

    void setISBN(int ISBN);

};



#endif //CSE220_PROJECT5_TEXTBOOK_H
