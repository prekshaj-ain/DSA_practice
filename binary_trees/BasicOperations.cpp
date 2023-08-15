#include <iostream>
#include "BinaryTree.h"
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
BinaryTreeNode<int> *takeInput()
{
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(data);
    BinaryTreeNode<int> *left = takeInput();
    BinaryTreeNode<int> *right = takeInput();
    root->left = left;
    root->right = right;
    return root;
}
int main()
{
    BinaryTreeNode<int> *root = takeInput();
    Print(root);
}