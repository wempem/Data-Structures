#ifdef STACK_H
#include <stdlib.h>
#include <iostream>
#include "stack.hpp"

template <class T>
Stack<T>::Stack() {
    mLinkedStack = new SLList<T>();
}

template <class T>
Stack<T>::Stack(const Stack<T> &stack) {
    mLinkedStack = new SLList<T>(*(stack.mLinkedStack));
}

template <class T>
Stack<T>::~Stack() {
    delete mLinkedStack;
}

template <class T>
int Stack<T>::getLength() const {
    return mLinkedStack->getLength();
}

template <class T>
bool Stack<T>::push(const T &val) {
    return mLinkedStack->insert(0, val);
}

template <class T>
T& Stack<T>::top() {
    return (*mLinkedStack)[0];
}

template <class T>
void Stack<T>::pop() {
    mLinkedStack->removeLast();
}

template <class T>
void Stack<T>::print() const {
    mLinkedStack->print();
}

template <class T>
bool Stack<T>::isEmpty() const {
    return mLinkedStack->getLength() == 0;
}
template <class T>
bool Stack<T>::operator==(const Stack<T> &stack) const{
        bool isEqual = false;
	isEqual = mLinkedStack->operator==(*stack.mLinkedStack);
        return isEqual;
}

#endif
