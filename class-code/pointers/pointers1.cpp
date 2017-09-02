#include <iostream>

int main(int argc, char *argv[]) {
    int *a; // a stores the memory location of an integer.
            // Specifically this declares a to store a memory location of an integer.
            // IE: a is a pointer to an integer.
    int b = 100;
    std::cout << a << "\n"; // Output is undefined
    a = &b; // & generates a memory address of something
            // Therefore &b generates the memory address of b
            // We then stores in in a
    std::cout << "a = " << a << "\n"; // Output is the memory location of b
    std::cout << "b = " << b << "\n"; // Output is 100
    std::cout << "*a = " << *a << "\n"; // Output is the value stored at the memory location 
                                        // describe by a which is 100.
    *a = 200; // Go to the memory location describe by a and changes its value to 200.
    std::cout << "b = " << b << "\n"; // Output is 200
    return 0;
}
