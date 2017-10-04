#include <stdlib.h>
#include <iostream>
#include "array.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
	int ary[] = {1,2,3,4,5};
	Array<int> *arry = new Array<int>(ary, 5);
	//arry->print();
	//arry->bubbleSort();
	std::cout << arry->binarySearch(-2);
	//arry->bubbleSort();
	//arry->print();
}

