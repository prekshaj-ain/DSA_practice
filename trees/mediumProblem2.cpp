// structurally identical
// next largest
// second largest element in tree
// replace with depth

#include "Tree.h"
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
TreeNode<int> *takeInputLevelOrder()
{
    int rootData;
    queue<TreeNode<int> *> q;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *front = q.front();
        int numChild = 0;
        q.pop();

        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int data;

            cin >> data;
            TreeNode<int> *child = new TreeNode<int>(data);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}

bool identical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->data != root2->data || root1->children.size() != root2->children.size())
        return false;
    for (int i = 0; i < root1->children.size(); i++)
    {
        bool subAns = identical(root1->children[i], root2->children[i]);
        if (subAns == false)
        {
            return false;
        }
    }
    return true;
}

int nextLargest(TreeNode<int> *root, int num)
{
    if (root == NULL)
        return -1;
    int ans = INT_MAX;
    if (root->data > num)
        ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int subans = nextLargest(root->children[i], num);
        if (subans > num && subans < ans)
        {
            ans = subans;
        }
    }
    return ans;
}

pair<int, int> helper(TreeNode<int> *root)
{
    if (root->children.size() == 0)
    {
        return {root->data, INT_MIN};
    }
    pair<int, int> ans = {root->data, INT_MIN};
    for (int i = 0; i < root->children.size(); i++)
    {
        pair<int, int> subans = helper(root->children[i]);
        int temp;
        if (subans.first > ans.first)
        {
            temp = ans.first;
            ans.first = subans.first;
        }
        if (subans.second > temp)
        {
            ans.second = subans.second;
        }
        else if (subans.second < temp)
        {
            ans.second = temp;
        }
    }
    return ans;
}

int secondLargest(TreeNode<int> *root)
{
    if (root == NULL)
        return INT_MIN;
    return helper(root).second;
}

void replaceHelper(TreeNode<int> *root, int depth)
{
    root->data = depth;
    for (int i = 0; i < root->children.size(); i++)
    {
        replaceHelper(root->children[i], depth + 1);
    }
}

void replaceWithDepth(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    replaceHelper(root, 0);
}
void Preorder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        Preorder(root->children[i]);
    }
}
int main()
{
    TreeNode<int> *root1 = takeInputLevelOrder();
    /* TreeNode<int> *root2 = takeInputLevelOrder();
    cout << "Is Identical : " << identical(root1, root2); */
    // cout << "Next Largest : " << nextLargest(root1, 0);
    cout << "Second Largest : " << secondLargest(root1);
    replaceWithDepth(root1);
    cout << endl;
    Preorder(root1);

    return 0;
}