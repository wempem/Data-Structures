#ifndef MAP_HPP
#define MAP_HPP

class Map{
    private:
	int mSize;
	int *idArray;
	char *strArray[];
    public:
        Map(int size);

        /* Adds (inserts) val with the associated key.
         * Returns if successful or not. (It is not successful if we are out
         * of memory, or if the key already exists.)
        */
        bool add(const char *key, int val);

        /* Search for they key. If found it sets ret to the correct val and 
         * returns true. Otherwise this function returns false.
         */
        bool get(const char *key, int &ret);

        /*returns the size (memory consumed) by this data structure.*/
        int size();
	int length(const char *key);
        /* Removes the current value from the Map AND frees up any memory 
         * that it can.
         * Returns true if there was something to remove, false otherwise.
         */
        bool remove(const char *key);

        /* Returns the number of names with a given prefix.
         * EX: If we have {John, Jonathan, Paul, Mark, Luke, Joanna} then
         * howMany("Jo") == 3.
         */
        int howMany(const char *prefix);

	void decrementId(int val);

	void increaseId();
	
	void increaseStr();
        void print();

        /*Frees all memory*/
        ~Map();
};

#endif
