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

bool search(BinaryTreeNode<int> *root, int num)
{
    if (root == NULL)
        return false;
    if (root->data == num)
        return true;
    if (root->data > num)
        return search(root->left, num);
    if (root->data < num)
        return search(root->right, num);
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    cout << "\n Enter number to search : ";
    int num;
    cin >> num;
    cout << "\n Is number exist :" << search(root, num);
    return 0;
}