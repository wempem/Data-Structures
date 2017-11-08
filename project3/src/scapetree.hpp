#ifndef SCAPE_TREE_H
#define SCAPE_TREE_H
#include <sstream>
#include <string>
//code taken from http://www.sanfoundry.com/cpp-program-implement-avl-trees/
template<class T>
class ScapeTreeNode {
    public:
        ScapeTreeNode<T> () {
        mLeft = mRight = NULL;
	parent = NULL;
        }
        ScapeTreeNode *mLeft, *mRight, *parent;
        T mVal;
	ScapeTreeNode<T> (float v){
	mLeft = mRight = parent = NULL;
	mVal = v;
	}
};

template<class T>
class ScapeTree {
    private:
	
        /* You fill in private member data. */
        ScapeTreeNode<T> *mRoot;
        int mSize;
        /* Recommended, but not necessary helper function. */
        void put(ScapeTreeNode<T> *rover, ScapeTreeNode<T> *newNode);
        /* Recommended, but not necessary helper function. */
        std::string inorderString(ScapeTreeNode<T> *node);
        std::string postorderString(ScapeTreeNode<T> *node);
        std::string preorderString(ScapeTreeNode<T> *node);
        public:

        /* Creates an empty binary tree. */
        ScapeTree();
	
        /* Does a deep copy of the tree. */
        ScapeTree(const ScapeTree<T> &tree);

        /* Add a given value to the Binary Tree.
         * Must maintain ordering!
         * Do NOT do ANY balancing!
         */
        void put(const T &val);
        void deleteMe(ScapeTreeNode<T> *node);
        /* Returns the height for the binary tree. */
        int getHeight();
        int getHeight(ScapeTreeNode<T> *node);
        /* Returns true if an item exists in the Binary Tree */
        bool contains(const T &val) const;
        std::string toString(T x);
        /* Removes a specific val from the Binary Tree.
         * Returns true if the value exists (and was removed.)
"src/binarytree.hpp" 89L, 2987C
        bool remove(const T &val);

        * This method returns true iff there is a value in the tree
         * >= min and <= max.  In other words, it returns true if there
         * is an item in the tree in the range [min, max]
         */
        bool existsInRange(T min, T max) const;
        int countInRange(T min, T max) const;
        bool remove(const T &val);
	bool removed(const T& val, ScapeTreeNode<T> *node);
        bool exchangeRemove(const T& val, ScapeTreeNode<T> *node);
        /* Returns a string representation of the binary Tree in order. */
        std::string inorderString();

        /* Returns a string representation of the binary Tree pre order. */
        std::string preorderString();

        /* Returns a string representation of the binary Tree post order. */
        std::string postorderString();

        /* Does an inorder traversal of the Binary Search Tree calling
         * visit on each node.
         */
     
        bool contain(const T&, ScapeTreeNode<T> *node) const;
        bool exists(T min, T max, ScapeTreeNode<T> *node) const;
        int count(T min, T max, ScapeTreeNode<T> *node) const;
        
	static int const log32(int n);	
	int storeInArray(ScapeTreeNode<T> *node, ScapeTreeNode<T> *arr[], int i);	        
	int size(ScapeTreeNode<T> *node);
	void rebuildTree(ScapeTreeNode<T> *u);	
	ScapeTreeNode<T>* buildBalancedFromArray(ScapeTreeNode<T> **a, int i, int n);
	int BSTInsertAndFindDepth(ScapeTreeNode<T> *u);
	/* Always free memory. */
        ~ScapeTree();
};

/* Since BinaryTree is templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly
 * declared.)
 */
#include "scape.cpp"

#endif
