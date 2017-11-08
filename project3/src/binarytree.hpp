#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <sstream>
#include <string>
//code taken from http://www.sanfoundry.com/cpp-program-implement-avl-trees/
template<class T>
class BinaryTreeNode {
    public:
        BinaryTreeNode<T> () {
        mLeft = mRight = NULL;
        }
        BinaryTreeNode *mLeft, *mRight;
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
        std::string postorderString(BinaryTreeNode<T> *node);
        std::string preorderString(BinaryTreeNode<T> *node);
        public:

        /* Creates an empty binary tree. */
        BinaryTree();
	
        /* Does a deep copy of the tree. */
        BinaryTree(const BinaryTree<T> &tree);

        /* Add a given value to the Binary Tree.
         * Must maintain ordering!
         * Do NOT do ANY balancing!
         */
        void put(const T &val);
        void deleteMe(BinaryTreeNode<T> *node);
        /* Returns the height for the binary tree. */
        int getHeight();
        int getHeight(BinaryTreeNode<T> *node);
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
	bool removed(const T& val, BinaryTreeNode<T> *node);
        bool exchangeRemove(const T& val, BinaryTreeNode<T> *node);
        /* Returns a string representation of the binary Tree in order. */
        std::string inorderString();

        /* Returns a string representation of the binary Tree pre order. */
        std::string preorderString();

        /* Returns a string representation of the binary Tree post order. */
        std::string postorderString();

        /* Does an inorder traversal of the Binary Search Tree calling
         * visit on each node.
         */
     
        bool contain(const T&, BinaryTreeNode<T> *node) const;
        bool exists(T min, T max, BinaryTreeNode<T> *node) const;
        int count(T min, T max, BinaryTreeNode<T> *node) const;
        
	
        int diff(BinaryTreeNode<T> *node);
        BinaryTreeNode<T>* rr_rotation(BinaryTreeNode<T> *node);
        BinaryTreeNode<T>* ll_rotation(BinaryTreeNode<T> *node);
        BinaryTreeNode<T>* lr_rotation(BinaryTreeNode<T> *node);
        BinaryTreeNode<T>* rl_rotation(BinaryTreeNode<T> *node);
        BinaryTreeNode<T>* balance(BinaryTreeNode<T> *node);
        BinaryTreeNode<T>* insert(BinaryTreeNode<T> *node, T val);
        void display(BinaryTreeNode<T> *node, T val);
	/* Always free memory. */
        ~BinaryTree();
};

/* Since BinaryTree is templated, we include the .cpp.
 * Templated classes are not implemented until utilized (or explicitly
 * declared.)
 */
#include "avl.cpp"

#endif
