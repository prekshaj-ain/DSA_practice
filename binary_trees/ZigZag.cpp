#include <iostream>
#include <bits/stdc++.h>
#include "BinaryTree.h"
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

vector<vector<int>> zigzag(BinaryTreeNode<int> *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<BinaryTreeNode<int> *> q;
    bool leftToRight = true;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            int index = leftToRight ? i : size - i - 1;
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            level[index] = node->data;
        }
        leftToRight = !leftToRight;
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    cout << "\n Zig Zag Traversal : \n";
    vector<vector<int>> tree = zigzag(root);
    for (int i = 0; i < tree.size(); i++)
    {
        for (int j = 0; j < tree[i].size(); j++)
        {
            cout << tree[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}