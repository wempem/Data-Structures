#include <vector>
#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {
    std::vector<int> ints;
    ints.push_back(14);
    ints.push_back(7);
    ints.push_back(12);
    ints.push_back(22);
    ints.push_back(18);
    ints.push_back(103);
    ints.push_back(96);
    ints.push_back(4);
    std::cout << "capacity: " << ints.capacity() << "\n";
    std::cout << "size: " << ints.size() << "\n";

    // The recommended way of iteratoring
    for (std::vector<int>::iterator i = ints.begin(); i != ints.end(); i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";

    std::vector<int>::iterator contains = find(ints.begin(), ints.end(), 22);

    std::cout << "Does 22 exist? " << (contains != ints.end()) << "\n";
    std::cout << "Position of 22:" << (contains - ints.begin()) << "\n";

    return 0;
}
