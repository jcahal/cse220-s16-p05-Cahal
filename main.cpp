#include <iostream>

#include "includes.h"
#include "Fiction.h"

using namespace std;

//Main declarations
int main(int argc, char *argv[]);				// The main function
void menu();			// display main choices
void branching(char c, Catalog *pCatalog, ShoppingCart *pShoppingCart);	// branch to the chosen function


//=====================================================================================
// function addToCatalog()
//=====================================================================================
void addToCatalog(Catalog *catalog){
	//Not sure if I have to redeclare these... as I was working on getting this, I tried to access Book
	//To do something like cin.getline(Book::title, 50), etc. etc. but I followed the similar style
	//from the previous assignment.
	int bookID;
	char title[50];
	double price;
	int inventory;
	char bookType[50];
	Category category;

	int issue;
	//Not sure how what to call in terms of with the classes. this is giving an error, says needs to be static
	//Fiction::setAuthor(NULL);
	char author[50];

	Book *book = new Book;

	cout<<"ADDING A NEW BOOK TO THE CATALOG"<<endl;
	cout<<"================================"<<endl;
	cout<<"Note: Before adding a new book to the catalog, please look at what we already have..."<<endl;
	catalog->print();

	cout << "Enter the Category of the book: Textbook, Fiction, or Magazine: ";
	cin.ignore();
	cin.getline(bookType, 50);
	if (strcmp(bookType, "Textbook") ==0) category = TEXTBOOK;
	else if (strcmp(bookType, "Fiction") ==0) category = FICTION;
	else if (strcmp(bookType, "Magazine") ==0) category = MAGAZINE;
	else if (strcmp(bookType, "Book") ==0) category = BOOK;
	else{
		cout <<"Invalid input for bookType" << endl;
		//call a break statement or a loop of some sort to have it redo the entry for category???
	}

	switch (category) {
		case TEXTBOOK: {
			cout<<"BookType is TEXTBOOK."<<endl;
			//Uncertain on how to do this but almost feel that under this have it then
			//do the construction of Textbook(bookID,title,price,category)
			break;
		}
		case BOOK: {
			cout<<"BookType is BOOK."<<endl;
			break;
		}
		case FICTION: {
			cout<<"BookType is FICTION."<<endl;
			cout<<"Please enter name of author: "<<endl;
			cin.getline(author,50);
			//Perhaps should call in here fiction.setauthor(author)
			break;
		}
		case MAGAZINE: {
			cout<<"BookType is MAGAZINE."<<endl;
			cout<<"Please enter Magazine issue: "<<endl;
			cin>>issue;
			//Perhaps should call in here magazine.setissue(author)
			break;
		}
	}
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


	book->setID(bookID);
	book->setTitle(title);
	book->setPrice(price);
	book->setInventory(inventory);
	book->setCategory(category);

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

//=====================================================================================
// function main()
//=====================================================================================
int main(int argc, char *argv[]) {
cout << "Starting main" << endl;
	//Call the catalog which will bring us to import a file to start the program
	Catalog *catalog = new Catalog();
	ShoppingCart *shoppingCart = new ShoppingCart();
cout << "Step" << endl;
	cout << endl << "Welcome to The Electronic Bookstoree" << endl;

	char input;

	do {
		cout << "Loop" << endl;
		menu();

		cin >> input;

		branching(input, catalog, shoppingCart);

	} while(input != 'q');

	cout << "Out of loop" << endl;

	catalog->print();

	delete shoppingCart;
	delete catalog;


	char ch;
	do {
		menu();				// display choices
		cin >> ch;			// enter a choice from the keyboard
		ch = tolower(ch);	// convert to lower case
		branching(ch, catalog, shoppingCart);		// branch to the chosen function
	}
	while (ch != 'q');			// 'q' for quit
	return 0;
}

void recommendationsList(Catalog *pCatalog) {

}
void removeFromCatalog(Catalog *pCatalog) {

}

//=====================================================================================
// function branching() - Process user input and branches program
//=====================================================================================
void branching(char c, Catalog *pCatalog, ShoppingCart *pShoppingCart) {		// branch to chosen function
	switch(c) {
		case 's':	recommendationsList(pCatalog);
			break;
		case 'c':	addToCatalog(pCatalog);
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