#ifdef SLLIST_HPP
#include <iostream>
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

    SLLNode *rover = sll.mHead;
    while (rover != NULL) {
        this->append(rover->mVal);
        rover = rover->mNext;
    }
}

/* Returns if the two lists contain the same elements in the
 * same order.*/
template<class T>
bool SLList<T>::operator==(const SLList<T> &list) const {
    SLLNode *rover = this->mHead;
    SLLNode *dover = list.mHead;

    while (rover != NULL && dover != NULL && rover->mVal == dover->mVal) {
        rover = rover->mNext;
        dover = dover->mNext;
    }
std::cout << "hi";
    return (rover == NULL && dover == NULL);
}

template<class T>
int SLList<T>::getLength() const {
    return mSize;
}

/* Insert at the end of the list.*/
template<class T>
bool SLList<T>::append(const T &val) {
    // First create the new node
    SLLNode *newNode = new SLLNode();
    newNode->mVal = val;
    newNode->mNext = NULL;

    // If the list is empty, just set head
    if (mHead == NULL) {
        mTail = mHead = newNode;
    } else {
        // Get the pointer to the last node
        // That is mTail
        // then point to the new last node
        mTail->mNext = newNode;
        mTail = newNode;
    }

    // increment size
    mSize++;
    return true;
}

/* Print out the Singly Linked List */
template<class T>
void SLList<T>::print() const {
    // Visit each node printing the value as we progress.
    SLLNode *rover = mHead; // Rover moves from one element to the next.
    while(rover != NULL) {
        std::cout << rover->mVal << ", ";
        rover = rover->mNext;
    }
    std::cout << "\n";
}
/* Insert val at position pos.
 * Return true if successful (it can be placed.)
 * Otherwise return false.
 */
template<class T>
bool SLList<T>::insert(const int pos, const T &val) {
    // We need to validate pos
    if (pos < 0 || pos > mSize) {
        return false;
    }

    if (mHead == NULL) {
        return append(val);
    }

    // Create the new node.
    SLLNode *newNode = new SLLNode();
    newNode->mVal = val;
    newNode->mNext = NULL;

    // First we get rover to the pos
    SLLNode *rover = mHead;
    for (int i = 0; i < pos - 1; i++) {
        rover = rover->mNext;
    }

    newNode->mNext = rover->mNext;
    rover->mNext = newNode;

    mSize++;
    return true;
}

/* Retrieves the element at position pos */
template<class T>
T& SLList<T>::operator[](const int pos) const {
    SLLNode *rover = mHead;

    for (int i = 0; i < pos; i++) {
        rover = rover->mNext;
    }

    return rover->mVal;
}

template<class T>
SLList<T>::~SLList() {
    SLLNode *rover = mHead;
    SLLNode *deleteMe;
    while (rover != NULL) {
        deleteMe = rover;
        rover = rover->mNext;
        delete deleteMe;
    }

    mTail = mHead = NULL;
    mSize = 0;
}

template<class T>
bool SLList<T>::removeFirst() {
    // You fill in for lab10.
   	if(mHead == NULL){
 		return false;
	}
 	SLLNode *rover = mHead->mNext;
 	delete mHead;
	mHead = rover;
	mSize--;
     	return true;
}
template<class T>
bool SLList<T>::removeLast(){
	if(mHead == NULL){
		return false;
	}
	SLLNode *rover = mHead;
	
	while (rover->mNext != mTail){
		rover = rover->mNext;
	}
	delete mTail;
	mTail = rover;
	return true;
}
#endif
