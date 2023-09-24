#include<iostream>
using namespace std;
#define MAX_SIZE 6
class Queue
{
private:
    int A[MAX_SIZE];
    int front;
    int rear;
public:
    Queue();
    bool isEmpty();
    int Front();
    void Enqueue(int x);
    bool isFull();
    int Dequeue();
    void print();
    
};
 Queue:: Queue(){
    front = -1;
    rear = -1;
}
void Queue:: print(){
  if(!isEmpty()){
      cout << "\n QUEUE IS: ";
      int i = front;
     while(i<=rear){
         cout << A[i]<<" ";
         i = (i+1)%MAX_SIZE;
     }
  }
}
int Queue:: Dequeue(){
    int value = 0;
    cout << "\ndequeueing: ";
    if(isEmpty()){
        cout << "\nUnderflow queue";
        return -1;
    }
    else if(front == rear){
        value = A[front];
        front = rear = -1;
        return value;
    }
    else{
        value = A[front];
        front = (front+1)%MAX_SIZE;
        return value;
    }

}
bool Queue::isFull(){
    if((rear+1)%MAX_SIZE == front){
        return true;
    }
    return false;
}
void Queue::Enqueue(int x){
    cout << "\n enqueueing : "<<x;
    if(isEmpty()){
        front = front+1;
        rear = rear+1;
    }
    else if(isFull()){
        cout << "Queue: overflow";
        return;
    }
    else{
        rear = (rear + 1)%MAX_SIZE;
    }
    A[rear] = x;
    
}
bool Queue::isEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }
    return false;
}
int Queue:: Front(){
    if(front == -1){
        cout << "queue is empty";
        return -1;
    }
    return A[front];
}
int main(){
    Queue Q;
    Q.Enqueue(1);
    Q.Enqueue(2);
    Q.Enqueue(3);
    Q.Enqueue(4);
    Q.Enqueue(5);
    // cout << Q.isEmpty();
    Q.print();
}



