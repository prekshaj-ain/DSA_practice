// find height of tree
// depth of node
// count leaf nodes

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

int height(TreeNode<int> *root)
{
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int subAns = height(root->children[i]);
        if (subAns > ans)
            ans = subAns;
    }
    return ans + 1;
}

void printAtDepthD(int d, TreeNode<int> *root)
{
    if (d == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printAtDepthD(d - 1, root->children[i]);
    }
}

int main()
{
    TreeNode<int> *root = takeInputLevelOrder();
    cout << "Height : " << height(root) << endl;
    cout << "Depth 2 : ";
    printAtDepthD(2, root);
    return 0;
}