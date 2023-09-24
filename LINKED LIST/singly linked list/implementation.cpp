#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node *head = NULL;
void insertAtEnd(int x){
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
void insertAtBegin(int x){

    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}
void display(){

    Node* temp;
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
}
void deleteEnd(){
    if(head ==  NULL){
        cout << "underflow";
        return;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    temp->next = NULL;
}
void deleteBegin(){
    if(head == NULL){
        cout << "underflow";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;

}
void insertAt(int x,int n){
    Node* temp = head;
    int count = 1;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }
    if(count < n  && n < 1){
        cout << "\ninvalid position";
        return;
    }
    temp = head;
    for(int i=1;i<n-1;i++){
        temp = temp->next;
    }
    Node *new_node = new Node();
    new_node->data = x;
    new_node->next = temp->next;
    temp->next = new_node;


}
void deleteN(int n){
    Node* temp = head;
    Node* prev = NULL;
    if(temp!=NULL && temp->data == n){
        head = temp->next;
        delete temp;
        return;
    }
    while(temp->next !=NULL){
        if(temp->next->data == n){
            prev = temp;
            temp = temp->next;
            prev->next = temp->next;
            delete temp;
            return;
        }
        temp = temp->next;
    }
    cout << "\n value doesnot exist";
}
int main(){
    insertAtBegin(5);
    insertAtEnd(1);
    insertAtBegin(4);
    insertAtEnd(7);
    insertAt(10,4);
    deleteN(10);
    // deleteBegin();
    display();
    return 0;
}
