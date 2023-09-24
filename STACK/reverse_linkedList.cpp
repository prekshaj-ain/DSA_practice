#include<iostream>
#include<stack>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* head = NULL;
stack<Node*> S;
void reverse(){
    Node* temp = head;
    while(temp != NULL){
        S.push(temp);
        temp = temp->next;
    }
    temp = S.top();
    head = temp;
    S.pop();
    while(!S.empty()){
        temp->next = S.top();
        temp = temp->next;
        S.pop();
    }
    temp->next = NULL;
}
void print(){
    Node* temp;
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}
void insert(int x){

    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

int main(){
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    reverse();
    print();

    return 0;
}