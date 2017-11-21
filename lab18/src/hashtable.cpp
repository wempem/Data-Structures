#ifdef HASH_TABLE_H

template<class K, class V>
HashTable<K, V>::HashTable(const int size):mTable(size) {
	mTable.reserve(size);
}

template<class K, class V>
HashTable<K, V>::~HashTable() {
}

template<class K, class V>
bool HashTable<K, V>::insert(const K &key, const V &val) {
    int size = mTable.capacity(); // Gets how many elements can be stored in the array/vector.
    int index = hashcode(key); // convert the key to an integer.
    index %= size; // Size down the 'size' variable so it index into the array/vector.
    Pair toInsert;
    toInsert.mKey = key;
    toInsert.mVal = val;
    mTable[index].push_back(toInsert); // Add value to the hash table
}

template<class K, class V>
V& HashTable<K, V>::operator[](const K &key) {
    int size = mTable.capacity(); // Gets how many elements can be stored in the array/vector.
    int index = hashcode(key); // convert the key to an integer.
    index %= size; // Size down the 'size' variable so it index into the array/vector.
    // First get the list at mTable[index]
    // Search the list for the key
    // return the value associated with the key.
	
	for(typename std::list<Pair>::iterator it = mTable[index].begin(); 
		it != mTable[index].end(); it++){
	if(it->mKey == key){
		return it->mVal;
	}
	}
		
}

template <class K, class V>
bool HashTable<K, V>::remove(const K &key){
	if(mTable.capacity() == 0){
		return false;
	}
	int size = mTable.capacity();
	int index = hashcode(key);
	index %= size;
	for(typename std::list<Pair>::iterator it = mTable[index].begin();
			it != mTable[index].end(); it++){
		if(it->mKey == key){
			mTable[index].erase(it);
		return true;
		}
		}
	return false;
	}


int hashcode(int key) {
    return key;
}

int hashcode(const std::string &key) {
    // You need to do something else.
//	int hash = std::stoi(key, 0);
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
