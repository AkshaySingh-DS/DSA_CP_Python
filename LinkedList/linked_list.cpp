#include <iostream>
using namespace std;

class Node{

    public:
        int data;
        Node* next;

    Node(int data){

        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node * &head, int data){

    //new node at head
    Node * node = new Node(data);
    node -> next = head;
    head = node;
}

void insertAtTail(Node * &tail, int data){
    //new node at tail
    Node* node = new Node(data);
    tail -> next = node;
    tail = node;

}

void insertAtPosition(Node* &tail, Node* &head, int pos, int data){
    
    //some edge case when pos is 1 and last
    int cnt = 1;
    Node* temp = head;
    Node* node = new Node(data);

    //if pos is 1
    if (pos == 1){
        insertAtHead(head, data);
        return;
    }
    //if pos is last

    //insert at position
    while (cnt < pos-1){

        temp  = temp -> next;
        cnt++; 
    }
    //if temp is a last node then we have to update the tail pointer as well
    if (temp -> next == NULL){

        insertAtTail(tail ,data);
        return;
    }
        
    //in general case
    node -> next = temp -> next;
    temp -> next = node;
}

void printList(Node* head){

    Node* temp = head;

    while(temp){

        cout << temp -> data << "->";
        temp = temp -> next; 
    }
    cout << endl;
}

int main(){

    Node * node1 = new Node(10);

    //making head, tail to node1
    Node* head = node1;
    Node* tail = node1;

    //insert at head
    insertAtHead(head, 20);
    insertAtHead(head, 32);

    //printlist
    printList(head);

    //insert at tail
    insertAtTail(tail, 95);
    insertAtTail(tail, 82);

    //printlist
    printList(head);

    //insert At position
    insertAtPosition(tail, head, 6, 25);

    //printlist
    printList(head);

    //check the head and tail
    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl;


    return 0;
}