#ifdef HEAP_H

template<class T>
Heap<T>::Heap(const int len) {
    mCapacity = len;
    mHeap = new T[mCapacity];
    mSize = 0;
}

template <class T>
Heap<T>::Heap(const T *array, const int size){

}

template<class T>
void Heap<T>::insert(const T& element) {
    // 1) Check if we have capacity.
    if (mSize >= mCapacity) {
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

}

template<class T>
int Heap<T>::getSize(){

}

template <class T>
int Heap<T>::contains(const T &val) const{

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

}
#endif
