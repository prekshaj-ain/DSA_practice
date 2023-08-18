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

pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {0, 0};
    pair<int, int> leftans = heightDiameter(root->left);
    pair<int, int> rightans = heightDiameter(root->right);
    int height = 1 + max(leftans.first, rightans.first);
    int diameter = max(leftans.first + rightans.first, max(leftans.second, rightans.second));
    return {height, diameter};
}

int diameter(BinaryTreeNode<int> *root)
{
    return heightDiameter(root).second;
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    cout << "\n Diameter of tree : " << diameter(root);
    return 0;
}