#include <iostream>
int countNegatives(const int array[], int size) {
    int sum = 0;
	for (int i = 0; i < size; i++){
		if(array[i] < 0){
			sum++;
		}
	}
	return sum;
}

int findMinOdd(const int array[], int size) {
	int oddValue = 0;
	bool firstTime = true;
	for(int i =  0; i < size; i++){
		int nE = array[i +1];
		if(!(array[i] % 2 == 0)){
			if((firstTime == true) && (oddValue < array[i])){
			oddValue = array[i];
			firstTime = false;			
			}
			else if(oddValue > array[i]){
				oddValue = array[i];
			}
				
		}
    
	}
	if(oddValue == 0)
		oddValue = -1;
	return oddValue;
}

int search(const int array[], int size, int value) {
	for(int i = 0; i < size; i++){
		if(array[i] == value)
		{
			return i;
		}
	}	
    return -1;
}
bool remove(int array[], int size, int index){
	if(index < 0){
		return false;
	}
	else if (index > size){
		return false;
	}
	else{
		for(int i = 0; i < size; i++){
			if(i == index) {
			for(int j = i; j < (size - 1); j++)
			{
				array[j] = array[j+1];
				
			}
			array[size - 1] = 0;
			return true;
		}
	}
	return false;
}
}
