#ifdef SCAPE_TREE_H
#define SCAPE_TREE_H
#include <cmath>
template <class T>
ScapeTree<T>::ScapeTree() {
        mRoot = NULL;
}

template<class T>
ScapeTree<T>::~ScapeTree() {
        deleteMe(mRoot);
        mRoot = NULL;
}

template<class T>
void ScapeTree<T>::deleteMe(ScapeTreeNode<T> *node){
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
void ScapeTree<T>::put(const T &val){
        // Create a new node
	ScapeTreeNode<T> *node = new ScapeTreeNode<T>(val);

// Perform BST insertion and find depth of
// the inserted node.
	int h = BSTInsertAndFindDepth(node);

// If tree becomes unbalanced
	if (h > log32(mSize)){
// Find Scapegoat
	ScapeTreeNode<T> *p = node->parent;
	while (3*size(p) <= 2*size(p->parent))
	p = p->parent;

// Rebuild tree rooted under scapegoat
	rebuildTree(p->parent);
	}

}
template <class T>
int ScapeTree<T>::getHeight(){

        ScapeTreeNode<T> *rover = mRoot;
        return getHeight(rover);

}

template <class T>
int ScapeTree<T>::getHeight(ScapeTreeNode<T> *node){

        int left, right;
        if(node == NULL){
                return -1;
        }
        left = getHeight(node->mLeft);
        right = getHeight(node->mRight);

        if(left > right){
        return left++;
        }
        else{
                return right++;
        }
}

template <class T>
bool ScapeTree<T>::contains(const T &val) const{
        contain(val, mRoot);
}

template<class T>
bool ScapeTree<T>::contain(const T &val, ScapeTreeNode<T> *node) const{
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
bool ScapeTree<T>::remove(const T &val){
        if(mRoot == val){
                exchangeRemove(mRoot);
                return true;
        }
        else
                removed(val, mRoot);
}

template <class T>
bool ScapeTree<T>::removed(const T &val, ScapeTreeNode<T> *node) {
        ScapeTreeNode<T> *Left, *Right;
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
bool ScapeTree<T>::exchangeRemove(const T &val, ScapeTreeNode<T> *node){
        ScapeTreeNode<T> *right = node->mRight;
        ScapeTreeNode<T> *left = node->mLeft;

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
std::string ScapeTree<T>::inorderString(){
        return inorderString(mRoot);
}

template <class T>
std::string ScapeTree<T>::preorderString(){
        return preorderString(mRoot);
}

template <class T>
std::string ScapeTree<T>::postorderString(){
        return postorderString(mRoot);
}

template<class T>
std::string ScapeTree<T>::postorderString(ScapeTreeNode<T> *node){
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
std::string ScapeTree<T>::preorderString(ScapeTreeNode<T> *node){
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
std::string ScapeTree<T>::inorderString(ScapeTreeNode<T> *node){
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
std::string ScapeTree<T>::toString(T x){
        std::ostringstream temp;
        temp << x;
        return temp.str();
}
template <class T>
int ScapeTree<T>::storeInArray(ScapeTreeNode<T> *node, ScapeTreeNode<T> *arr[], int i){

	if (node == NULL)
		return i;

	i = storeInArray(node->mLeft, arr, i);
	arr[i++] = node;
	return storeInArray(node->mRight, arr, i);
}
template <class T>
int ScapeTree<T>::size(ScapeTreeNode<T> *node){
	if (node == NULL)
		return 0;
	return 1 + size(node->mLeft) + size(node->mRight);
}

template <class T>
void ScapeTree<T>::rebuildTree(ScapeTreeNode<T> *u){
	int n = size(u);
	ScapeTreeNode<T> *p = u->parent;
	ScapeTreeNode<T> **a = new ScapeTreeNode<T>* [n];
	storeInArray(u, a, 0);
	if (p == NULL)
	{
	mRoot = buildBalancedFromArray(a, 0, n);
	mRoot->parent = NULL;
	}
	else if (p->mRight == u)
	{
		p->mRight = buildBalancedFromArray(a, 0, n);
		p->mRight->parent = p;
	}
	else
	{
		p->mLeft = buildBalancedFromArray(a, 0, n);
		p->mLeft->parent = p;
	}
}
template <class T>
ScapeTreeNode<T>* ScapeTree<T>::buildBalancedFromArray(ScapeTreeNode<T> **a,int i, int n){
	if (n== 0)
		return NULL;
	int m = n / 2;

// Now a[m] becomes the root of the new
// subtree a[0],.....,a[m-1]
	a[i+m]->mLeft = buildBalancedFromArray(a, i, m);

// elements a[0],...a[m-1] gets stored
// in the left subtree
	if (a[i+m]->mLeft != NULL)
		a[i+m]->mLeft->parent = a[i+m];

// elements a[m+1],....a[n-1] gets stored
// in the right subtree
	a[i+m]->mRight = buildBalancedFromArray(a, i+m+1, n-m-1);
	if (a[i+m]->mRight != NULL)
		a[i+m]->mRight->parent = a[i+m];

	return a[i+m];
}
template <class T>
int ScapeTree<T>::BSTInsertAndFindDepth(ScapeTreeNode<T> *u){
// If tree is empty
	ScapeTreeNode<T> *w = mRoot;
	if (w == NULL)
	{
		mRoot = u;
		mSize++;
		return 0;
	}

	// While the node is not inserted
	// or a node with same key exists.
	bool done = false;
	int d = 0;
	do
	{
	if (u->mVal < w->mVal)
	{
		if (w->mLeft == NULL)
		{
			w->mLeft = u;
			u->parent = w;
			done = true;
		}
		else
			w = w->mLeft;
	}
	else if (u->mVal > w->mVal){
		if (w->mRight == NULL){	
			w->mRight = u;
			u->parent = w;
			done = true;
		}
		else
			w = w->mRight;
	}
	else
		return -1;
		d++;
	}
	while (!done);

	mSize++;
	return d;
}
template <class T>
int const ScapeTree<T>::log32(int n){
	double const log23 = 2.4663034623764317;
	return (int)ceil(log23 * log(n));
}
#endif
