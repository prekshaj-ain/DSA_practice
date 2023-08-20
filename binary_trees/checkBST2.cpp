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

bool isBSThelper(BinaryTreeNode<int> *root, int min, int max)
{
    if (root == NULL)
        return true;
    bool output = isBSThelper(root->left, min, root->data - 1) && isBSThelper(root->right, root->data, max) && (root->data > min && root->data <= max);
    return output;
}

bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    return isBSThelper(root, INT_MIN, INT_MAX);
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    cout << "\n IS BST ? " << isBST(root);
    return 0;
}