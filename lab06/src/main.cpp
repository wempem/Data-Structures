#include <stdlib.h>
#include <iostream>
#include "IntArray.hpp"

using namespace std;

int main(int argc, char *argv[]) {
<<<<<<< HEAD
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
	std::cout << (*(ary->indexOf(1235)));
    delete DUT2;
	delete ary;
=======
    int array[] = {1, 2, 3, 4, 5, 6};
    IntArray DUT(array, 6);
    IntArray *DUT2 = new IntArray(array, 6);
    /* You may write manual tests here. */
    delete DUT2;
>>>>>>> 6496dea5d51dc379abad9c5429ca9b43c4ae124d
}

