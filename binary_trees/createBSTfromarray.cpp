#include <iostream>
#include "BinaryTree.h"
#include <bits/stdc++.h>
using namespace std;

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

BinaryTreeNode<int> *createBSThelper(int *arr, int s, int e)
{
    if (s > e)
        return NULL;
    int m = s + (e - s) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[m]);
    root->left = createBSThelper(arr, s, m - 1);
    root->right = createBSThelper(arr, m + 1, e);
    return root;
}

BinaryTreeNode<int> *createBST(int *arr, int n)
{
    return createBSThelper(arr, 0, n - 1);
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    BinaryTreeNode<int> *root = createBST(arr, n);
    Print(root);
    delete[] arr;
    return 0;
}