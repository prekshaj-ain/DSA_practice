#include <iostream>
#include <bits/stdc++.h>
#include "BinaryTree.h"
using namespace std;

class BST
{
    BinaryTreeNode<int> *root;
    bool searchHelper(BinaryTreeNode<int> *node, int data)
    {
        if (node == NULL)
            return false;
        if (node->data == data)
            return true;
        else if (node->data > data)
        {
            return searchHelper(node->left, data);
        }
        else
        {
            return searchHelper(node->right, data);
        }
    }
    BinaryTreeNode<int> *insertHelper(BinaryTreeNode<int> *root, int data)
    {
        BinaryTreeNode<int> *node = new BinaryTreeNode<int>(data);
        if (root == NULL)
        {
            return node;
        }
        if (root->data <= data)
        {
            root->right = insertHelper(root->right, data);
            return root;
        }
        if (root->data > data)
        {
            root->left = insertHelper(root->left, data);
            return root;
        }
        return root;
    }
    void PrintHelper(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " : ";
        if (root->left)
        {
            cout << "L" << root->left->data << " ";
        }
        if (root->right)
        {
            cout << "R" << root->right->data << " ";
        }
        cout << endl;
        PrintHelper(root->left);
        PrintHelper(root->right);
    }
    BinaryTreeNode<int> *deleteHelper(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL)
            return NULL;
        if (root->data > data)
        {
            root->left = deleteHelper(root->left, data);
            return root;
        }
        else if (root->data < data)
        {
            root->right = deleteHelper(root->right, data);
            return root;
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }
            else if (root->left == NULL)
            {
                BinaryTreeNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                BinaryTreeNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else
            {
                BinaryTreeNode<int> *minNode = root->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                root->data = rightMin;
                root->right = deleteHelper(root->right, rightMin);
                return root;
            }
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
    void insert(int data)
    {
        root = insertHelper(root, data);
    }
    void Print()
    {
        PrintHelper(root);
    }
    void deleteData(int data)
    {
        root = deleteHelper(root, data);
    }
};