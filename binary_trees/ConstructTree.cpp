// Construct Tree from postorder and inorder
#include <iostream>
#include "BinaryTree.h"
#include <bits/stdc++.h>
using namespace std;

BinaryTreeNode<int> *constructTreeHelper(vector<int> &postOrder, vector<int> &inOrder, int postStart, int postEnd, int inStart, int inEnd, map<int, int> &inMap)
{
    if (postEnd < postStart || inEnd < inStart)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postOrder[postEnd]);
    int inRoot = inMap[root->data];
    int numleft = inRoot - inStart;
    root->left = constructTreeHelper(postOrder, inOrder, postStart, postStart + numleft - 1, inStart, inRoot - 1, inMap);
    root->right = constructTreeHelper(postOrder, inOrder, postStart + numleft, postEnd - 1, inRoot + 1, inEnd, inMap);
    return root;
}

BinaryTreeNode<int> *constructTree(vector<int> &postOrder, vector<int> &inOrder)
{
    map<int, int> inMap;
    for (int i = 0; i < inOrder.size(); i++)
    {
        inMap[inOrder[i]] = i;
    }
    BinaryTreeNode<int> *root = constructTreeHelper(postOrder, inOrder, 0, postOrder.size() - 1, 0, inOrder.size() - 1, inMap);
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
    vector<int> inOrder = {4, 2, 5, 1, 6, 3, 7};
    vector<int> postOrder = {4, 5, 2, 6, 7, 3, 1};
    BinaryTreeNode<int> *root = constructTree(postOrder, inOrder);
    printLevelOrder(root);
}