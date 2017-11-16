#ifdef PRIORITY_QUEUE_H
#include <iostream>
template<class T>
PriorityQueue<T>::PriorityQueue() { 
	std::make_heap(mVector.begin(), mVector.end());
}

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T> &pq){
	mVector(pq.begin(), pq.end());
}

template <class T>
PriorityQueue<T>::~PriorityQueue(){
}

template<class T>
int PriorityQueue<T>::getLength() const{
	return mVector.size();
}

template<class T>
bool PriorityQueue<T>::isEmpty() const{
	if(mVector.size() == 0){
		return true;
	}
	return false;
}
template<class T>
void PriorityQueue<T>::print() const{;
	std::cout << "\n";
	for(std::vector<int>::const_iterator i = mVector.begin(); i != mVector.end(); i++){
		std::cout << *i << " , ";
	}
}
template<class T>
bool PriorityQueue<T>::push(const T &val){
	mVector.push_back(val);
	push_heap(mVector.begin(), mVector.end());
	sort_heap(mVector.begin(), mVector.end());
	if(val == mVector.front()){
		return true;	
	}
	return false;
}
template<class T>
T PriorityQueue<T>::pop() {
	T temp;
	temp = mVector.front();
	pop_heap(mVector.begin(), mVector.end());
	return temp;
}

template<class T>
bool PriorityQueue<T>::operator==(const PriorityQueue<T> &pq) const{
//	for(std::vector<T>::iterator i = mVector.begin(); i != mVector.end(); i++){

//	}
//	pq.mVector(i);
}
#endif
