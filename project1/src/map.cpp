#include "map.hpp"
#include <iostream>

// Sad to admit, my code does not work. For future projects, I will start right away. Sadness Occured today Dr.West. Sadness. Despair. Humility.  

Map::Map(int size){
	mSize = size;
	idArray = new int[mSize];
	*strArray = new char[mSize];
	for(int i = 0; i < mSize; i++){
		idArray[i] = 0;
		strArray[i] = '\0';
		}
}
int Map::length(const char *key){
	int length = 0;
	for(int i = 0; *(key + i); i++){
		if(key[i] == ' ')
		{
			i++;
		}
		length = i;
	}
	return length;
}
bool Map::add(const char *key, int val){
	int kLength = length(key);
	if(key == NULL || key == '\0'){
		return false;
	}
	for(int i = 0; i < mSize; i++){
		if(idArray[i] == val){
			std::cout << "This ID has already been used: " << val << "\n";
			return false;
		}
		if(idArray[i] == 0){
			mSize++;
			increaseId();
//			increaseStr();
			char *newArray = new char[kLength + i];
			for(int j = 0; j < kLength + i; j++){
				newArray[j] = key[j];
			}
			strArray[i] = newArray;
			idArray[i] = val;
			return true;
		}
	}

}

bool Map::get(const char *key, int &ret){
   	for(int i = 0; i < mSize - 1; i++){
		for(int j = 0; j < length(key + i); j++){
			if(strArray[i][j] == key[j]){
				ret = idArray[i];
				return true;
			}			
		}
	}
	 return false;
}

int Map::size(){
    return 0;
}

bool Map::remove(const char *key){
	if(key == NULL || key == "\0"){
		return false;
	}
	for(int i = 0; i < mSize; i++){
		for(int j = 0; j < length(key + i); j++){
			if(strArray[i][j] == key[j]){
				strArray[i][j] = '\0';
				decrementId(idArray[i]);
			}
			
		}
		mSize--;
		return true;
	}
    return false;
}

int Map::howMany(const char *prefix){
	int count = 0;
	bool equals = false;
	if(prefix == NULL || prefix == '\0'){
		return false;
	}
	for(int i = 0; i < mSize; i++){
		for(int j = 0; j < length(prefix); j++){
			if(strArray[i][j] == prefix[j]){
				equals = true;
			} 
			
		}
		if(equals == true){
			count++;
		}
	}
	return count;
}


void Map::print(){
	for(int i = 0; i < mSize - 1; i++){
		std::cout << idArray[i] << "\n";
		std::cout << strArray[i] << "\n";
	}
}
void Map::decrementId(int val){
	int *temp = new int[mSize - 1];
	for(int i = 0; i < mSize; i++){
		if(idArray[i] != val){
		temp[i] = idArray[i];
		}
	}
	delete[] idArray;
	idArray = temp;
	
}
void Map::increaseId(){
	mSize++;
	int *temp = new int[mSize];
	for(int i = 0; i < mSize - 1; i++){
		temp[i] = idArray[i];
	}
	delete[] idArray;
	idArray = temp;
}

void Map::increaseStr(){
	//Tried doing this different ways, but could not go anywhere with it without a compiler error or
	// a seg fault.
	//delete[] *strArray;
	//strArray = temp;
//	char *temp = new char[(mSize*2)];
//	for(int i = 0; i < mSize*2; i++){
//		strArray[i] = temp[i];
//}
	//delete[] *strArray;
	//strArray = temp;	
}

Map::~Map(){
	delete[] *strArray;
	delete[] idArray;
	delete[] *temp;
}
