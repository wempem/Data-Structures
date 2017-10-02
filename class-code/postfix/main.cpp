#include <iostream>
#include <stack>

std::stack<int> iStack;
void add();
void mult();

int main(int argc, char *argv[]) {
    iStack.push(10);
    iStack.push(15);
    iStack.push(19);
    add();
    mult();
    std::cout << iStack.top() << "\n";
}

void mult() {
    int first = iStack.top();
    iStack.pop();
    int second = iStack.top();
    iStack.pop();
    iStack.push(first * second);
}

void add() {
    int first = iStack.top();
    iStack.pop();
    int second = iStack.top();
    iStack.pop();
    iStack.push(first + second);
}
