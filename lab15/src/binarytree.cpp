#ifdef BINARY_TREE_H
#define BINARY_TREE_H
#include <string>
#include <iostream>
#include <sstream>
template<class T>
BinaryTree<T>::BinaryTree() {
	mRoot = NULL;
}

template<class T>
BinaryTree<T>::~BinaryTree() {
	deleteMe(mRoot);
	mRoot = NULL;
}

template<class T>
void BinaryTree<T>::deleteMe(BinaryTreeNode<T> *node){
        if(node == NULL){
                return;
        }
        if(node->mLeft != NULL){
                deleteMe(node->mLeft);
        }
        else if(node->mRight != NULL){
                deleteMe(node->mRight);
        }
        else{
                delete node;
                return;
        }
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree){
	
}

template <class T>
void BinaryTree<T>::put(const T &val){
	BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>();
	newNode->mVal = val;

	if (mRoot == NULL) {
        	mRoot = newNode;
        	return;
	}

	BinaryTreeNode<T> *rover = mRoot;
	bool isFound = false;
	while (!isFound) {
		if (rover->mVal < val && rover->mRight != NULL) {
        		rover = rover->mRight;
		} else if (rover->mVal > val && rover->mLeft != NULL) {
        		rover = rover->mLeft;
		} else {
        		isFound = true;
		}
	}
	if (rover->mVal < val) {
        	rover->mRight = newNode;
	} else {
        	rover->mLeft = newNode;
	}
}

template <class T>
int BinaryTree<T>::getHeight(){

	BinaryTreeNode<T> *rover = mRoot;
	return getHeight(rover);

}

template <class T>
int BinaryTree<T>::getHeight(BinaryTreeNode<T> *node){

	int left, right;
	if(node == NULL){
        	return -1;
 	}
	left = findHeight(node->mLeft);
	right = findHeight(node->mRight);

	if(left > right){
        return left++;
	}
 	else{
        	return right++;
 	}
}

template <class T>
bool BinaryTree<T>::contains(const T &val) const{
	contain(val, mRoot);
}

template<class T>
bool BinaryTree<T>::contain(const T &val, BinaryTreeNode<T> *node) const{
		if(node->mVal == val){
			return true;
		}
		if(node->mLeft != NULL){
			contain(val, node->mLeft);
		}
		else if(node->mRight != NULL){
			contain(val, node->mRight);
		}
		else if((node->mRight == NULL) && (node->mLeft == NULL)){
			return false;
		}
}
template <class T>
bool BinaryTree<T>::remove(const T &val){
	if(mRoot == val){
		exchangeRemove(mRoot);
		return true;
	}
	else
		removed(val, mRoot);
}

template <class T>
bool BinaryTree<T>::removed(const T &val, BinaryTreeNode<T> *node) {
	BinaryTreeNode<T> *Left, *Right;
	Left = node->mLeft;
	Right = node->mRight;
	
	if(Left->mVal == val || Right->mVal == val){
		exchangeRemove(node);
		
	}
	else if(node->mRight != NULL){
		removed(val, node->mRight);
	}
	else if(node->mLeft != NULL){
		removed(val, node->mLeft);
	}
	else if(node->mLeft == NULL && node->mRight == NULL){
		return false;
	}
}

template <class T>
bool BinaryTree<T>::exchangeRemove(const T &val, BinaryTreeNode<T> *node){
	BinaryTreeNode<T> *right = node->mRight;
	BinaryTreeNode<T> *left = node->mLeft;
	
	if(node == mRoot){
		while(right != NULL){
			right = right->mLeft;
		}
		if(right == NULL){
			left = right;
			delete node; 
			return true;	
		}		
	}
	else if(right->mVal == val){
		node->mRight = right->mRight;
		delete right;
		return true; 
	}
	else
		node->mLeft = left->mLeft;
		delete left;
		return true;
}
template <class T>
bool BinaryTree<T>::existsInRange(T min, T max) const{
	if(mRoot->mVal >= min && mRoot->mVal <= max){
		return true;
	}
	exists(min, max, mRoot); 
}

template <class T>
bool BinaryTree<T>::exists(T min, T max, BinaryTreeNode<T> *node) const{
	if(node->mVal >= min && node->mVal <= max){
		return true;
	}
	else if(node->mRight != NULL){
		exists(min, max, node->mRight);
	}
	else if(node->mLeft != NULL){
		exists(min, max, node->mLeft);
	}
	else if(node->mLeft == NULL && node->mRight == NULL){
		return false;
	}
}

template <class T>
std::string BinaryTree<T>::inorderString(){
	return inorderString(mRoot);
}

template <class T>
std::string BinaryTree<T>::preorderString(){
	return preorderString(mRoot);
}

template <class T>
std::string BinaryTree<T>::postorderString(){
	return postorderString(mRoot);
}

template <class T>
void inorderTraversal(void (*visit) (T &item)){
	(*visit);	
}

template <class T>
int BinaryTree<T>::countInRange(T min, T max) const{
	int counter = 0;
	counter = count(min, max, mRoot);
	return counter;
}

template <class T>
int BinaryTree<T>::count(T min, T max, BinaryTreeNode<T> *node) const{
	int counter;
	if(node->mLeft == NULL && node->mRight == NULL){
		return 0;
	}
	if(node->mVal >= min && node->mVal <= max){
        	counter++;
 	}
        counter += exists(min, max, node->mRight);
        counter += exists(min, max, node->mLeft);	
	return counter;

}	 
template<class T>
std::string BinaryTree<T>::postorderString(BinaryTreeNode<T> *node){
	std::string ret = "";
	if(node == NULL){
		return "";
	}
	ret.append(postorderString(node->mLeft));
	ret.append(postorderString(node->mRight));
	ret.append(toString(node->mVal)+ " ");
	return ret;
}

template<class T>
std::string BinaryTree<T>::preorderString(BinaryTreeNode<T> *node){
	std::string ret = "";
	if(node == NULL){
		return "";
	}
	ret.append(toString(node->mVal) + " ");
	ret.append(preorderString(node->mLeft));
	ret.append(preorderString(node->mRight));
	return ret;
}

template<class T>
std::string BinaryTree<T>::inorderString(BinaryTreeNode<T> *node){
        std::string ret = "";
	if(node == NULL){
                return "";
        }

        ret.append(inorderString(node->mLeft));
        ret.append(toString(node->mVal) + " ");
        ret.append(inorderString(node->mRight));

        return ret;
}
template <class T>
std::string BinaryTree<T>::toString(T x){
	std::ostringstream temp;
	temp << x;
	return temp.str();
}
#endif
