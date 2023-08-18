// Sum Of Nodes
// Level order traversal
// Remove Leaf nodes
// Nodes without sibling

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

vector<vector<int>> levelwisePrint(BinaryTreeNode<int> *root)
{
    vector<vector<int>> ans;
    queue<BinaryTreeNode<int> *> q;
    if (root == NULL)
        return ans;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            BinaryTreeNode<int> *front = q.front();
            q.pop();
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
            level.push_back(front->data);
        }
        ans.push_back(level);
    }
    return ans;
}

void Print(vector<vector<int>> tree)
{
    for (int i = 0; i < tree.size(); i++)
    {
        for (int j = 0; j < tree[i].size(); j++)
        {
            cout << tree[i][j] << " ";
        }
        cout << endl;
    }
}

int sumOfNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return root->data + leftSum + rightSum;
}

BinaryTreeNode<int> *removeLeaf(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    if (root->right == NULL && root->left == NULL)
        return NULL;
    root->left = removeLeaf(root->left);
    root->right = removeLeaf(root->right);
    return root;
}

vector<int> nodesWithoutSibling(BinaryTreeNode<int> *root)
{
    vector<int> left, right;
    if (root == NULL)
    {
        return {};
    }
    left = nodesWithoutSibling(root->left);
    right = nodesWithoutSibling(root->right);
    left.insert(left.end(), right.begin(), right.end());
    if (root->left == NULL && root->right != NULL)
    {
        left.push_back(root->right->data);
        return left;
    }
    if (root->left != NULL && root->right == NULL)
    {
        left.push_back(root->left->data);
        return left;
    }
    return left;
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    cout << "\n SUM OF NODES: " << sumOfNodes(root);
    cout << "\n NODES WITHOUT SIBLINGS: ";
    vector<int> nodes = nodesWithoutSibling(root);
    for (auto node : nodes)
    {
        cout << node << ",";
    }
    cout << endl;
    vector<vector<int>> tree = levelwisePrint(root);
    Print(tree);
    BinaryTreeNode<int> *withoutLeaf = removeLeaf(root);
    cout << "\n TREE WITHOUT LEAF NODES :\n";
    tree = levelwisePrint(withoutLeaf);
    Print(tree);
}