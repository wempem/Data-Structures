/* Array is templated, therefore only include the code if it is included from
 * the header file! 
 */
#ifdef ARRAY_H
#include <stdio.h>
#include <algorithm>

/* Do a deep copy of the array into the list.
 * Note: This one uses a pointer!
 */
template <class T>
Array<T>::Array(const T *array, const int size){
	mSize = size;
	mArray = new int[mSize];
 	for(int i = 0; i < mSize; i++)
          	mArray[i] = array[i];
  	}


/* Do a deep copy of the array into the list
 * Note: This one uses a reference to a List!
 */
template <class T>
Array<T>::Array(const Array<T> &list){
	mArray = new int[list.mSize];
	for(int i = 0; i <list.mSize; i++){
        	mArray[i] = list.mArray[i];
	}
}
template <class T>
int Array<T>::getLength() const{
	return mSize;
}
template <class T>
int Array<T>::indexOf(const T &value){
	for(int i = 0; i < mSize; i++){
		if(mArray[i] == value){
			return i;
		}
	}
	return -1;
}
template <class T>
bool Array<T>::remove(const int index){
	        if(index >= mSize || index < 0){
                return false;
        }
        for(int i = 0; i < mSize; i++){
                if(i == index){
                        for(int j = i; j < (mSize - 1); j++){
                                mArray[j] = mArray[j+1];
                        }
                        mArray[mSize - 1] = 0;
                        return true;
                }
        }
        return false;
}

/* Retrieves the element at position pos */
template <class T>
T& Array<T>::operator[](const int pos){
	return mArray[pos];
}

template <class T>
bool Array<T>::operator==(Array<T> &list) const{

}

template <class T>
void Array<T>::bubbleSort(){
	for(int i = 0; i < mSize; i++){
		for(int j = 0; j < mSize - 1; j++){
                  	if(mArray[j] > mArray[j+1]){
                          	std::swap(mArray[j], mArray[j+1]);
                  }
          }
  }
}
template <class T>
void Array<T>::selectionSort(){
	int temp = 0;
	for(int i = 0; i < mSize - 1; i++){
			temp = i;
		for(int j = i + 1; j < mSize; j++){
			if(mArray[j] < mArray[temp]){
				temp = j;
				std::swap(mArray[i], mArray[temp]);
			}
		
		
		}
		//std::cout << temp << "," << "\n";
	}
}

template <class T>
void Array<T>::print(){
	for(int i = 0; i < mSize; i++){
		std::cout << mArray[i] << " , ";
	}
	std::cout << "\n";
}

template <class T>
void Array<T>::insertionSort(){
	int temp = 0;
	for(int i = 0; i < mSize; i++){
		for (int j = i; j > 0 && mArray[j - 1] > mArray[j]; j--) {
 			std::swap(mArray[j], mArray[j-1]);
		}
	}
}

template <class T>
void Array<T>::sort(){
	Array<T>::insertionSort();
}


template <class T>
Array<T>::~Array() {
	delete[] mArray;
}

#endif
