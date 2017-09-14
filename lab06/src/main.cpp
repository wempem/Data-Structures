#include <stdlib.h>
#include <iostream>
#include "IntArray.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	int arry[] = {121,1235,7,9};
    int array[] = {1, 2, 3, 4, 5, 6};
    //IntArray ary(arry, 4);
    IntArray *ary = new IntArray(arry, 4);	
    //IntArray DUT(array, 6);
    IntArray *DUT2 = new IntArray(array, 6);
    /* You may write manual tests here. */
	//std::cout << (DUT.remove(3));
	std::cout << "hi" << "\n";
	std::cout << (DUT2 -> findIntersections(*(ary)));
	
    delete DUT2;
	delete ary;
}

