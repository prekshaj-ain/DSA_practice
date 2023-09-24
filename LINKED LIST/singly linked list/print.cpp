// print linked list in reverse and forward manner using recursion
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
void insert(int x){
    Node* new_node = new Node();
    new_node->data = x;
    new_node->next = NULL;
    if( head == NULL){
        head = new_node;
        return;
    }
    Node* temp = head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    return;

}
void print(Node* p){
    if(p==NULL){
        return;
    }
    cout<<p->data<<"->";
    print(p->next);
}
void reversePrint(Node* p){
    if(p==NULL) return;
    reversePrint(p->next);
    cout<<p->data<<"->";
}
int main(){
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    print(head);
    cout <<endl;
    reversePrint(head);
    return 0;
}
