#include "BinarySearchTree.h"
#include <iostream>
using namespace std;
int main()
{
    BST tree;
    tree.insert(4);
    tree.insert(5);
    tree.insert(1);
    tree.insert(2);
    tree.Print();
    cout << "\n IS 3 PRESENT:" << tree.search(3);
    tree.deleteData(4);
    cout << endl;
    tree.Print();
    return 0;
}
