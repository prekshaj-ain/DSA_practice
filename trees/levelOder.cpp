#include <iostream>
#include <queue>
#include "Tree.h"
using namespace std;

TreeNode<int> *takeInputLevelOrder()
{
    int rootData;
    cout << "Enter data";
    queue<TreeNode<int> *> q;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *front = q.front();
        int numChild = 0;
        q.pop();
        cout << "Enter number of chilren for " << front->data << " ";
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int data;
            cout << "Enter " << i << "th child data ";
            cin >> data;
            TreeNode<int> *child = new TreeNode<int>(data);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root;
}
void PrintLevelOrder(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *front = q.front();
        q.pop();
        cout << front->data << " : ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
            q.push(front->children[i]);
        }
        cout << endl;
    }
}
int main()
{
    TreeNode<int> *root = takeInputLevelOrder();
    PrintLevelOrder(root);
    return 0;
}
