#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *p = NULL, b;
    int a = 32;
    b = 16;

    p = &a;
    std::cout << "*p = " << *p << "\n";
    std::cout << "b = " << b << "\n";
    return 0;
}
