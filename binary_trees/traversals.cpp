// preorder
// postorder
// inorder

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

vector<int> inorder(BinaryTreeNode<int> *root)
{
    BinaryTreeNode<int> *node = root;
    stack<BinaryTreeNode<int> *> s;
    vector<int> ans;
    while (true)
    {
        if (node != NULL)
        {
            s.push(node);
            node = node->left;
        }
        else
        {
            if (s.empty())
                break;

            node = s.top();
            s.pop();
            ans.push_back(node->data);
            node = node->right;
        }
    }
    return ans;
}

vector<int> preorder(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int> *> s;
    vector<int> ans;
    s.push(root);
    while (!s.empty())
    {
        BinaryTreeNode<int> *top = s.top();
        s.pop();
        if (top->right)
            s.push(top->right);
        if (top->left)
            s.push(top->left);
        ans.push_back(top->data);
    }
    return ans;
}

vector<int> postorder(BinaryTreeNode<int> *root)
{
    stack<BinaryTreeNode<int> *> s;
    BinaryTreeNode<int> *node = root;
    vector<int> ans;
    while (node != NULL || !s.empty())
    {
        if (node != NULL)
        {
            s.push(node);
            node = node->left;
        }
        else
        {
            BinaryTreeNode<int> *temp = s.top();
            if (temp->right != NULL)
            {

                node = temp->right;
            }
            else
            {
                s.pop();
                ans.push_back(temp->data);
                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->data);
                }
            }
        }
    }
    return ans;
}

void Print(vector<int> arr)
{
    for (auto ele : arr)
    {
        cout << ele << " ";
    }
    cout << endl;
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    cout << "\nInorder : ";
    vector<int> inorderPrint = inorder(root);
    Print(inorderPrint);
    cout << "\nPreorder : ";
    vector<int> prePrint = preorder(root);
    Print(prePrint);
    cout << "\nPostorder : ";
    vector<int> postorderPrint = postorder(root);
    Print(postorderPrint);

    return 0;
}
