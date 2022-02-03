/* Problem Statement : https://www.codingninjas.com/codestudio/problems/reverse-linked-list_920513?leftPanelTab=0
Time Complexity : O(N) , Where N is the number of node in list
Space Comlpexity : O(1) using iterative and O(N) using recursion */

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/
//iterative solution
Node* reverseLinkedList(Node *head)
{
    // Write your code here 
    //if list is empty or we've single node 
    if (head == NULL || head -> next == NULL)
        return head;
    
    Node *prev = NULL; // to get the previous list
    Node *t = head; //to get the current node
    Node *forward; // to save the next list after changing current (t) to prev
    
    while (t != NULL){
        
        forward = t -> next;
        t -> next = prev;
        prev = t;
        t = forward;
    }
    
    return prev;   
}
//recursive solution -> tail recusion
Node *reverseList(Node *prev, Node *temp){
    
    //base case
    if (temp == NULL)
        return prev;
    
    //recursive case
    Node *f = temp -> next;
    temp -> next = prev;
    
    //now prev will be the temp and temp will bre the forward(f)
    return reverseList(temp, f);  
}
Node* reverseLinkedList(Node *head)
{
    // Write your code here 
    Node *prev = NULL;
    Node *temp = head;
    return reverseList(prev, temp);
    
}

/* Python Solution:
'''***************************************************************

    Following is the class structure of the LinkedListNode class:

    class LinkedListNode
        LinkedListNode(data):
            data = data
            next = None

*****************************************************************'''

def reverseLinkedList(head):
    #Write your code here.
    
    #boundary case if list is empty or we've only one node
    if head == None or head.next == None:
        return head
    
    prev, temp = None, head
    
    while temp != None:
        
        forwward = temp.next
        temp.next = prev
        prev = temp
        temp = forwward    
        
    return prev *
    
//another recursive solution by deviding list in two parts
def reverseHelper(head):
    #boundary case if list is empty or we've only one node
    if head == None or head.next == None:
        return head
    
    #devide list into two parts assume rest part will be reverse by recursion 
    #we just need to handle the only one case with head
    rest = reverseLinkedList(head.next)
    #rest is the head pointer of reversed list
    
    head.next.next = head
    head.next = None
    
    return rest
    
def reverseLinkedList(head):  
    return reverseHelper(head)/