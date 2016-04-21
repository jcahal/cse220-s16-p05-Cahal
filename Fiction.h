//
// Created by MacBook Pro on 4/19/16.
//

#ifndef CSE220_PROJECT5_FICTION_H
#define CSE220_PROJECT5_FICTION_H

#include <iostream>
#include "book.h"

class Fiction: public Book{
private:
    char author[100];

public:
    Fiction();
    Fiction(int bookID, const char *title, double price, int inventory,char *author, Category category);

    virtual ~Fiction();

    char *getAuthor();

    void setAuthor(char *author);
};


#endif //CSE220_PROJECT5_FICTION_H
