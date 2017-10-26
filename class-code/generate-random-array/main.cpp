#include <iostream>
#include <stdlib.h>

int* generateRandomArray(int size);

int main(int argc, char *argv[]) {
    srand(100);
    int *rand1 = generateRandomArray(10);
    for (int i = 0; i < 10; i++) {
        std::cout << rand1[i] << "\n";
    }
    int *rand2 = generateRandomArray(10);
    for (int i = 0; i < 10; i++) {
        std::cout << rand2[i] << "\n";
    }

    delete[] rand1;
    delete[] rand2;
    return 0;
}

int* generateRandomArray(int size) {
    int *ret = new int[size];

    for (int i = 0; i < size; i++) {
        ret[i] = rand();
    }

    return ret;
}
