#include <iostream>

void recursivePrint(int iary[], int pos, int size);
int factorial(int n);

int main(int argc, char *argv[]) {
    int iary[] = {0, 4, 72, 12, 44, 18, 19, 20, 21};

    // If we want to print
    for (int i = 0; i < 9; i++) {
        std::cout << iary[i] << ",";
    }
    std::cout << "\n";

    recursivePrint(iary, 0, 9);

    std::cout << "5! = " << factorial(5) << "\n";
    std::cout << "10! = " << factorial(10) << "\n";

    return 0;
}

int factorial(int n) {
    // Base Case
    if (n == 0) {
        return 1;
    }

    // Recurse
    return n * factorial(n-1);
}

void recursivePrint(int iary[], int pos, int size) {
    // ALWAYS WRITE YOUR BASE CASE ON TOP!!!
    if (pos == size) {
       std::cout << "\n";
       return;
    }

    // Do the work.
    std::cout << iary[pos] << ",";

    // Recurse
    recursivePrint(iary, pos + 1, size);
}
