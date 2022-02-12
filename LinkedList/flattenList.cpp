/*Problem Statement : https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_1112655
or https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
Time complexity : O(N * M)
Space Complexity: O(N) using recursion stack

where N is the all paranets and M is the child in each parant
*/

#include <iostream>
using namespace std;


class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

//merge the two sorted list
Node* merge(Node* head1, Node* head2){
    
    //base case
    if (head1 == NULL)
        return head2;
    
     if (head2 == NULL)
        return head1;
    
    //recursive case
    Node *tail;
    
    if (head1 -> data > head2 -> data){
        //noted we are using child pointer 
        tail = head2;
        tail -> child = merge(head1, head2 -> child);     
    }
    else{
        tail = head1;
        tail -> child = merge(head1 -> child, head2);       
    }
    
    //tail will be the new head of the list
    return tail;
}

//flatten the list in one sorted list using tail recursion
Node* flattenLinkedList(Node* head) {
    
    //base case
    if (head == NULL or head -> next == NULL)
        return head ;    
    
    //recursive case
    Node *down = head;
    Node *right = flattenLinkedList(head -> next);
    down -> next = NULL;
    
    
    //merge two sorted list
    Node* resulthead = merge(down , right);
    return resulthead;
}

//python iterative approach
//not working for some case

/* # List Node Class
class Node:
    def __init__(self, data):

        self.data = data
        self.next = None
        self.child = None

    def __del__(self):
        if(self.next):
            del self.next

#using iterative approach

def sortedMerge(head1, head2):
   #base case
    if head1 == None:
        return head2
    
    if head2 == None:
        return head2
    
    #recursive case
    
    if head1.data > head2.data:
        tail = head2
        tail.child = sortedMerge(head1, head2.child)
    else:
        tail = head1
        tail.child = sortedMerge(head1.child, head2)
        
    return tail
         
    
def flattenLinkedList(head):
    #write your code here
    if head == None:
        return head
    
    down = head
    right = head.next
    
    while right is not None:
        down = sortedMerge(down, right)
        
        right = right.next
        
    return down */