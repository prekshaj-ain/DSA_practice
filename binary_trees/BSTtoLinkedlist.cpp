#include <iostream>
#include "BinaryTree.h"
#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

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

pair<Node *, Node *> insert(int data, Node *head, Node *tail)
{
    Node *node = new Node(data);
    if (head == NULL)
        return {node, node};
    tail->next = node;
    tail = tail->next;
    return {head, tail};
}

Node *BSTtoList(BinaryTreeNode<int> *root)
{
    BinaryTreeNode<int> *node = root;
    stack<BinaryTreeNode<int> *> s;
    pair<Node *, Node *> ptr;
    ptr.first = NULL, ptr.second = NULL;
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
            ptr = insert(node->data, ptr.first, ptr.second);
            node = node->right;
        }
    }
    return ptr.first;
}

void PrintLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    BinaryTreeNode<int> *root = levelOrderInput();
    Node *head = BSTtoList(root);
    cout << endl;
    PrintLL(head);
    return 0;
}
