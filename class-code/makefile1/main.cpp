#include <iostream>

#include "sum.hpp"

int main(int argc, char *argv[]) {
    int start = 0;
    int end = 100;

    std::cout << "I have " << argc << " arguments.\n";
    std::cout << "and here they are!\n";

    for (int i = 0; i < argc; i++) {
        std::cout << "argv[" << i << "] = '" << argv[i] << "'\n";
    }

    if (argc > 2) {
        start = atoi(argv[1]);
        end = atoi(argv[2]);
    }

    std::cout << sum(start, end) << "\n";
    return 0;
}
