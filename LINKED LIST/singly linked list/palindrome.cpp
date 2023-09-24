#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* head = NULL;
Node* middle(){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* reverse(Node*p){
    Node* prevptr = NULL;
    Node *currptr = p, *nextptr;
    while(currptr != NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    return prevptr;

}
bool isPalin(){
    if(head == NULL){
        return true;
    }
    Node* mid = middle();
    Node* last = reverse(mid);
    Node* curr = head;
    while(last !=NULL){
        if(last->data != curr->data) return false;
        last = last->next;
        curr = curr->next;
        
    }
    return true;
}
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


int main(){
    insert(1);
    // insert(2);
    insert(3);
    insert(2);
    insert(1);
    bool result = isPalin();
    cout << result;

    return 0;
}