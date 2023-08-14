// contains x
// count nodes greater than x
// node with maximum child sum

#include "Tree.h"
#include <iostream>
#include <queue>
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

bool containsX(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    bool ans;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = containsX(root->children[i], x);
        if (ans == true)
            return true;
    }
    return ans;
}

int countNodes(TreeNode<int> *root, int x)
{
    if (root == NULL)
        return 0;
    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNodes(root->children[i], x);
    }
    if (root->data > x)
        return count + 1;
    return count;
}

pair<TreeNode<int> *, int> maxChildSum(TreeNode<int> *root)
{
    if (root == NULL)
        return {NULL, 0};
    pair<TreeNode<int> *, int> ans;
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum += root->children[i]->data;
    }
    ans = {root, sum};
    for (int i = 0; i < root->children.size(); i++)
    {
        pair<TreeNode<int> *, int> subans = maxChildSum(root->children[i]);
        if (subans.second > ans.second)
        {
            ans = subans;
        }
    }
    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevelOrder();
    cout << containsX(root, 70);
    cout << "\nCount : " << countNodes(root, 70);
    cout << "\n Node with maximum sum : " << maxChildSum(root).first->data;
    cout << "\n Sum is : " << maxChildSum(root).second;
    return 0;
}