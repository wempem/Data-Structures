#ifndef ARRAY_HPP
#define ARRAY_HPP

template<class T>
class Array {
    private:
        int mSize;
        T *mArray;
    public:
        Array(T *array, int size);
};


/* Never do this, except when using templates! */
#include "array.cpp"

#endif
