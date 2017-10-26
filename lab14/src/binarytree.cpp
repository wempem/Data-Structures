#ifdef BINARY_TREE_H

#include "binarytree.hpp"
#include <string>
#include <iostream>
template<class T>
BinaryTree<T>::BinaryTree() {
	mRoot = NULL;
}

template<class T>
BinaryTree<T>::~BinaryTree() {
	BinaryTreeNode<T> *rover = mRoot;
	delete rover->mLeft;
	delete rover->mRight;		
}

template<class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T> &tree){
	
	BinaryTreeNode<T> *rover = mRoot;
	tree->mRoot = rover;
	tree->mVal = rover->mVal;
//	tree.put(rove);
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
template<class T>
std::string BinaryTree<T>::inorderString(BinaryTreeNode<T> *node, std::string &ret){	
	
	if(node == NULL){
		return "";
	}

	ret.append(inorderString(node->mLeft));
	ret.append(str(node->mVal) + " ");
	ret.append(inorderString(node->mRight));

	return ret;
}

template<class T>
T& BinaryTree<T>::copyCons(BinaryTreeNode<T> *node){
	 
}

template <class T>
std::string BinaryTree<T>::inorderString(){
	std::string ret = "";
	return inorderString(mRoot, ret);
}

template <class T>
T& BinaryTree<T>::lca(T& a, T& b){
	
	BinaryTreeNode<T> *rover = mRoot;	
	while (rover!= NULL){
		if(rover->mVal > a && rover->mVal > b){
			rover = rover->mLeft;
		}
		else if(rover->mVal < a && rover->mVal < b){
			rover = rover->mRight;
		}
		else{break;} 	
	}
	return rover;
}

#endif 
