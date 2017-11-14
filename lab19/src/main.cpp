#include <stdio.h>
#include "hashtable.hpp"

int main(int argc, char *argv[]) {
    HashTable<int, int> table(100, .80);
    return 0;
}
