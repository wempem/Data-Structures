#include <iostream>

int main(int argc, char *argv[]) {
    int *a; // a stores the memory location of an integer.
            // Specifically this declares a to store a memory location of an integer.
            // IE: a is a pointer to an integer.
    int b = 100;
    int c = 100;
    std::cout << a << "\n"; // Output is undefined
    a = &b; // & generates a memory address of something
            // Therefore &b generates the memory address of b
            // We then stores in in a
    std::cout << "a = " << a << "\n"; // Output is the memory location of b
    std::cout << "b = " << b << "\n"; // Output is 100
    std::cout << "*a = " << *a << "\n"; // Output is the value stored at the memory location 
                                        // describe by a which is 100.

    double *d = (double *)&b;/* 1) Declares d to be a pointer to a double
                                2) generates the memory location of b
                                3) Casts that memory location to a double pointer
                                4) Stores that pointer in d.*/
    std::cout << "d = " << d << "\n"; // Output is the memory location of b
    std::cout << "*d = " << *d << "\n"; // Output is technically undefined.

    float *f = (float *)&b;/* 1) Declares f to be a pointer to a double
                                2) generates the memory location of b
                                3) Casts that memory location to a double pointer
                                4) Stores that pointer in f.*/
    std::cout << "f = " << f << "\n"; // Output is the memory location of b
    std::cout << "*f = " << *f << "\n"; // Output is technically undefined.

    *f = 10.135;
    std::cout << "*f = " << *f << "\n"; // Output is 10.135
    std::cout << "b = " << b << "\n"; // Output is some integer representation of 10.135

    return 0;
}
