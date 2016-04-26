#include <iostream>

#include "includes.h"

using namespace std;

//Main declarations
int main(int argc, char *argv[]);		// The main function
void menu();							// display main choices
void branching(char c, Catalog *pCatalog, ShoppingCart *pShoppingCart);	// branch to the chosen function


//=====================================================================================
// function addToCatalog()
//=====================================================================================
void addToCatalog(Catalog *catalog){
	//Not sure if I have to redeclare these... as I was working on getting this, I tried to access Book
	//To do something like cin.getline(Book::title, 50), etc. etc. but I followed the similar style
	//from the previous assignment.
	Book *book = new Book();
	Magazine *magazine = new Magazine();
	Fiction *fiction = new Fiction();

	//It is giving me errors when I try to include this Textbook part, but it can make when I block it out.

	//Textbook *textbook = new Textbook();

	int bookID;
	char title[50];
	double price;
	int inventory;
	char bookType[50];
	//Category category;

	char TextBookAuthor[50];
	int issue;
	int ISBN;
	char author[50];


	cout<<"ADDING A NEW BOOK TO THE CATALOG"<<endl;
	cout<<"================================"<<endl;
	cout<<"Note: Before adding a new book to the catalog, please look at what we already have..."<<endl;
	catalog->print();


	cout<<"Please enter the book ID: "<<endl;
	cin.ignore();
	cin>>bookID;
	cout<<"Please enter the name of book: "<<endl;
	cin.ignore();
	cin.getline(title,50);
	cout<<"Please enter the price of the book: "<<endl;
	cin>>price;
	cout<<"Please enter how many are in stock: "<<endl;
	cin.ignore();
	cin>>inventory;

	cout << "Enter the Category of the book: Textbook, Fiction, or Magazine: ";
	cin.ignore();
	cin.getline(bookType, 50);
	if (strcmp(bookType, "Textbook") ==0) book->setCategory(TEXTBOOK);
	else if (strcmp(bookType, "Fiction") ==0) book->setCategory(FICTION);
	else if (strcmp(bookType, "Magazine") ==0) book->setCategory(MAGAZINE);
	else if (strcmp(bookType, "Book") ==0) book->setCategory(BOOK);
	else{
		cout <<"Invalid input for bookType" << endl;
		//call a break statement or a loop of some sort to have it redo the entry for category???
	}

	switch (book->getCategory()) {
		case TEXTBOOK: {
			cout<<"BookType is TEXTBOOK."<<endl;
			cout<<"Please enter textbook's ISBN number: "<<endl;
			cin.ignore();
			cin>>ISBN;
			cout<<"Please enter the textbook's author: "<<endl;
			cin.getline(TextBookAuthor, 50);

			//Same as above; giving issue in make process with the Textbook...
			//book = new Textbook(bookID, title, price, inventory, ISBN, TextBookAuthor, TEXTBOOK);
			catalog->insertBook(book);
			break;
		}
		case BOOK: {
			cout<<"BookType is BOOK."<<endl;
			book = new Book(bookID, title, price, inventory, BOOK);
			catalog->insertBook(book);
			break;
		}
		case FICTION: {
			cout<<"BookType is FICTION."<<endl;
			cout<<"Please enter name of author: "<<endl;
			cin.getline(author,50);

			book = new Fiction(bookID, title, price, inventory, author, FICTION);
			catalog->insertBook(book);
			break;
		}
		case MAGAZINE: {
			cout<<"BookType is MAGAZINE."<<endl;
			cout<<"Please enter Magazine issue: "<<endl;
			cin.ignore();
			cin>>issue;
			book = new Magazine(bookID, title, price, inventory, issue, MAGAZINE);
			catalog->insertBook(book);
			break;
		}
	}


	//book->setID(bookID);
	//book->setTitle(title);
	//book->setPrice(price);
	//book->setInventory(inventory);


}
//=====================================================================================
// function addToShoppingCart()
//=====================================================================================
void addToShoppingCart(ShoppingCart *shoppingCart) {
	Book *book = new Book;
	char title[50];

	cout << "Thank you for selecting a book to purchase, to purchase, please enter the following..." << endl;
	cout << "Title of book: "<<endl;
	cin.getline(title,50);

	//I feel that to get this to work properly, we want to run a check with the inserted title against
	// the books in our catalog; if the book exists, add to shopping cart and affirm that it has been added

	//char *Book::getTitle(title);
}
//=====================================================================================
// function checkOut()
//=====================================================================================
void checkOut(ShoppingCart *shoppingCart) {

}

void recommendationsList(Catalog *pCatalog) {

}
void removeFromCatalog(Catalog *pCatalog) {

}

//=====================================================================================
// function main()
//=====================================================================================
int main(int argc, char *argv[]) {
	//Call the catalog which will bring us to import a file to start the program
	Catalog *catalog = new Catalog();
	ShoppingCart *pShoppingCart = new ShoppingCart();
	cout << endl << "Welcome to The Electronic Bookstore" << endl;

	char ch;
	do {
		menu();				// display choices
		cin >> ch;			// enter a choice from the keyboard
		ch = tolower(ch);	// convert to lower case
		branching(ch, catalog, pShoppingCart);		// branch to the chosen function
	}
	while (ch != 'q');			// 'q' for quit

	//catalog->print();
	delete pShoppingCart;
	delete catalog;

	return 0;
}

//=====================================================================================
// function branching() - Process user input and branches program
//=====================================================================================
void branching(char c, Catalog *pCatalog, ShoppingCart *pShoppingCart) {		// branch to chosen function
	switch(c) {
		case 's':	recommendationsList(pCatalog);
			break;
		case 'c':	{
			cout<<"Add to catalog called..."<<endl;
			addToCatalog(pCatalog);}
			break;
		case 'r':	removeFromCatalog(pCatalog);
			break;
		case 'a':	addToShoppingCart(pShoppingCart);
			break;
		case 'b':	checkOut(pShoppingCart);
			break;
		case 'i':	readData(pCatalog);
			break;
		case 'e':	writeData(pCatalog);
			break;
		case 'p':	pCatalog->print();
			break;
		case 'q':	cout << endl << "@Exiting the program..............." << endl;
			cin.get();	//type any key.
			break;
		default:	cout << endl << "@ERROR - Invalid input." << endl;
			cout << "@Try again....." << endl;
	}
}