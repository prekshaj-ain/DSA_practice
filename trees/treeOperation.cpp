#include <iostream>
#include "Tree.h"
using namespace std;
TreeNode<int> *takeInput()
{
    int rootData;
    int numChild;
    cout << "Enter data :";
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    cout << "Enter number of children of " << rootData;
    cin >> numChild;
    for (int i = 0; i < numChild; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void Print(TreeNode<int> *root)
{
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        Print(root->children[i]);
    }
}
int main()
{
    TreeNode<int> *root = takeInput();
    Print(root);

    return 0;
}