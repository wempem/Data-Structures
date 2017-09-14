#include <iostream>
#include <stdlib.h>

int add(int *a, int *b);
int fun(int *a, int *b);
int fun2(int *a, int *b);
void fun3(int *&a);

int main(int argc, char *argv[]) {
    int *p = new int[10];

    for (int i = 0; i < 10; i++) {
        p[i] = 10 + i*10;
    }

    std::cout << add(p, p+5) << "\n";
    std::cout << fun(p+1, p+5) << "\n";

    std::cout << "*p = " << *p << "\n";

    fun2(p, p+1);
    std::cout << "*p = " << *p << "\n";

    fun3(p);
    std::cout << "*p = " << *p << "\n";

    return 0;
}

int add(int *a, int *b) {
    return *a + *b;
}

int fun(int *a, int *b) {
    a++;
    b--;

    return *a + *b;
}

int fun2(int *a, int *b) {
    *a = 200;
    *b = 300;
}

void fun3(int *&a) {
    a++;
}
