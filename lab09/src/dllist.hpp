#ifndef DLLIST_HPP
#define DLLIST_HPP

//#include "sllist.hpp"
template<class T>
class DLList{
	private:
	class SLLNode{
		public:
			T mVal;
			SLLNode *mNext,*mPrev;
	};
	int mSize;
	SLLNode *mHead, *mTail;
	public:
		DLList();
		DLList(const DLList<T> &dell);
		~DLList();
		int getLength() const;
		bool append(const T &val);
		bool insert(const int pos, const T &val);
		void print() const;
		bool remove(const T &val);
		T& operator[](const int pos);
		bool operator==(const DLList<T> &list) const;
};

#include "dllist.cpp"

#endif
