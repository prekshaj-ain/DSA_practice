// count nodes
// sum of all nodes
// node with largest data

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

int countNodes(TreeNode<int> *root)
{
    int count = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        count += countNodes(root->children[i]);
    }
    return count + 1;
}

int sum(TreeNode<int> *root)
{
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sum(root->children[i]);
    }
    return ans + root->data;
}

TreeNode<int> *largest(TreeNode<int> *root)
{
    TreeNode<int> *ans = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *subAns = largest(root->children[i]);
        if (subAns->data > ans->data)
        {
            ans = subAns;
        }
    }
    return ans;
}

int main()
{
    TreeNode<int> *root = takeInputLevelOrder();
    cout << countNodes(root) << endl;
    cout << "Sum : " << sum(root) << endl;
    cout << "Largest : " << largest(root)->data << endl;
    return 0;
}