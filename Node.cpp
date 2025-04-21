#include <iostream>
using namespace std;

// Add a new student to the system (student=Node)

struct Node {
    int data;
    Node* next;
};

void insert (Node*& head, int value){
    Node* newNode = new Node;
    newNode -> data = value,
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
        return;
    }
Node* temp = head;
while(temp-> next !=NULL){
    temp = temp -> next;
}
temp->next = newNode;

};

int main(){
    Node* head = NULL;
    insert (head, 1);
    insert (head, 2);
    insert (head, 3);
    insert (head, 4);
    insert (head, 5);

    return 0;
}
