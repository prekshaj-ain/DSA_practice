// is binary tree balanced

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

int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

pair<int, bool> heightBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {0, true};
    pair<int, bool> leftans = heightBalanced(root->left);
    pair<int, bool> rightans = heightBalanced(root->right);
    int height = max(leftans.first, rightans.first) + 1;
    if (leftans.second && rightans.second)
    {
        if (abs(leftans.first - rightans.first) > 1)
            return {height, false};
        else
            return {height, true};
    }
    return {height, false};
}

bool balanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    return heightBalanced(root).second;
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    cout << "\nIs balanced :" << balanced(root);
    return 0;
}