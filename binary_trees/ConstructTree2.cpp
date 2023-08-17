// Construct Tree from preorder and inorder
#include <iostream>
#include "BinaryTree.h"
#include <bits/stdc++.h>
using namespace std;

BinaryTreeNode<int> *constructTreeHelper(vector<int> &pre, vector<int> &in, int startPre, int endPre, int startIn, int endIn, map<int, int> &inMap)
{
    if (startPre > endPre || startIn > endIn)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(pre[startPre]);
    int inRoot = inMap[root->data];
    int numLeft = inRoot - startIn;

    root->left = constructTreeHelper(pre, in, startPre + 1, startPre + numLeft, startIn, inRoot - 1, inMap);
    root->right = constructTreeHelper(pre, in, startPre + numLeft + 1, endPre, inRoot + 1, endIn, inMap);
    return root;
}

BinaryTreeNode<int> *constructTree(vector<int> &pre, vector<int> &in)
{
    map<int, int> inMap;
    for (int i = 0; i < in.size(); i++)
    {
        inMap[in[i]] = i;
    }
    BinaryTreeNode<int> *root = constructTreeHelper(pre, in, 0, pre.size() - 1, 0, in.size() - 1, inMap);
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
    vector<int> pre = {5, 6, 2, 3, 9, 10};
    vector<int> in = {2, 6, 3, 9, 5, 10};
    BinaryTreeNode<int> *root = constructTree(pre, in);
    printLevelOrder(root);
}