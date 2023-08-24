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

vector<pair<int, int>> pairSumHelper(BinaryTreeNode<int> *root, int sum, unordered_set<int> &prefixSum)
{
    vector<pair<int, int>> ans;
    if (root == NULL)
        return ans;
    if (prefixSum.find(sum - root->data) != prefixSum.end())
    {
        if (sum - root->data > root->data)
        {
            ans.push_back({root->data, sum - root->data});
        }
        else
            ans.push_back({sum - root->data, root->data});
    }
    prefixSum.insert(root->data);
    vector<pair<int, int>> ansLeft = pairSumHelper(root->left, sum, prefixSum);
    ans.insert(ans.end(), ansLeft.begin(), ansLeft.end());
    vector<pair<int, int>> ansRight = pairSumHelper(root->right, sum, prefixSum);
    ans.insert(ans.end(), ansRight.begin(), ansRight.end());
    return ans;
}

void pairSum(BinaryTreeNode<int> *root, int sum)
{
    if (root == NULL)
    {
        cout << "No element found";
        return;
    }
    unordered_set<int> prefixSum;
    vector<pair<int, int>> ans = pairSumHelper(root, sum, prefixSum);
    for (auto sumpair : ans)
    {
        cout << "\n"
             << sumpair.first << "," << sumpair.second;
    }
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    cout << "Enter sum: ";
    int sum;
    cin >> sum;
    pairSum(root, sum);
    return 0;
}