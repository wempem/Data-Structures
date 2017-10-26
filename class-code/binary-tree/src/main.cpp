#include <stdio.h>
#include <iostream>
#include "binarytree.hpp"

int main(int argc, char *argv[]) {
    BinaryTree bt;
    bt.insert(6);
    bt.insert(18);
    bt.insert(9001);
    bt.insert(4);
    bt.insert(73);
    bt.insert(72);
    bt.insert(42);
    std::cout << bt.inorderTraversal();
    return 0;
}
