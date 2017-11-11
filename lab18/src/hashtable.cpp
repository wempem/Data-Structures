#ifdef HASH_TABLE_H

template<class K, class V>
HashTable<K, V>::HashTable(const int size) {
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
	while(mTable[index][i] != key){
		if(mTable[index] == key){
			return mTable[index].mVal;
		}	
	}
    // First get the list at mTable[index]
    // Search the list for the key
    // return the value associated with the key.
}

int hashcode(int key) {
    return key;
}

int hashcode(std::string key) {
    // You need to do something else.
    return 0;
}

#endif
