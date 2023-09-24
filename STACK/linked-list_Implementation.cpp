#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

class Stack
{
private:
    Node* top;
public:
    Stack(){
        top = NULL;
    }
    void push(int x);
    void pop();
    bool IsEmpty();
    int peek();
    void print();
};

void Stack:: push(int x){
    Node* new_node = new Node();
    new_node->data = x;
    new_node->next = top;
    top = new_node;
}
void Stack:: pop(){
    if(top == NULL){
        cout << "stack underflow";
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}
void Stack:: print(){
    Node* temp = top;
    cout << "\n Stack is:";
    while(temp != NULL){
        cout << temp->data<<" ";
        temp = temp->next;
    }
}
bool Stack::IsEmpty(){
    if (top == NULL){
        return true;
    }
    return false;
}
int Stack::peek(){
    return top->data;
}
int main(){
    Stack S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    S.pop();
    S.print();
    cout << "\n"<<S.IsEmpty();
    cout << "\n"<<S.peek();
    return 0;
}


