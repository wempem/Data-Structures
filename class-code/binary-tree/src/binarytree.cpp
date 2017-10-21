#include "binarytree.hpp"
#include <iostream>

BinaryTree::BinaryTree() {
    mRoot = NULL;
}

BinaryTree::~BinaryTree() {
    // TODO: Finish later
}

void BinaryTree::insert(int val) {

    // 1) Create a node with value
    BinaryTreeNode *newNode = new BinaryTreeNode();
    newNode->mVal = val;

    // 2) If empty set the root to the new node and exit
    if (mRoot == NULL) {
        mRoot = newNode;
        return;
    }

    // 3) Find the location of the new node
    BinaryTreeNode *rover = mRoot;
    // All values are unique.
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

    // 4) Insert into the location
    if (rover->mVal < val) {
        rover->mRight = newNode;
    } else {
        rover->mLeft = newNode;
    }
}

bool BinaryTree::remove(int val) {
}

bool BinaryTree::exists(int val) {
    // 1) iterate through Binary Tree going left & right.
    BinaryTreeNode *rover = mRoot;
    // All values are unique.
    while (rover != NULL) {

        // 2) Check val at each position/node, if found return true.
        if (rover->mVal == val) {
            return true;
        }

        if (rover->mVal > val) {
            rover = rover->mRight;
        } else if (rover->mVal < val) {
            rover = rover->mLeft;
        }
    }

    // 3) return false
    return false;
}

std::string BinaryTree::inorderTraversal() {
    return inorderTraversal(mRoot);
}

std::string BinaryTree::inorderTraversal(BinaryTreeNode *node) {
    std::string ret = "";
    // FIRST TAKE CARE OF THE BASE CASE!!!
    // 1) Check if node is NULL, then return
    if (node == NULL) {
        return "";
    }

    // 2) Go down left subtree
    ret.append(inorderTraversal(node->mLeft));

    // 3) Print the node
    ret.append(std::to_string(node->mVal) + " ");

    // 4) Go down right subtree
    ret.append(inorderTraversal(node->mRight));

    return ret;
}
