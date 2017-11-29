#ifdef HASH_TABLE_H

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

    // Check the load factor
    float pFull = percentFull();
    if (pFull >= mLoadFactor) {
        doubleCapacity();
    }

    return true;
}

template<class K, class V>
void HashTable<K, V>::doubleCapacity() {
    // You implement.
	int newSize = mTable->size() *2;
	HashTable<int, int> temp(newSize, mLoadFactor); 
	temp.mTable = new std::vector<std::pair<K, V>* >(newSize);
//	temp->resize(mTable->size() *2);
	
	for(typename std::vector<std::pair<K,V>* >::iterator i = mTable->begin(); i != mTable->end(); i++)	{
		temp.mTable->push_back(i->mKey, i->mVal);
	}
	mTable = temp;
	delete temp;
}

template<class K, class V>
float HashTable<K, V>::percentFull() {
    float pFull = 0.0;

    pFull = mSize; // Ensures mSize is converted to a float.
    pFull /= mTable->capacity();

    return pFull;
}

template<class K, class V>
HashTable<K, V>::~HashTable() {
}

int hashcode(int key) {
    return key;
}

int hashcode(const std::string &key) {
    // You need to do something else.
    return 0;
}

#endif
