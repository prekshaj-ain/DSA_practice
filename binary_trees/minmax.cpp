// Minimum and Maximum in the Binary Tree

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

pair<int, int> minmax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return {INT_MAX, INT_MIN};
    }
    pair<int, int> leftans = minmax(root->left);
    pair<int, int> rightans = minmax(root->right);
    int minVal = min(root->data, min(leftans.first, rightans.first));
    int maxVal = max(root->data, max(leftans.second, rightans.second));
    return {minVal, maxVal};
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    cout << "\n MINIMUM VALUE : " << minmax(root).first;
    cout << "\n MAXIMUM VALUE : " << minmax(root).second;
    return 0;
}