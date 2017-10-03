#include <stdlib.h>
#include <iostream>
#include "stack.hpp"
#include "queue.hpp"
using namespace std;

int main(int argc, char *argv[]) {
    /* You may write manual tests here. */
	Queue<int> queue;
    Stack<int> stack;
	queue.pop();
    stack.pop();
    cout << stack.getLength() << "\n";
    for (int i = 0; i < 100; i++) {
        queue.push(i);
    }
    cout << queue.getLength() << "\n";
    //cout << queue.top() << "\n";

    Stack<int> s2(stack);
}

