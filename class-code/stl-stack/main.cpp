#include <iostream>
#include <stack>

int main(int argc, char *argv[]) {
    std::stack<int> iStack;
    iStack.push(10);
    iStack.push(15);
    iStack.push(19);
    std::cout << iStack.top() << "\n";
    std::cout << iStack.top() << "\n";
    iStack.pop();
    std::cout << iStack.top() << "\n";
}
