#include <iostream>

int main(int argc, char *argv[]) {
    int *a = new int; /* 1) Declares a to be a pointer to an int
                         2) allocate 1 integer in the heap
                         3) stores the memory location of that integer in 'a'
                         */
    std::cout << "a = " << a << "\n"; // Output is memory location of the integer
    std::cout << "*a = " << *a << "\n"; // Output is undefined
    *a = 100;
    std::cout << "a = " << a << "\n"; // Output is memory location of the integer
    std::cout << "*a = " << *a << "\n"; // Output is 100

    int *b = a; // First declares b to be a pointer to an integer, then b=a, namely
                // b stores the same memory location as a.

    std::cout << "b = " << b << "\n"; // Output is the memory address of a/the integer.
    *a = 200;
    std::cout << "*b = " << *b << "\n"; // Output is 200

    int **c = &b; /* 1) Declare c to be a pointer to pointer to an integer.
                     2) It generates the memory location of b
                     3) It stores the memory location of b in c
                     */
    std::cout << "c = " << c << "\n"; // Output is the memory location of b
    std::cout << "*c = " << *c << "\n"; // Output is the memory location of the integer.
    std::cout << "**c = " << **c << "\n"; // Output is 200

    int **d = &a; /* 1) Declare d to be a pointer to pointer to an integer.
                     2) It generates the memory location of a
                     3) It stores the memory location of a in d
                     */
    std::cout << "d = " << d << "\n"; // Output is the memory location of a.
    std::cout << "*d = " << *d << "\n"; // Output is memory location of the integer a is pointing to.
    std::cout << "**d = " << **d << "\n"; // Output is 200

    int ***e = (int ***)d; /* 1) Declares e to be a pointer to a pointer to a pointer to an integer.
                              2) Casts d to be a apointer to a pointer to a pointer to an integer.
                              3) stores the value of casted d in e.*/
    std::cout << "e = " << e << "\n"; // Output is the memory location of a
    std::cout << "*e = " << *e << "\n"; // Output is the memory location of the integer
    std::cout << "**e = " << **e << "\n"; // Output is 200
    std::cout << "***e = " << ***e << "\n"; // Output is undefined, but will probaly segfault

    delete a; // delete b also work, as well as delete *c
    return 0;
}
