#include <iostream>

int main(int argc, char *argv[]) {
    int *grades = new int[100];

    for (int i = 0; i < 100; i++) {
        grades[i] = i;
    }


    delete[] grades;

    return 0;
}
