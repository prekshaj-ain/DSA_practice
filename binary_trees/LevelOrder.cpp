#include <iostream>
#include <bits/stdc++.h>
#include "BinaryTree.h"
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

void printLevelOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (front->left)
        {
            cout << front->left->data << " ";
            q.push(front->left);
        }
        if (front->right)
        {
            cout << front->right->data << " ";
            q.push(front->right);
        }
    }
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    printLevelOrder(root);
    return 0;
}