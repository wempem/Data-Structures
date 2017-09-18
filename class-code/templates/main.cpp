#include <iostream>
#include "array.hpp"

template<class T>
T sum(T a, T b) {
    return a + b;
}

void templateFunctionTest();


int main(int argc, char *argv[]) {
    //templateFunctionTest();
    int ary[] = {5, 99, 32, 72, 101, -98, 30, 33, 12};
    Array<int> DUT(ary, 9);
    return 0;
}

void templateFunctionTest() {
    int a = 5, b = 10;
    std::cout << "sum of a & b = " << sum(a, b) << "\n";
    double c = 5.7, d = 10.8;
    std::cout << "sum of c & d = " << sum(c, d) << "\n";
    std::cout << "sum of a & d = " << sum((double)a, d) << "\n";
}
