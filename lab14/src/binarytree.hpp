#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <string>

template<class T>
class BinaryTreeNode {
    public:
        BinaryTreeNode<T> () {
		mLeft = mRight = NULL;
	}
	BinaryTreeNode<T> *mLeft, *mRight;
	T mVal;
};

template<class T>
class BinaryTree {
    private:
        /* You fill in private member data. */
	BinaryTreeNode<T> *mRoot;
	int mSize;	
        /* Recommended, but not necessary helper function. */
        void put(BinaryTreeNode<T> *rover, BinaryTreeNode<T> *newNode);
        /* Recommended, but not necessary helper function. */
        std::string inorderString(BinaryTreeNode<T> *node);
    public:

        /* Creates an empty binary tree. */
        BinaryTree();
	void deleteMe(BinaryTreeNode<T> *node);
        /* Does a deep copy of the tree. */
        BinaryTree(const BinaryTree<T> &tree);

        /* Add a given value to the Binary Tree. 
         * Must maintain ordering!
         * Do NOT do ANY balancing!
         */
        void put(const T &val);
	std::string toString(T x);
        /* Returns the height for the binary tree. */
        int getHeight();
	int getHeight(BinaryTreeNode<T> *node);
        /* Returns a string representation of the binary Tree in order. */
        std::string inorderString();

        /* Return the lowest common ancestor (LCA) of two values.
         * The LCA is the most immediate parent of both values.  For example:
         *      4
         *    /   \
         *   2     8
         *  / \   / \
         * 1   3 6   10
         * LCA(1, 3) = 2
         * LCA(1, 2) = 2
         * LCA(1, 6) = 4
         */
        T& lca(T& a, T& b);

        /* Always free memory. */
        ~BinaryTree();
	T& copyCons(BinaryTreeNode<T> *node);
};

/* Since BinaryTree is templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly 
 * declared.)
 */
#include "binarytree.cpp"

#endif
