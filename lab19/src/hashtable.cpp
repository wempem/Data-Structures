#ifdef HASH_TABLE_H
#include <iostream>
template<class K, class V>
HashTable<K, V>::HashTable(const int size, const float loadFactor) {
    mTable = new std::vector<std::pair<K, V>* >(size);
    mSize = 0;
    mLoadFactor = loadFactor;

    for (int i = 0; i < size; i++) {
        (*mTable)[i] = NULL;
    }
}

template<class K, class V>
bool HashTable<K, V>::insert(const K &key, const V &val) {
    int size = mTable->capacity(); // Gets how many elements can be stored in the array/vector.
    int index = hashcode(key); // convert the key to an integer.
    index %= size; // Size down the 'size' variable so it index into the array/vector.

    // Create the pair to add
    std::pair<K, V> *toInsert = new std::pair<K, V>(key, val);

    // Find an empty place to put the pair.
    while ((*mTable)[index] != NULL) {
        index++;
        if (index >= mTable->capacity()) {
            index = 0;
        }
    }
    // Now index is pointing to an empty location
    // If it is empty put it there.
    (*mTable)[index] = toInsert;
	std::cout << "made it";
    // Check the load factor
    float pFull = percentFull();
std::cout << pFull;
    if (pFull >= mLoadFactor) {
        std::cout << "here";
	doubleCapacity();
	
    }

    return true;
}

template<class K, class V>
void HashTable<K, V>::doubleCapacity() {
    // You implement.
	int newSize = mTable->capacity() *2;
	HashTable<K, V> temp(newSize, mLoadFactor); 
	
	for(typename std::vector<std::pair<K, V>* >::iterator i = mTable->begin(); i != mTable->end(); i++)	{
		temp.insert((*i)->first, (*i)->second);
		std::cout << (*i)->first <<  " " << (*i)->second << "\n";
	}
	mTable = temp.mTable;
	delete temp.mTable;
}

template<class K, class V>
float HashTable<K, V>::percentFull() {
    float pFull = 0.0;

    pFull = mSize; // Ensures mSize is converted to a float.
    pFull /= mTable->capacity();

    return pFull;
}

template <class K, class V>
bool HashTable<K,V>::remove(const K &key){
	if(mTable->capacity() == 0){
		return false;
	}
	for(typename std::vector<std::pair<K, V>* >::iterator i = mTable->begin(); i != mTable->end(); 	i++){
        if((*i)->first == key){
		mTable->erase(i);
		return true;
	}
	
	}
	return false;
}
template<class K, class V>
HashTable<K, V>::~HashTable() {
	mTable->clear();
}

int hashcode(int key) {
    return key;
}

int hashcode(const std::string &key) {
    // You need to do something else.
        int i = 0;
        int hash = 0;
        while(key[i] != '\0'){
                int integer = key[i];
                hash += integer;
                integer = 0;
                i++;
        }
    return hash;
}

#endif
