all: bookstore

bookstore: main.o containers books
	g++ main.o Book.o Magazine.o Fiction.o Catalog.o ShoppingCart.o -o bookstore

main.o:
	g++ -c main.cpp -o main.o

containers:
	g++ -c Catalog.cpp ShoppingCart.cpp

books:
	g++ -c Book.cpp Magazine.cpp Fiction.cpp

clean:
	rm *.o bookstore