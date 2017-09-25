#include <stdlib.h>
#include <iostream>
#include "array.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
    	int ary[] = {1,2,3,4,5};
	Array<int> array(ary, 5);
	Array<int> array1(array);
	std::cout << array1[2] << "\n";
	std::cout << array.getLength() << "\n";
	std::cout << array.indexOf(3);
}

