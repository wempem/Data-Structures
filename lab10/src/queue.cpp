#ifdef QUEUE_H
#include "queue.hpp"
#include <stdlib.h>
#include <iostream>

template <class T>
Queue<T>::Queue(){
	mLinkedQueue = new SLList<T>();
}
template <class T>
Queue<T>::Queue(const Queue<T> &queue){
	mLinkedQueue = new SLList<T>(*(queue.mLinkedQueue));	
}
template <class T>
Queue<T>::~Queue(){
	delete mLinkedQueue;
}
template <class T>
int Queue<T>::getLength() const{
	return mLinkedQueue->getLength();
}
template <class T>
bool Queue<T>::isEmpty() const{
	return mLinkedQueue->getLength() == 0;
}

template <class T>
void Queue<T>::print() const{
	mLinkedQueue->print();
}
template <class T>
bool Queue<T>::push(const T&val){
	return mLinkedQueue->insert(mLinkedQueue->getLength(), val);
}
template <class T>
T& Queue<T>::first(){
	return mLinkedQueue->operator[](0);
}

template <class T>
void Queue<T>::pop(){
	mLinkedQueue->removeFirst();	
}

template <class T>
bool Queue<T>::operator==(const Queue<T> &queue) const{
	bool isEqual = mLinkedQueue->operator==(*queue.mLinkedQueue);
	return isEqual;
}

#endif
