#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>

/* HashTable via open addressing */
template<class K, class V>
class HashTable {
    struct Pair {
        K mKey;
        V mValue;
        Pair(const K key, const V value) {
            mKey = key;
            mValue = value;
        }
        bool operator==(const Pair &pair) {
            return mKey == pair.mKey;
        }
    };
    private:
        /* Class to begin filling out...*/
        int mLen;
        V mInvalid;
    public:
        /* Initialize the Hash Table with size size. */
        HashTable(const int size, const float loadFactor);

        /* Deconstructor shall free up memory */
        ~HashTable();

        /* Map key -> val.
         * Return true if sucessful (it is unique.)
         * Otheriwise return false.
         */
        bool insert(const K &key, const V &val);

        /* Print out the HashTable */
        void print() const;

        /* Remove the val associated with key.
         * Return true if found and removed.
         * Otherwise return false.
         */
        bool remove(const K &key);

        /* Retrieves the V val that key maps to. */
        V& operator[](const K &key);

        int loadFactor();
};

int hashcode(int key);
int hashcode(const std::string &key);

#include "hashtable.cpp"

#endif
