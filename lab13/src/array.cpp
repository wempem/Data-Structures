/* Array is templated, therefore only include the code if it is included from
 * the header file! 
 */
#ifdef ARRAY_H
#include <stdio.h>
#include <algorithm>
#include <iostream>
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
void Array<T>::qsort(){
	int middlePos = mArray[mSize/2];
	int right = mSize - 1;
	int left = 0;
	int temp;

	while(left <= right){
		while(mArray[right] > middlePos){
			right--;	
		}
		while(mArray[left] < middlePos){
			left++;
		}
		if(left <= right){
			temp = mArray[left];
			mArray[left] = mArray[right];
			mArray[right] = temp;
			right--;
			left++;
		}		
	}
	
	if(mSize - 1 < left){
		quickSort(left, mSize - 1);
	}
	if(0 < right){
		quickSort(0, right);
	}
}

template <class T>
void Array<T>::quickSort(int left, int right){
	
	int middlePos = mArray[(left + right) / 2];
	int newLeft = left;
	int newRight = right;
	int temp;
	std::cout << "newRight: " << newRight << "\n"; 
	while(newLeft <= newRight){
		while(mArray[newRight] > middlePos){
			newRight--;
		}
		while(mArray[newLeft] < middlePos){
			newLeft++;
		}
		if(newLeft <= newRight)
			temp = mArray[newLeft];
			mArray[newLeft] = mArray[newRight];
			mArray[newRight] = temp;
			newRight--;	
			newLeft++;
	}

	std::cout << "Left: " << left << "\n";
	std::cout << "newRight: " << newRight << "\n";
	std::cout << "newLeft: " << newLeft << "\n";
	std::cout << "right: " << right << "\n";
	if(newLeft < right){
		quickSort(newLeft, right);
	}
	if(left < newRight){
		quickSort(left, newRight);
	}
	std::cout << "Didn't do through";
}

template <class T>
void Array<T>::msort(){
	merge_sort(mArray, mSize);
}

template <class T>
void Array<T>::print(){
	for(int i = 0; i < mSize; i++){
		std::cout << mArray[i] << " , ";
	}
	std::cout << "\n";
}

template <class T>
void Array<T>::sort(){
	Array<T>::qsort();
}


template <class T>
Array<T>::~Array() {
	delete[] mArray;
}

template <class T>
void Array<T>::merge_sort(int *ary, int size){

	if (size == 1){
                return;
        }

        int middlePos = size / 2;
        merge_sort(ary, middlePos);
        if (size % 2 == 0) { // size is even
                merge_sort(ary + middlePos, middlePos);
        }else {
                merge_sort(ary + middlePos, middlePos + 1);
        }
 // We need to merge!
        int s1pos = 0;
        int s2pos = middlePos;
        int pos = 0;
	int temp[size];

 for (pos = 0; pos < size; pos++) {
     if ((s2pos >= size) || (s1pos < middlePos && ary[s1pos] < ary[s2pos])) {
         temp[pos] = ary[s1pos];
         s1pos++;
     } else {
         temp[pos] = ary[s2pos];
         s2pos++;
     }
}
        for(int i = 0; i < size; i++){
                ary[i] = temp[i];
        }
}
#endif
