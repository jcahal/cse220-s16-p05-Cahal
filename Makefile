all: bookstore

bookstore: main.o classes
	g++ main.o Book.o Catalog.o ShoppingCart.o Magazine.o -o bookstore

main.o:
	g++ -c main.cpp -o main.o

classes:
	g++ -c Book.cpp Catalog.cpp ShoppingCart.cpp Magazine.cpp

clean:
	rm *.o bookstore