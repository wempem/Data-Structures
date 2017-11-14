#ifdef DLLIST_HPP

template<class T>
DLList<T>::DLList(){

	mSize = 0;
	mHead = NULL;
	mTail = NULL;
}

template<class T>
DLList<T>::DLList(const DLList<T> &dll){

	mSize = 0;
	mHead = mTail = NULL;
	SLLNode *rover = dll.mHead;
	while(rover != NULL){
		this->append(rover->mVal);
		rover = rover->mNext;
	}
}
template<class T>
DLList<T>::~DLList(){

	SLLNode *rover = mHead;
	SLLNode *deleteMe;
	while(rover != NULL){
		deleteMe = rover;
		rover = rover->mNext;
		delete deleteMe;
	}
	mTail = NULL;
	mHead = NULL;
	mSize = 0;

}
template<class T>
int DLList<T>::getLength() const{
	return mSize;
}

template<class T>
bool DLList<T>::append(const T &val){
	
	SLLNode *newNode = new SLLNode();
	newNode->mVal = val;
	newNode->mNext = NULL;
	newNode->mPrev = NULL;
	if(mHead == NULL){
		mTail = mHead = newNode;
	} else {
		mTail->mNext = newNode;
		newNode->mPrev = mTail;
		mTail = newNode;
	}
	mSize++;
	return true;

}

template<class T>
void DLList<T>::print() const{
	SLLNode *rover = mHead;
	SLLNode *dover = mTail;

	while(rover != NULL){
		std::cout << rover->mVal << ", ";
		rover = rover->mNext;
	}
	std::cout << "\n";
}

template<class T>
bool DLList<T>::insert(const int pos, const T &val){
	if(pos < 0 || pos > mSize){
         	return false;
 	}

	 if(mHead == NULL){
        	 return append(val);
 	}

	 SLLNode *rover = mHead;
	 SLLNode *newNode = new SLLNode();
	 SLLNode *posNode = mHead;
	 newNode->mVal = val;
	 newNode->mNext = NULL;
	 newNode->mPrev = NULL;

	 for(int i = 0; i < pos - 1; i++){
       		  rover = rover->mNext;
		  posNode = posNode->mNext;
 	 }
	 posNode = posNode->mNext;

 
	 posNode->mPrev = newNode;
	 newNode->mNext = posNode;
	 rover->mNext = newNode;
	 newNode->mPrev = rover;
	
	 mSize++;
	 return true;
}
template <class T>
bool DLList<T>::remove(const T &val){
        if(mHead == NULL){
                return false;
        }
        SLLNode *rover = mHead;
	SLLNode *beforePos;
        SLLNode *newNode = new SLLNode();
        newNode->mNext = NULL;

        while(rover->mVal != val){
                rover = rover->mNext;
        }

	beforePos = rover->mPrev;
        newNode = rover;
        rover = newNode->mNext;
        rover->mPrev = beforePos; 
	
	delete newNode;
        mSize--;
        return true;
}
template <class T>
bool DLList<T>::operator==(const SLList<T> &list) const {
        SLLNode *rover = this->mHead;
        SLLNode *dover = list.mHead;
        while(rover != NULL && dover != NULL && rover->mVal == dover->mVal){
                rover = rover->mNext;
                dover = dover->mNext;
        }

        return(dover == NULL && rover == NULL);
}

template <class T>
T& DLList<T>::operator[](const int pos) const{
        SLLNode *rover = mHead;
        for(int i = 0; i < pos; i++){
                rover = rover->mNext;
        }
        return rover->mVal;
}
#endif
