#include <iostream>
using namespace std;
#include "DynamicQueue.h"

int main()
{
    DynamicQueue<int> Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);
    Q.enqueue(60);
    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;
    cout << Q.dequeue() << endl;
    Q.enqueue(70);
    Q.enqueue(80);
    cout << Q.front() << endl;

    return 0;
}