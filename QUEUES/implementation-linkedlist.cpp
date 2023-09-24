#include <iostream>
using namespace std;
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T x)
    {
        data = x;
        next = NULL;
    }
};
template <typename T>
class Queue
{
    Node<T> *front;
    Node<T> *rear;
    int size;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
        size = 0;
    }
    ~Queue()
    {
        delete front;
        delete rear;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    void enqueue(T x)
    {
        Node<T> *new_node = new Node<T>(x);
        if (isEmpty())
        {
            front = new_node;
            rear = new_node;
            size++;
            return;
        }

        else
        {
            rear->next = new_node;
            rear = new_node;
            size++;
            return;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "\n QUEUE IS EMPTY";
            return;
        }
        else if (rear == front)
        {
            cout << "\n DEQUEUING :" << front->data;
            rear = front = NULL;
            size--;
            return;
        }
        int value;
        Node<T> *temp = front;
        front = front->next;
        value = temp->data;
        delete temp;
        size--;
        cout << "\n DEQUEUEING :" << value;
    }
    T Front()
    {
        if (!isEmpty())
        {
            return front->data;
        }
        else
        {
            cout << "\n queue is empty";
            return -1;
        }
    }
    int getSize()
    {
        return size;
    }
};
int main()
{
    Queue<int> Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.dequeue();
    cout << endl
         << Q.getSize();
    cout << endl
         << Q.Front();
    return 0;
}