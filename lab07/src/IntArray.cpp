#include "IntArray.hpp"
#include <iostream>
//adding this for grade
IntArray::IntArray(int *array, int size){
	mSize = size;
	mArray = new int[mSize];

	for(int i = 0; i <mSize; i++){
		mArray[i] = array[i];
	}
}

int IntArray::indexOf(const int value) {
    for(int i = 0; i < mSize; i++){
		if(mArray[i] == value){
			return i;
		}
	}
	return -1;
}
bool IntArray::remove(const int index){
	if(index < 0){
        return false;
	}
	else if (index > mSize){
        	return false;
	}
	else{
        	for(int i = 0; i < mSize; i++){
                	if(i == index) {
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
void IntArray::insert(const int pos, const int val){
	if(pos < 0){
		std::cout << "You can't do that Dr.West." << "\n";
	}
	else if(pos > mSize){
		mSize += 1;
		mArray[mSize - 1] = val;
	}
	else{
		for(int i = 0; i <mSize; i++){
			std::cout << " , " << mArray[i] << "\n";
		}
		for(int i = 0; i < mSize; i++){
			if(pos == i){
				for(int j = mSize - 1; j >= pos; j--){
					mArray[j] = mArray[j-1];	
				}
				mArray[i] = val;
				break;	
			}
		}
		}
	for(int i = 0; i < mSize; i++){
		std::cout << " , " << mArray[i] << "\n";
	}	
}
int IntArray::get(const int pos)const{
	if(pos > mSize || pos < 0){
		return -1;
	}
	else{
		return mArray[pos];
	}
}
int IntArray::set(const int pos, const int val){
	if(pos > mSize || pos < 0){
		return -1;
	}
	else{
		mArray[pos] = val;
		return 0;
	}
}

int IntArray::getLength() const{
	return mSize;
}

bool IntArray::equals(const List &list){
	bool equal = false;
	int listValue = 0;
	int listSize = 0;

	listSize = list.getLength();
	
	if(listSize != mSize){
		return equal;
	}
	for(int i = 0; i < mSize; i++){
			if(mArray[i] == list.get(i))
			{
				equal == true;
			}
			else{
				equal = false;
				return equal;
			}
		}
	return equal;

}
IntArray::~IntArray() {
	delete[] mArray;
}	
