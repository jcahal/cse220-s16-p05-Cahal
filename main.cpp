#include <iostream>

#include "includes.h"

using namespace std;

int main(int argc, char *argv[]) {

	Catalog *catalog = new Catalog;
	readData(catalog);

	delete catalog;

	return 0;
}