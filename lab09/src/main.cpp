#include <stdlib.h>
#include <iostream>
#include "sllist.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
    SLList<int> sl;
    std::cout << "sl.getLength() = " << sl.getLength() << "\n";
    sl.print();
    sl.append(17);
    std::cout << "sl.getLength() = " << sl.getLength() << "\n";
    sl.print();
    sl.append(8);
    sl.append(32);
    sl.append(78);
    sl.append(17);
    sl.append(9001);
    sl.print();
    SLList<int> sl2(sl);
    sl2.print();
}
