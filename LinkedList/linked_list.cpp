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
    /* ~Node(){

        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    } */
};

//insertion methods
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

//deletions methods (Assuming we have at least one node to delete)
void deleteAtFront(Node* &head){

    //assuming at least two nodes
    Node *temp = head;
    head = head -> next;
    temp -> next= NULL;
    delete temp;
}

void deleteAtPos(Node *&head, int pos){

    //if node is at front

    if(pos == 1){

        deleteAtFront(head);
        return ;
    }
    
    Node *prev = NULL;
    Node *current = head;
    int cnt = 1;
    while (cnt < pos){

        prev = current;
        current = current -> next;
        cnt++;
    } 
    //assuming we are not having any tail
    prev -> next = current -> next;
    current -> next = NULL;
    delete current;
}
bool deleteNodeByKey(Node * &head, int key){

    Node *current = head;
    Node *prev = NULL; 

    //boundruy case when data itself present at head
    if (head -> data == key){

        Node *t = head;
        head = head -> next;
        t -> next  = NULL;
        delete t; 
        return true;
    }

    while(current != NULL){

        if  (current -> data == key){
            prev -> next = current -> next;
            current -> next = NULL;
            delete current;
            return true;
        }
        prev = current;
        current  = current -> next;
    }
    return false;
}


void printList(Node* head){

    Node* temp = head;

    while(temp){

        cout << temp -> data << "->";
        temp = temp -> next; 
    }
    cout << endl;
}

int getLength(Node *head){

    Node *temp = head;
    int cnt = 0;
    while(temp){
        temp = temp -> next;
        cnt++;
    }

    return cnt;
}

Node * findMiddle(Node *head) {
    // Write your code here
    //if only one node or list is empty
    if(head -> next == NULL || head == NULL)
        return head;
    
    Node *t = head;
    int cnt = 1; 
    int length = getLength(t);
    cout << length << endl;
    
    while (cnt <= length/2){       
        t = t -> next;
        cnt++;   
    }   

    return t;
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
    //midile of list
    int l = getLength(head);
    cout << "Length of list: " << l <<endl;
    Node *middle = findMiddle(head);
    cout << "middle node : " << middle -> data << endl;

    //check the head and tail
    cout << "Head : " << head -> data << endl;
    cout << "Tail : " << tail -> data << endl;

    //delete at front
    deleteAtFront(head);

    //printlist
    printList(head);

    //delete at position
    deleteAtPos(head, 3);

    //printlist
    printList(head);
    l = getLength(head);
    cout << "Length of list: " << l <<endl;

    //delete node by key
    bool status = deleteNodeByKey(head, 82);

    if (status)  cout << "Node 82 has been deleted" << endl;
    else cout << "Node is not present" << endl;

    //printlist
    printList(head);

    //midile of list
    l = getLength(head);
    cout << "Length of list: " << l <<endl;
    middle = findMiddle(head);
    cout << "middle node : " << middle -> data << endl;

    return 0;
}