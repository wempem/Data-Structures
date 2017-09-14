#include <iostream>
#include "arrays.hpp"

int main(int argc, char *argv[]){
	int test_array[] = {2,3,4,0,5,6,7,11,12, 1};
	//std::cout << findMinOdd(test_array, 10) << "\n";
	//std::cout << search(test_array, 10 , 1) << "\n";
	for(int i = 0; i < 10; i++){
		std::cout << test_array[i] << ",";
	}
	std::cout << "\n";
	remove(test_array, 10, -12);
	for(int i = 0; i < 10; i++){
		std::cout << test_array[i] << ",";
	}
	return 0;
}
