#include "map.hpp"
#include <iostream>
int main(int argc, char *argv[]){
	int ret = 0;
	Map *map = new Map(1);
	map->add("Matt W", 2);
	map->add("Matthew J", 3);	
	map->add("Jackson Josh", 5);
//	map->remove("Matthew J");
//	map->add("Jones Tim", 10);
//	map->add("Zach Smith", 12);
	map->get("Zach Smith", ret);
	std::cout << "ret is: " << ret << "\n";
	map->print();
	return 0;
}
