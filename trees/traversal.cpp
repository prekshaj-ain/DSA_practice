// preorder
// postorder

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

void Postorder(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        Postorder(root->children[i]);
    }
    cout << root->data << " ";
}

int main()
{
    TreeNode<int> *root = takeInputLevelOrder();
    cout << "Preorder : " << endl;
    Preorder(root);
    cout << endl;
    cout << "Postorder : " << endl;
    Postorder(root);
}