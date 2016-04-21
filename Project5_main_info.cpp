//=====================================================================================
/* Name: Austin Hancock- ashancoc@asu.edu
 * Project: C++ Project 5... cse220-s16-p05-ashancoc
 * Date: Tuesday, April 14th, 2016
 *
 */
//=====================================================================================
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
using namespace std;


//=====================================================================================

// Forward declaration of global functions outside any class
int main();				// The main function
void menu();			// display main choices
void branching(char);	// branch to the chosen function

void recommendationsList();

int addToCatalog();

int removeFromCatalog();

int addToShoppingCart();

int checkOut();




//=====================================================================================
// function main()
//=====================================================================================
int main() {	// main function is the entry point of the program
    char ch;
    cout << "SHOPPING CART" << endl;
    cout << "***********************************************" << endl;

    do {
        menu();				// display choices
        cin >> ch;			// enter a choice from the keyboard
        ch = tolower(ch);	// convert to lower case
        branching(ch);		// branch to the chosen function
    }
    while (ch != 'q');			// 'q' for quit
    return 0;
}

//=====================================================================================
// function menu()
//=====================================================================================
void menu() {
    cout <<	endl << endl << "MENU" << endl;
    cout << "----" << endl;
    cout << "s: See our Recommendations!" << endl;
    cout << "c: Add a book to the catalog." << endl;
    cout << "r: Remove a book from the catalog." << endl;
    cout << "a: Add books to the shopping cart." << endl;
    cout << "b: Proceed to check out."<<endl;
    cout << "q: Exit the store." << endl;
    cout << endl << "Please enter your choice () --> ";
}

//=====================================================================================
// function branching()
//=====================================================================================
void branching(char c) {		// branch to chosen function
    switch(c) {
        case 's':	recommendationsList();
            break;
        case 'c':	addToCatalog();
            break;
        case 'r':	removeFromCatalog();
            break;
        case 'a':	addToShoppingCart();
            break;
        case 'b':	checkOut();
            break;
        case 'q':	cout << endl << "@Exiting the program..............." << endl;
            cin.get();	//type any key.
            break;
        default:	cout << endl << "@ERROR - Invalid input." << endl;
            cout << "@Try again....." << endl;
    }
}

