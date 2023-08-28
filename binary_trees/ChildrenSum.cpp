// convert binary tree to a tree which satisfy children sum property
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
void Print(BinaryTreeNode<int> *root)
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
    Print(root->left);
    Print(root->right);
}

void ChildrenSum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;
    int childSum = 0;
    if (root->left)
        childSum += root->left->data;
    if (root->right)
        childSum += root->right->data;
    if (childSum < root->data)
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    else
    {
        root->data = childSum;
    }
    ChildrenSum(root->left);
    ChildrenSum(root->right);

    int totalSum = 0;
    if (root->left)
        totalSum += root->left->data;
    if (root->right)
        totalSum += root->right->data;

    root->data = totalSum;
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    ChildrenSum(root);
    Print(root);
    return 0;
}