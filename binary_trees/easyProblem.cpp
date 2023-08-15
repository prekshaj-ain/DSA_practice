// count nodes
// is node present
// height of tree
// mirror binary tree

#include <iostream>
#include <bits/stdc++.h>
#include "BinaryTree.h"
using namespace std;

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

int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int countleft = countNodes(root->left);
    int countRight = countNodes(root->right);
    return 1 + countleft + countRight;
}

bool isPresent(BinaryTreeNode<int> *root, int val)
{
    if (root == NULL)
        return false;
    else if (root->data == val)
        return true;
    bool subAns = isPresent(root->left, val);
    if (subAns)
        return true;
    bool subAns2 = isPresent(root->right, val);
    if (subAns2)
        return true;
    return false;
}

int heightOfTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int rightHeight = heightOfTree(root->right);
    int leftHeight = heightOfTree(root->left);
    return 1 + max(rightHeight, leftHeight);
}

void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
}
int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    cout << "\n Number of nodes: " << countNodes(root);
    /* cout << "\n enter number to be searched : ";
    int val;
    cin >> val;
    cout << "\n"
         << isPresent(root, val); */
    cout << "\n Height of the tree : " << heightOfTree(root);
    cout << endl;
    printLevelOrder(root);
    mirrorBinaryTree(root);
    cout << endl;
    printLevelOrder(root);
}