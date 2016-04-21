//
// Created by MacBook Pro on 4/19/16.
//

#ifndef CSE220_PROJECT5_MAGAZINE_H
#define CSE220_PROJECT5_MAGAZINE_H

#include <iostream>
#include "Book.h"

class Magazine: public Book {
private:
    int issue;

public:
    Magazine();
    Magazine(int bookID, const char *title, double price, int inventory, int issue, Category category);


    virtual ~Magazine(); //destructor

    int getIssue();

    void setIssue(int issue);

};


#endif //CSE220_PROJECT5_MAGAZINE_H
