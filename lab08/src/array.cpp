/* Array is templated, therefore only include the code if it is included from
 * the header file! 
 */
#ifdef ARRAY_H
#include <stdio.h>
#include <iostream>
/* Do a deep copy of the array into the list.
 * Note: This one uses a pointer!
 */
template <class T>
Array<T>::Array(const T *array, const int size){
	mSize = size;
	mArray = new int[mSize];
	for(int i = 0; i < mSize; i++){
		mArray[i] = array[i];
	std::cout << " ," << mArray[i];
	}
	std::cout << "\n";
}

/* Do a deep copy of the array into the list
 * Note: This one uses a reference to a List!
 */
template <class T>
Array<T>::Array(const Array<T> &list){
	mArray = new int[list.mSize]; 
	for(int i = 0; i < list.mSize; i++){
		mArray[i] = list.mArray[i];		
		std::cout << " ," << mArray[i];
	}
}
template <class T>
int Array<T>::Array::getLength() const{
	return mSize;
}

template <class T>
int Array<T>::Array::indexOf(const T &value){
	for(int i = 0; i < mSize; i++){
		if(mArray[i] == value){
			return i;
		}
	}
	return -1;
}
template <class T>
bool Array<T>::Array::remove(const int index){
	if(index < 0){
		return false;
	}
	else if (index > mSize){
		return false;
	}
	else{
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
}

/* Retrieves the element at position pos */
template <class T>
T& Array<T>::operator[](const int pos){
	return mArray[pos];
}

template <class T>
bool Array<T>::operator==(Array<T> &list) const{
	bool equals = false;
	if((list.getLength != mSize) || (list.mSize == NULL)){
		return equals;
	}
	for(int i = 0; i < mSize; i++){
		if(mArray[i] == list.get[i]){
			equals == true;
		}
		else{
			equals = false;
			return equals;
		}	
	}
	return equals; 
}

template <class T>
Array<T>::~Array() {
	delete[] mArray;
}


#endif
