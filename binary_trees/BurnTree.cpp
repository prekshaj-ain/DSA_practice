// Minimum time to burn a tree from starting point s
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
map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parentMapping(BinaryTreeNode<int> *root)
{
    map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parent;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            BinaryTreeNode<int> *front = q.front();
            q.pop();
            if (front->left)
            {
                q.push(front->left);
                parent[front->left] = front;
            }
            if (front->right)
            {
                q.push(front->right);
                parent[front->right] = front;
            }
        }
    }
    return parent;
}
int timeToBurn(BinaryTreeNode<int> *root, BinaryTreeNode<int> *target)
{
    map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parent = parentMapping(root);
    queue<BinaryTreeNode<int> *> q;
    unordered_set<int> visited;
    vector<int> ans;
    int time = 0;
    q.push(target);
    visited.insert(target->data);
    while (!q.empty())
    {
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            BinaryTreeNode<int> *front = q.front();
            q.pop();
            if (front->left && visited.find(front->left->data) == visited.end())
            {
                q.push(front->left);
                visited.insert(front->left->data);
            }
            if (front->right && visited.find(front->right->data) == visited.end())
            {
                q.push(front->right);
                visited.insert(front->right->data);
            }
            if (parent[front] && visited.find(parent[front]->data) == visited.end())
            {
                q.push(parent[front]);
                visited.insert(parent[front]->data);
            }
        }
        time++;
    }
    return time - 1;
}
int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    cout << "\n TIME : " << timeToBurn(root, root);
    return 0;
}
