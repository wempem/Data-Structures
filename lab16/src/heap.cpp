#ifdef HEAP_H
#include <cmath>
template<class T>
Heap<T>::Heap(const int len) {
    mCapacity = len;
    mHeap = new T[mCapacity];
    mSize = 0;
}

template <class T>
Heap<T>::Heap(const T *array, const int size){
	mSize = size;
	mHeap = new T[mSize];
	for(int i = 0; i < mSize; i++){
		mHeap[i] = array[i];
	}
}

template<class T>
void Heap<T>::insert(const T& element) {
    // 1) Check if we have capacity.
    if (mSize >= mCapacity) {
	while(mSize > mCapacity){
		mCapacity++;
	}
        //TODO: increase capacity!
    }

    // 2) Add the element to the end to preserve left justification &
    //    balanace.
    mHeap[mSize] = element;
    mSize++;

    // 3) SiftUp to fix the heap.  (AKA maintain the heap property.)
    int currentIndex = mSize - 1;
    int parentIndex = (currentIndex - 1) / 2;
    while (mHeap[parentIndex] < mHeap[currentIndex]) {
        T temp = mHeap[parentIndex];
        mHeap[parentIndex] = mHeap[currentIndex];
        mHeap[currentIndex] = temp;

        currentIndex = parentIndex;
        parentIndex = (currentIndex - 1) / 2;
    }
}

template<class T>
int Heap<T>::getHeight(){
	int temp = mSize + 1;
	int fin = 0;
	fin = log(temp) / log(2);
	if(fmod(log(temp),log(2)) == 1){
		return fin += 1;
	}
	return fin;
}

template<class T>
int Heap<T>::getSize(){
	return mSize;
}

template <class T>
int Heap<T>::contains(const T &val) const{
	for(int i = 0; i < mSize; i++){
		if(val == mHeap[i]){
			return i;
		}
	}
	return -1;
}

template<class T>
T& Heap<T>::operator[](const int pos) {
    return mHeap[pos];
}

template<class T>
T* Heap<T>::heapSort() {
    // At this point the array has been heapified
    // We want to swap the first and last element, then reheap.
    // Do that until mSize == 0;
    while (mSize != 0) {
        removeFirst();
    }

    T* ret = mHeap;
    mHeap = NULL;
    mCapacity = 0;

    return ret;
}

/* Removes and returns the first element */
template<class T>
T& Heap<T>::removeFirst() {
	T temp = 0;
	T first = mHeap[0];
	temp = mHeap[mSize - 1];
	mHeap[mSize - 1] = first;
	mSize--;
	heapSort();
	return mHeap[mSize];
    // 1) Swap the first and last element
    // 2) Decrement mSize
    // 3) Reheap
    // 4) return mHeap[mSize];
}

template<class T>
Heap<T>::~Heap() {
	delete[] mHeap; 
}
#endif
