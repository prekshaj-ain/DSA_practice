#include<iostream>
using namespace std;
#define MAX_SIZE 101
class Stack
{
private:
    int A[MAX_SIZE];
    int top;
public:
    Stack(){
        top = -1;
    }
    void push(int x);
    void pop();
    int peek();
    void print();
    bool IsEmpty();
};
void Stack::push(int x){
    if(top >= MAX_SIZE-1){
        cout << "\nSTACK OVERFLOW";
        return;
    }
    A[++top] = x;
}
void Stack::pop(){
    if(top == -1){
        cout << "\nSTACK UNDERFLOW";
        return;
    }
    top--;
}
int Stack::peek(){
    return A[top];
}
bool Stack::IsEmpty(){
    if(top == -1){
        return true;
    }
    return false;
}
void Stack::print(){
    cout << "Stack is:";
    for(int i=0;i<=top;i++){
        cout << A[i]<<" ";
    }
}
int main(){
    Stack S;
    S.push(1);
    S.push(2);
    S.push(3);
    S.print();
    S.pop();
    S.print();
    cout << S.peek();
    return 0;
}



