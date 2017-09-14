#include "IntArray.hpp"

/* Copy array’s contents to an internal array, (length = size). 
 * Do a deep copy!
 */
IntArray::IntArray(int *array, int size) {
    mSize = size;
    mArray = new int[mSize];

    for (int i = 0; i < mSize; i++) {
        mArray[i] = array[i];
    }
}

// Testing function
int IntArray::get(int index) {
    return mArray[index];
}

IntArray::~IntArray() {
    delete[] mArray;
}

int IntArray::getLength() {
    return mSize;
}
