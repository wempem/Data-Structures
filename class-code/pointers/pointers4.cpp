#include <iostream>

int main(int argc, char *argv[]) {
    int ary[100];
    int *a; // a stores the memory location of an integer.
            // Specifically this declares a to store a memory location of an integer.
            // IE: a is a pointer to an integer.
    a = ary;// a points to ary, namely a points to the first element of ary
    *a = 100;
    std::cout << "*a = " << *a << "\n"; // Output is 100;
    std::cout << "ary[0] = " << ary[0] << "\n"; // Output is 100
    ary[0] = 123;
    std::cout << "*a = " << *a << "\n"; // Output is 123

    *(a + 1) = 200;
    std::cout << "ary[0] = " << ary[0] << "\n"; // Output is 123
    std::cout << "ary[1] = " << ary[1] << "\n"; // Output is 200

    for (int i = 0; i < 100; i++) {
        *a = 100 * i;
        a++;
    }

    std::cout << "ary[2] = " << ary[2] << "\n"; // Output is 200

    std::cout << "a = " << a << "\n"; // Output memory location of the first element after the array
                                      // IE: ary[100]
    *a = 200; // Is this good? NO!

    return 0;
}
