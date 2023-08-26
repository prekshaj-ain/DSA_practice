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

void addLeftBoundary(BinaryTreeNode<int> *node, vector<int> &res)
{
    node = node->left;
    while (node)
    {
        if (node->left == NULL && node->right == NULL)
        {
            break;
        }
        res.push_back(node->data);
        if (node->left)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
}

void addRightBoundary(BinaryTreeNode<int> *node, vector<int> &res)
{
    vector<int> temp;
    node = node->right;
    while (node)
    {
        if (node->left == NULL && node->right == NULL)
        {
            break;
        }
        temp.push_back(node->data);
        if (node->right)
        {
            node = node->right;
        }
        else
        {
            node->left;
        }
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        res.push_back(temp[i]);
    }
}

void addLeaves(BinaryTreeNode<int> *node, vector<int> &res)
{
    if (node == NULL)
        return;
    addLeaves(node->left, res);
    if (node->left == NULL && node->right == NULL)
    {
        res.push_back(node->data);
        return;
    }
    addLeaves(node->right, res);
}

vector<int> boundaryTraversal(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return {};
    vector<int> traversal;
    traversal.push_back(root->data);
    addLeftBoundary(root, traversal);
    addLeaves(root, traversal);
    addRightBoundary(root, traversal);
    return traversal;
}

void Print(vector<int> traversal)
{
    for (auto ele : traversal)
    {
        cout << ele << " ";
    }
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    vector<int> traversal = boundaryTraversal(root);
    cout << "\n";
    Print(traversal);
    return 0;
}