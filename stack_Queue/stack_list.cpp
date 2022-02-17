/* Problem Statement : Built Stack from scratch using Linked List

Time complexity : O(1) for push, pop, peek, isEmpty operations.
Space Complexity : O(N) where N size of stack 
The stack is easy to implement asa well as dynamic in nature
*/

#include <iostream>
using namespace std;
class Node{

    public:
    int data;
    Node *next;
    Node(int data){

        this -> data = data;
        this -> next = NULL;
    }
};
//push insert at front, and head of the list will be the top of stack

void push(Node * &head, int data){

    Node *newnode = new Node(data);
    newnode -> next = head;
    head = newnode;
}

void pop(Node * &head){

    if (head == NULL)
        cout << "Stack is Empty" << endl;
            
        //pop the element from stack (head of the list)
        else{

            Node* temp = head;
            head = head -> next;

            //to avoid memory leak 
            temp -> next = NULL;
            delete temp;
        }
}

int peek(Node *head){

    if (head == NULL)
        return -1;

    return head -> data;
}

bool isEmpty(Node *head){

    if (head == NULL)
        return true;
            
    return false;
}


int main(){

    Node *top = NULL;

    //check empty list
    cout << isEmpty(top) << endl;

    //push nodes
    push(top, 45);

    //get top of stack
    cout << "top of stack: " << peek(top) << endl;

    push(top, 46);
    cout << isEmpty(top) << endl;

    //get top of stack
    cout << "top of stack: " << peek(top) << endl;

    //pop the element from stack and get peek
    pop(top);

    //get top of stack
    cout << "top of stack: " << peek(top) << endl;

    //check empty stack
    pop(top);
    pop(top);
    return 0;
}
