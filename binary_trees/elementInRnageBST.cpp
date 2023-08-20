// Elements Between K1 and K2
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

void elementInRange(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
        return;
    if (root->data >= k1 && root->data <= k2)
    {
        cout << root->data << ",";
    }
    if (k2 > root->data)
    {
        elementInRange(root->right, k1, k2);
    }
    if (k1 < root->data)
    {
        elementInRange(root->left, k1, k2);
    }
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    int k1, k2;
    cout << "\n ENTER RANGE: ";
    cin >> k1 >> k2;
    elementInRange(root, k1, k2);
    return 0;
}