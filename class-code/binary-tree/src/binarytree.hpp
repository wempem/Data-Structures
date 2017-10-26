#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <stdlib.h>
#include <string>

class BinaryTreeNode {
    public:
        BinaryTreeNode() {
            mVal = 0;
            mLeft = mRight = NULL;
        }
        BinaryTreeNode *mLeft, *mRight;
        int mVal;
};

class BinaryTree {
    private:
        BinaryTreeNode *mRoot;
        int mSize;
        std::string inorderTraversal(BinaryTreeNode *node);
    public:
        BinaryTree();
        ~BinaryTree();
        void insert(int val);
        bool remove(int val);
        bool exists(int val);
        std::string inorderTraversal();
};

#endif
