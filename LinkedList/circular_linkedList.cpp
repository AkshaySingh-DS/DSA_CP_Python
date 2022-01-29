#include <iostream>
using namespace std;

//in circular list there is nothing like a head/tail just for simplicity we are 
//taking one pointer that is tail which is pointing to some node in list
class Node{

    public:
        int data;
        Node *next;

    Node(int data){

        this -> data = data;
        this -> next = NULL;

    } 
};

//insert node after some value not position since this list is a circular list
void insertNode(Node* &tail, int key, int data){

    Node *newNode = new Node(data);

    //empty list
    if (tail == NULL){

        tail = newNode;
        tail -> next = newNode;
    }
    //we have at least one node in list
    else{

        Node *current  = tail;

        while (current -> data != key)  current = current -> next;

        newNode -> next = current -> next;
        current -> next = newNode;

    }
}

//deletion of a given node, assuming we have at least one node, assuming we also have the data present in the list
void deleteNode(Node * &tail, int data){

    Node *prev = tail;
    Node *current = tail -> next;

    //case2: if we have at least 2 node (general case)
    //case1 : if we have single node then (current and prev point to same)
    if(current == prev){
        tail = NULL;
        current -> next = NULL;
        delete current;
    }

    else{
        
        while(current -> data != data){

            prev = current;
            current = current -> next;
        }

        //if current is a tail then update the tail also (since it is a circular list then 
        //tail can point to any other node)
        if(current == tail){
            //save the tail pointer
            tail = prev;
        }
        prev -> next = current -> next;
        current -> next = NULL;
        delete current;
    }

}

//traverse the circular list
void printList(Node * &tail){

    //empty list
    if (tail == NULL){
        cout << "List is empty" << endl;
        return;
    }
        

    Node *temp = tail;

    //if we have only one node oin list so we also handle that boundary case
    do{
        cout << temp -> data << " ";
        temp = temp -> next; 
    } while(temp != tail);
    cout << endl;
}

int main(){

    Node *tail = NULL;

    printList(tail);
    insertNode(tail, 4, 22);
    printList(tail);

    insertNode(tail, 22, 20);
    insertNode(tail, 22, 12);
    printList(tail);

    insertNode(tail, 20, 35);
    insertNode(tail, 22, 10);
    printList(tail);

    deleteNode(tail, 10);
    printList(tail); 

    return 0;
}