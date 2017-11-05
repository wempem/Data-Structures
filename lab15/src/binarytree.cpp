#ifdef BINARY_TREE_H
#define BINARY_TREE_H

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
		else if(node->mRight == NULL && node->mLeft == NULL){
			return false;
		}

template <class T>
bool BinaryTree<T>::remove(const T &val){

}

template <class T>
bool BinaryTree<T>::existsInRange(T min, T max) const{

}

template <class T>
std::string BinaryTree<T>::inorderString(){
	std::string ret = "";
	return inorderString(mRoot, ret);
}

template <class T>
std::string BinaryTree<T>::preorderString(){

}

template <class T>
std::string BinaryTree<T>::postorderString(){

}

template <class T>
void inorderTraversal(void (*visit) (T &item)){

}

template<class T>
std::string BinaryTree<T>::inorderString(BinaryTreeNode<T> *node, std::string &ret){
        if(node == NULL){
                return "";
        }

        ret.append(inorderString(node->mLeft));
        ret.append(to_string(node->mVal) + " ");
        ret.append(inorderString(node->mRight));

        return ret;
}

#endif
