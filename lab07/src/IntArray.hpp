#ifndef INTARRAY_HPP
#define INTARRAY_HPP

#include "List.hpp"

class IntArray : public List{
	private:
		int *mArray;
		int mSize;
	public:
		IntArray(int *array, int size);
		int indexOf(const int value);
		bool remove(const int index);
		void insert(const int pos, const int val);
		int get(const int pos) const;
		int set(const int pos, const int val);
		bool equals(const List &list);
		int getLength() const;
		~IntArray();
};

#endif
