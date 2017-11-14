#include "IntArray.hpp"
#include <iostream>

/* Copy array’s contents to an internal array, (length = size). 
 * Do a deep copy!
 */
IntArray::IntArray(int *array, int size) {
    mSize = size;
    mArray = new int[mSize];

    for (int i = 0; i < mSize; i++) {
        mArray[i] = array[i];
    }
}

// Testing function
int IntArray::get(int index) {
    return mArray[index];
}

void IntArray::print(){
	for(int i = 0; i < mSize; i++){
		std::cout << mArray[i] << " ,";
	}
}

IntArray::~IntArray() {
    delete[] mArray;
}

int IntArray::getLength() {
    return mSize;
}
int IntArray::indexOf(int value){
	for(int i = 0; i < mSize; i++){
		if(mArray[i] == value)
		{
			return i;
		}
	}
	return -1;

}
bool IntArray::remove(int index){
	if(index < 0){
        	return false;
	}
	else if (index > mSize){
        	return false;
	}
	else{
        	for(int i = 0; i < mSize; i++){
                	if(i == index) {
                		for(int j = i; j < (mSize - 1); j++)
                		{
                        		mArray[j] = mArray[j+1];

                		}
                		mArray[mSize - 1] = 0;
				mSize--;
                		return true;
        		}		
		}
		return false;
	}
}
IntArray* IntArray::findIntersections(IntArray &ary){
	int arySize = ary.getLength();
	std::cout << arySize << "\n";
	int index = 0;
	int arraySize = 0;
	if(mSize >= arySize){
		arraySize = mSize; 
	}
	else{
		arraySize = arySize;
	}
	int array[arraySize];
	//for(int i = 0; i < mSize; i++){
		//std::cout << "Value of mArray: " << mArray[i] << "\n";
	//}
	//for (int i = 0; i <arySize; i++){
		//std::cout << "value of ary: " << ary.mArray[i] << "\n";
	//}
	//std::cout << "Made it after array[arraySize] was made" << "\n";
	for(int i = 0; i < mSize; i++){
	//std::cout << "Made it into the first loop" << "\n";
		for(int j = 0; j < arySize; j++){
		//std::cout << "Made it into the second loop" << "\n";
			if(mArray[i] == ary.mArray[j]){
				//std::cout << "Assinging has begun" << "\n";
				//std::cout << "ary.mArray[j]: " << ary.mArray[j] << "\n";
				//std::cout << "index " << index << "\n";
				array[index] = ary.mArray[j];
				//std::cout << "array[index] " << array[index] << "\n";
				index++;	
			}
		} 
	}
	if(index == 0){
	IntArray *finalArray = new IntArray(array, index);
	std::cout << "No values found" << "\n";
	return finalArray;
	}
	//for(int i = 0; i < index; i++){
		//std::cout << "value is " << array[i] << "\n";
	//}
	IntArray *finalArray = new IntArray(array,(index + 1));	
	//std::cout << "About to return " << "\n";
	return finalArray;
}
bool IntArray::isSubsequence(IntArray &ary){
	int arySize = ary.getLength();
	bool isSub = true;
	if(arySize > mSize){
		return false;
	}
	for(int i = 0; i < mSize - (arySize - 1); i++){
		if(mArray[i] == ary.mArray[0]){
			for(int j = 1; j < arySize; j++){
				if(mArray[i+j] == ary.mArray[j]){
					isSub = true;
				}
				else{
					isSub = false;
					break;
				}
			} 	
		}
	}
	return isSub;
}	

