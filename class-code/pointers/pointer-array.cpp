#include <iostream>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *p = new int[10];

    *p = 25;
    std::cout << "*p = " << *p << "\n";
    p++;
    *p = 35;
    std::cout << "*p = " << *p << "\n";
    std::cout << "p[0] = " << p[0] << "\n";
    std::cout << "p[-1] = " << p[-1] << "\n";
    p--;
    std::cout << "p[0] = " << p[0] << "\n";
    p[4] = 100;
    p += 4;
    std::cout << "p[0] = " << p[0] << "\n";
    std::cout << "*p = " << *p << "\n";
    p[1] = 200;
    std::cout << "p[1] = " << p[1] << "\n";
    std::cout << "*(p+1) = " << *(p+1) << "\n";
    return 0;
}
