#include <vector>
#include <iostream>

int main(int argc, char *argv[]) {
    std::vector<int> ints;
    std::cout << "starting capacity: " << ints.capacity() << "\n";
    //ints.reserve(100);
    ints.push_back(14);
    std::cout << "new capacity: " << ints.capacity() << "\n";
    ints.push_back(7);
    std::cout << "new capacity: " << ints.capacity() << "\n";
    ints.push_back(12);
    ints.push_back(22);
    ints.push_back(18);
    ints.push_back(103);
    ints.push_back(96);
    ints.push_back(4);
    std::cout << "capacity: " << ints.capacity() << "\n";
    std::cout << "size: " << ints.size() << "\n";

    // The not recommended way of iterating.
    for (int i = 0; i < ints.size(); i++) {
        std::cout << ints[i] << " ";
    }
    std::cout << "\n";

    // Out of bounds, but C++ just allows is =(
    //std::cout << ints[10] << "\n";

    // The recommended way of iteratoring
    for (std::vector<int>::iterator i = ints.begin(); i != ints.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    // Going backwards
    for (std::vector<int>::iterator i = (ints.end() - 1); i != ints.begin() - 1; i--) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    ints.insert(ints.begin() + 3, 47);
    // The recommended way of iteratoring
    for (std::vector<int>::iterator i = ints.begin(); i != ints.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    ints.erase(ints.begin() + 5);
    ints.erase(ints.begin() + 7);
    ints.erase(ints.begin() + 2);
    // The recommended way of iteratoring
    for (std::vector<int>::iterator i = ints.begin(); i != ints.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    std::cout << "capacity: " << ints.capacity() << "\n";
    std::cout << "size: " << ints.size() << "\n";

    return 0;
}
