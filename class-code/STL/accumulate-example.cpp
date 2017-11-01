#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>

int fun(const int &a, const int &b) {
    return a*b;
}

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

    int sum = 0;
    for (int i = 0; i < ints.size(); i++) {
        sum += ints[i];
    }
    std::cout << "sum = " << sum << "\n";

    std::cout << "sum = " << accumulate(ints.begin(), ints.end(), 0, std::plus<int>()) << "\n";
    std::cout << "sum = " << accumulate(ints.begin(), ints.end(), 1, fun) << "\n";

    return 0;
}
