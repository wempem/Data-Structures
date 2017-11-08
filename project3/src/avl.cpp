#ifdef BINARY_TREE_H
#define BINARY_TREE_H
#include <algorithm>
#include <sstream>
template <class T>
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
		rover = balance(rover);
        } else {
                rover->mLeft = newNode;
		rover = balance(rover);
        }
}
template <class T>
int BinaryTree<T>::getHeight(){

        BinaryTreeNode<T> *rover = mRoot;
        return getHeight(rover);

}

template <class T>
int BinaryTree<T>::getHeight(BinaryTreeNode<T> *node){

        int h = 0;
	if(node != NULL){
		int l_height = getHeight(node->mLeft);
		int r_height = getHeight(node->mRight);
		int max_height = std::max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
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
        if(mRoot->mVal == val){
                exchangeRemove(val, mRoot);
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
                exchangeRemove(val ,node);

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
template <class T>
int BinaryTree<T>::diff(BinaryTreeNode<T> *temp)
{
    int l_height = getHeight(temp->mLeft);
    int r_height = getHeight(temp->mRight);
    int b_factor= l_height - r_height;
    return b_factor;
}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::rr_rotation(BinaryTreeNode<T> *node){
	BinaryTreeNode<T> *temp;
    	temp = node->mRight;
    	node->mRight = temp->mLeft;
    	temp->mLeft = node;
    	return temp;
}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::ll_rotation(BinaryTreeNode<T> *node){
	BinaryTreeNode<T> *temp;
 	temp = node->mLeft;
 	node->mLeft = temp->mRight;
 	temp->mRight = node;
 	return temp;
}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::lr_rotation(BinaryTreeNode<T> *node){
	BinaryTreeNode<T> *temp;
    	temp = node->mLeft;
    	node->mLeft = rr_rotation (temp);
    	return ll_rotation (node);
}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::rl_rotation(BinaryTreeNode<T> *node){
	BinaryTreeNode<T> *temp;
    	temp = node->mRight;
    	node->mRight = ll_rotation (temp);
    	return rr_rotation (node);	
}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::balance(BinaryTreeNode<T> *node){
	int bal_factor = diff (node);
    if (bal_factor > 1)
    {
        if (diff (node->mLeft) > 0)
            node = ll_rotation (node);
        else
            node = lr_rotation (node);
    }
    else if (bal_factor < -1)
    {
        if (diff (node->mRight) > 0)
            node = rl_rotation (node);
        else
            node = rr_rotation (node);
    }
    return node;
}
template <class T>
BinaryTreeNode<T>* BinaryTree<T>::insert(BinaryTreeNode<T> *node, T val){
	if (node == NULL)
    {
        node = new BinaryTreeNode<T>;
        node->mVal = val;
        node->mLeft = NULL;
        node->mRight = NULL;
        return node;
    }
    else if (val < node->mVal)
    {
        node->mLeft = insert(node->mLeft, val);
        node = balance (node);
    }
    else if (val >= node->mVal)
    {
        node->mRight = insert(node->mRight, val);
        node = balance (node);
    }
    return node;
}

#endif
