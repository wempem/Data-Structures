#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string>
#include <vector>
#include <list>

/* HashTable via open addressing */
template<class K, class V>
class HashTable {
    private:
        class Pair {
            public:
                K mKey;
                V mVal;
        };
        std::vector<std::list<Pair> > mTable;
    public:
        /* Initialize the Hash Table with size size. */
        HashTable(const int size);

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

};

int hashcode(int key);
int hashcode(const std::string &key);

#include "hashtable.cpp"

#endif
