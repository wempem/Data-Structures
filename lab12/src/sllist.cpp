#ifdef SLLIST_HPP

template<class T>
SLList<T>::SLList() {
	mSize = 0;
	mHead = NULL;
	mTail = NULL;
}

/* Do a deep copy of sll into the this.
 * Note: This one uses a reference to a Singly Linked List!
 */
template<class T>
SLList<T>::SLList(const SLList<T> &sll) {
	mSize = 0;
	mHead = mTail = NULL;
	
	Node *rover = sll.mHead;
	while(rover != NULL){
		this->append(rover->mVal);
		rover = rover->mNext;
	}
}

template<class T>
SLList<T>::~SLList() {
	Node *rover = mHead;
	Node *deleteMe;
	while(rover != NULL){
		deleteMe = rover;
		rover = rover->mNext;
		delete deleteMe;
	}
	mTail = mHead = NULL;
	mSize = 0;
}

template<class T>
bool SLList<T>::append(const T &val) {
	
	Node *newNode = new Node();
	newNode->mVal = val;
	newNode->mNext = NULL;

	if (mHead == NULL) {
    		mTail = mHead = newNode;
	} else {
        	mTail->mNext = newNode;
    		mTail = newNode;
	}
	mSize++;
	return true;
}

template<class T>
void SLList<T>::print() const {
	Node *rover = mHead; 
	while(rover != NULL) {
    		std::cout << rover->mVal << ", ";
    		rover = rover->mNext;
	}
	std::cout << "\n";
}

/* Return the current length of the Singly Linked List */
template<class T>
int SLList<T>::getLength() const {
	return mSize;
}

/* Insert val at position pos.
 * Return true if successful (it can be placed.)
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::insert(const int pos, const T &val) {
   	if (pos < 0 || pos > mSize) {
    		return false;
	}

	if (mHead == NULL) {
    		return append(val);
	}

	Node *newNode = new Node();
	newNode->mVal = val;
	newNode->mNext = NULL;

	Node *rover = mHead;
	for (int i = 0; i < pos - 1; i++) {
    	rover = rover->mNext;
	}

	newNode->mNext = rover->mNext;
	rover->mNext = newNode;

	mSize++;
	return true;
}

/* Remove the first instance of val
 * Return true if found and removed.
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::remove(const T &val) {
     	if(mHead == NULL){
         	return false;
 	}
 	Node *rover = mHead;
 	Node *newNode = new Node();
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

template<class T>
T& SLList<T>::operator[](const int pos) const {
	Node *rover = mHead;
	for(int i = 0; i < mSize; i++){
		rover = rover->mNext;
	}
	return rover->mVal;
}
template<class T>
bool SLList<T>::operator==(const SLList<T> &list) const {
	Node *rover = this->mNext;
	Node *dover = list.mNext;
	while(rover != NULL && dover != NULL && rover->mVal == dover->mVal){
		rover = rover->mNext;
		dover = dover->mNext;
	}
	return(dover == NULL && rover == NULL);
}

template <class T>
void SLList<T>::sort(){
	Node *rover = mHead;
	Node *dover = mHead;
	Node *temp;
	while(rover != mTail->mNext){
		rover = rover->mNext;
		while(dover != mTail->mNext)
			if(rover->mVal <= dover->mVal){
				temp = dover; 	
				dover = rover;
				rover = temp;
				break;
			}
			else{
				dover = dover->mNext;
			}
		dover = mHead;
	}
}

#endif
