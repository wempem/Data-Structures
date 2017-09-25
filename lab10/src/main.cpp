#include <stdlib.h>
#include <iostream>
#include "stack.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
    Stack<int> stack;
    stack.pop();
    cout << stack.getLength() << "\n";
    for (int i = 0; i < 100; i++) {
        stack.push(i);
    }
    cout << stack.getLength() << "\n";
    cout << stack.top() << "\n";
}

