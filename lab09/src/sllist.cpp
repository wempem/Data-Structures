#ifdef SLLIST_HPP

template<class T>
SLList <T>::SLList(){
	mSize = 0;
	mHead = NULL;
	mTail = NULL;
}

template <class T>
SLList<T>::SLList(const SLList<T> &sll){
	mSize = 0;
	mHead = mTail = NULL;
	
	SLLNode *rover = sll.mHead;
	while(rover != NULL){
		this->append(rover->mVal);
		rover = rover->mNext;
	}
}

template <class T>
bool SLList<T>::operator==(const SLList<T> &list) const {
	SLLNode *rover = this->mHead;
	SLLNode *dover = list.mHead;
	while(rover != NULL && dover != NULL && rover->mVal == dover->mVal){
		rover = rover->mNext;
		dover = dover->mNext;
	}

	return(dover == NULL && rover == NULL);
}

template <class T>
int SLList<T>::getLength() const{
	return mSize;
}

template <class T>
bool SLList<T>::remove(const T &val){
	if(mHead == NULL){
		return false;
	}
	SLLNode *rover = mHead;
	SLLNode *newNode = new SLLNode();
	newNode->mNext = NULL;

	while(rover->mVal != val){
		rover = rover->mNext;
	}
	newNode = rover;
	rover = newNode->mNext;
	delete newNode;
	mSize--;
	return true;
}

template <class T>
bool SLList<T>::insert(const int pos, const T &val){
	if(pos < 0 || pos > mSize){
		return false;
	}

	if(mHead == NULL){
		return append(val);
	}
	
	SLLNode *rover = mHead;
	SLLNode *newNode = new SLLNode();
	newNode->mVal = val;
	newNode->mNext = NULL;

	for(int i = 0; i < pos - 1; i++){
		rover = rover->mNext;
	
	}
	newNode->mNext = rover->mNext;
	rover->mNext = newNode;
	mSize++;
	return true;
}
template <class T>
bool SLList<T>::append(const T &val){

	SLLNode *newNode = new SLLNode();
	newNode->mVal = val;
	newNode->mNext = NULL;

	if(mHead == NULL){
	mTail = mHead = newNode; 
	} else {
		mTail->mNext = newNode;
		mTail = newNode;
	}
	mSize++;
	return true;
}

template <class T>
void SLList<T>::print() const{
	SLLNode *rover = mTail;
	while(rover != NULL) {
		std::cout << rover->mVal << ", ";
		rover = rover->mNext;
	}
	std::cout << "\n";
}	

template <class T>
T& SLList<T>::operator[](const int pos) const{
	SLLNode *rover = mHead;
	for(int i = 0; i < pos; i++){
		rover = rover->mNext;
	}
	return rover->mVal;
}

template <class T>
SLList<T>::~SLList(){
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

#endif
