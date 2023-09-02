// find inorder successor and predecessor of bst

#include <iostream>
#include "BinaryTree.h"
#include <bits/stdc++.h>
using namespace std;

BinaryTreeNode<int> *levelOrderInput()
{
    int rootData;
    queue<BinaryTreeNode<int> *> q;
    cout << "Enter data";
    cin >> rootData;
    if (rootData == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        cout << "Enter left child of " << front->data;
        int left;
        cin >> left;
        if (left != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(left);
            front->left = leftNode;
            q.push(leftNode);
        }
        cout << "Enter right child of " << front->data;
        int right;
        cin >> right;
        if (right != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(right);
            front->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int successor(BinaryTreeNode<int> *root, int val)
{
    int succ = -1;
    BinaryTreeNode<int> *node = root;
    while (node)
    {
        if (node->data > val)
        {
            succ = node->data;
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    return succ;
}

int predecessor(BinaryTreeNode<int> *root, int val)
{
    int pred = -1;
    BinaryTreeNode<int> *node = root;
    while (node)
    {
        if (node->data >= val)
        {
            node = node->left;
        }
        else
        {
            pred = node->data;
            node = node->right;
        }
    }
    return pred;
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    int val;
    cin >> val;
    cout << "Successor : " << successor(root, val);
    cout << "\nPredecessor : " << predecessor(root, val);
    return 0;
}