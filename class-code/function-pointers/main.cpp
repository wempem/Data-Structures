#include <iostream>
#include <stdio.h>

int (*operation)(int, int);
int *intPointer;

int add(int a, int b) {
    return a + b;
}

int mult(int a, int b) {
    return a * b;
}

void printOperation(int (*op)(int, int));
void printOperations(int (**op)(int, int), int size);

int main(int argc, char *argv[]) {
    operation = mult;
    printf("operation = 0x%lx\n", operation);
    printf("&add = 0x%lx\n", &add);
    printf("&mult = 0x%lx\n", &mult);

    //std::cout << "(*operation)(10, 24) = " << (*operation)(10, 24) << "\n";
    printOperation(&add);
    printOperation(&mult);

    int (*operations[])(int, int) = {
        add,
        mult
    };
    printOperations(operations, 2);
    return 0;
}

void printOperation(int (*op)(int, int)) {
    std::cout << "(*op)(10, 24) = " << (*op)(10, 24) << "\n";
}

void printOperations(int (**op)(int, int), int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "(*op[" << i << "])(10, 24) = " << (*op[i])(10, 24) << "\n";
    }
}
