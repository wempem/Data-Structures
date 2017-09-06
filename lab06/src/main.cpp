#include <stdlib.h>
#include <iostream>
#include "IntArray.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    int array[] = {1, 2, 3, 4, 5, 6};
    IntArray DUT(array, 6);
    IntArray *DUT2 = new IntArray(array, 6);
    /* You may write manual tests here. */
    delete DUT2;
}

