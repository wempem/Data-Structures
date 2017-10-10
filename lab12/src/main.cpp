#include <stdlib.h>
#include <iostream>
#include "array.hpp"
#include "sllist.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
	int array[] = {5,1,3,82,17};
	Array<int> *ary = new Array<int>(array,5);
	ary->print();
	ary->insertionSort();
	ary->print();
}

