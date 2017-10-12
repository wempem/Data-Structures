#include <stdlib.h>
#include <iostream>
#include "sllist.hpp"
#include "dllist.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
	SLList<int> sl;
	DLList<int> dll;
	dll.append(18);
	dll.append(19);
	dll.append(20);
	std::cout << dll.getLength();
	dll.print();
//	sl.append(17);
//	sl.append(42);
//	sl.append(52);
//	std::cout << "sl.getLength() = " << sl.getLength() << "\n";
//	sl.print();
//	sl.remove(42);
//	sl.print();	
//	std::cout << "sl.getLength() = " << sl.getLength() << "\n";	
//	sl.append(51);
//	std::cout << "sl.getLength() = " << sl.getLength() << "\n";	
//	sl.print();
}

