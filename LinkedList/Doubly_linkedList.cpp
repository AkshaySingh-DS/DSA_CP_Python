#include <iostream>
using namespace std;

class Node{

    public:
        int data;
        Node *prev;
        Node *next;

    //constructor to create the node
    Node(int data){

        this -> data = data;
        this -> prev = NULL;
        this -> next= NULL;
    }
};

//insertion methods
void insertAtHead(Node * &head, Node * &tail, int data){

    //when list is not empty
    Node *newNode = new Node(data);
    if (head != NULL){

        newNode -> next = head;
        head -> prev = newNode;
    }
    //if list is empty 
    else tail = newNode;

    head = newNode;
}

//insert at End , assuming we are having at least one node
void insertAtEnd(Node * &tail, int data){

    Node *newNode = new Node(data);
    tail -> next = newNode;
    newNode -> prev = tail;
    //update the tail
    tail = newNode; 
}

//insert at given position, assumning we have at least one node (in case of empty list will also work)
void insertAtPosition(Node *  &head, Node * &tail, int pos, int data){

    //case1 when pos ==> 1 insert At head
    //case2 when pos ==> end oF List insert at End
    //case3 somewhere in middle 
    
    //case1
    if(pos == 1){
        insertAtHead(head, tail,  data);
        return;
    }

    Node *current = head;
    int cnt = 1;
    
    while (cnt < pos - 1){
        current  = current -> next;
        cnt++;
    }

    //case2
    if (current -> next == NULL){

        insertAtEnd(tail, data);
        return;
    }

    //case3
    Node *newNode = new Node(data);
    newNode -> next = current -> next;
    newNode -> prev = current;
    current -> next -> prev = newNode;
    current -> next = newNode;
}

//deletion methods, assume we have at least one node to delete
void deleteHead(Node * &head, Node * &tail){

    Node *temp = head; 

    //means we have at least two nodes
    if (head != tail){

        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;   
    }
    //when we have only one node
    else head = tail = NULL;
    delete temp;

    cout << "Node has been Deleted " << endl;
}

void deleteATPosition(Node * &head, Node * &tail, int pos){

    //it handles the single node as well as pos == 1 in genral case
    if (pos == 1) deleteHead(head, tail);  
    else{

        int cnt = 1;
        Node *curr = head;

        while (cnt < pos){

            curr = curr -> next;
            cnt++;
        } 

        if (curr -> next != NULL) curr -> next -> prev = curr -> prev; // null pointerexception in case of last node
        //last node we want to delete
        else tail = curr -> prev; // no need to change tail if it is not the last node.

        //will work for both cases
        curr -> prev -> next = curr -> next; // in case of last node curr -> next will be NULL that is fine.

        //memory free statements
        curr -> prev = NULL;
        curr -> next = NULL;
        delete curr;
        
    }
}
//traverse list
void printList(Node * &head, Node * &tail){

    Node *temp = head;


    if(head == NULL) cout << "List is Empty" << endl;
    
    //for non empty list
    while(temp != NULL){

        cout << temp -> data << " ";
        temp = temp -> next;   
    }cout << endl;

}

int main(){

    Node *head = NULL;
    Node *tail = NULL; 

    printList(head, tail);
    insertAtHead(head , tail , 20);
    insertAtHead(head , tail , 25);
    insertAtHead(head , tail , 10);
    printList(head, tail);

    insertAtEnd(tail , 56);
    insertAtEnd(tail , 46);
    printList(head, tail);

    insertAtPosition(head, tail, 4, 48);
    printList(head, tail);

    cout << "head: " << head -> data << endl;
    deleteHead(head, tail);
    printList(head, tail); 

    deleteATPosition(head, tail, 4);
    printList(head, tail);

    return 0;
}