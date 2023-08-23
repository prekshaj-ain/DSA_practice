#include "BinaryTree.h"
#include <iostream>
using namespace std;

class BST
{
    BinaryTreeNode<int> *root;
    bool searchHelper(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
            return false;
        if (root->data == data)
            return true;
        if (root->data > data)
        {
            return searchHelper(root->left, data);
        }
        if (root->data < data)
        {
            return searchHelper(root->right, data);
        }
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }
    bool search(int data)
    {
        return searchHelper(root, data);
    }
};