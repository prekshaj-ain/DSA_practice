#include <bits/stdc++.h>
using namespace std;
#include "MinHeap.h"

int main()
{
    MinHeap<int> heap;
    heap.push(10);
    heap.push(5);
    heap.push(-5);
    cout << "\n " << heap.top();
    heap.pop();
    cout << "\n " << heap.top();

    return 0;
}