#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
void reverse(){
    Node *prev = NULL,*curr = head;
    Node* temp = curr->next;
    while(curr->next != NULL){
        prev = temp;
        temp= temp->next;
        
    }


}
