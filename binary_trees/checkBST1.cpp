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

pair<bool, pair<int, int>> isBSThelper(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {true, {INT_MAX, INT_MIN}};
    pair<bool, pair<int, int>> leftans = isBSThelper(root->left);
    pair<bool, pair<int, int>> rightans = isBSThelper(root->right);
    int minimum = min(root->data, min(leftans.second.first, rightans.second.first));
    int maximum = max(root->data, max(leftans.second.second, rightans.second.second));
    bool isBST = (leftans.second.second < root->data) && (rightans.second.first >= root->data) && leftans.first && rightans.first;
    return {isBST, {minimum, maximum}};
}

bool isBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    return isBSThelper(root).first;
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    cout << "\nIS BST ? " << isBST(root);
    return 0;
}