/* Problem Statement : https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937
Time Complexity :  
Space Comlpexity :  
*/
#include <iostream>
using namespace std;

//approach-1 devide list into three list and then merge them by keeping boundary cases in mind
class Node{
    public:
        int data;
        Node *next;

        //constructor
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
};

Node* sortList(Node *head){
    //create dummy heads of three list
    
    Node *head0 = new Node(-1);
    Node *head1 = new Node(-1);
    Node *head2 = new Node(-1);
    
    //crate dummy tail of three list
    Node *tail0 =  head0;
    Node *tail1 =  head1;
    Node *tail2 =  head2;
   
    Node *temp =  head;
    while (temp != NULL){
        
        int value = temp -> data;
        
        if (value == 0) {
            
            tail0 -> next = temp;
            tail0 = temp;
       }
       
        else if (value == 1) {
             tail1 -> next = temp;
             tail1 = temp;      
        } 
        
        else{
             tail2 -> next = temp;
             tail2 = temp;     
        } 

        temp = temp -> next;
    }
    
  	    
    	//first assuming we have at least one 0's, 1's, and 2's below code works but will not work if 1's is zero
        //tail0 -> next = head1 -> next;
        //tail1 -> next = head2 -> next;
        //head = head0 -> next;
    	//tail2 -> next = NULL;
    	
      	//more optimized way
     	//severity is with 1's list if that has zero node
    	if (head1 -> next != NULL) tail0 -> next = head1 -> next;
    	else tail0 -> next = head2 -> next; //this will not create any issue even 0's list is also has zero node and even 2's also zero(given list is empty)
    	
    	
    	//for normal flow, this will not create any issues even 1's is also zero
    	tail1 -> next = head2 -> next;
    
    	//but make sure 2's tail point to NULL
    	tail2 -> next = NULL;
        head = head0 -> next;
    	//delete all dummy nodes
        delete head0;
        delete head1;
        delete head2;

        return head;
    
}

//approach - 2 By counting the 0's, 1's and 2's and themn update the nodes 
/* '''
    Following is the linked list node structure
    class Node:
        def __init__(self, data):
            self.data = data
            self.next = None
'''
def count012s(head):
    cnt_zero, cnt_one ,cnt_two = 0, 0, 0
    temp = head
    while (temp != None):
        val = temp.data
        
        if val == 0:
            cnt_zero += 1
            
        elif val == 1:
            cnt_one += 1
            
        else:
            cnt_two += 1
        
        temp = temp.next
            
    return cnt_zero, cnt_one, cnt_two
    
    
def sortList(head):
    # Write your code here
    cnt_zero, cnt_one, cnt_two = count012s(head)
    temp = head
    
    while (temp != None):
        if cnt_zero != 0:
            temp.data = 0
            cnt_zero -= 1
        
        elif cnt_one != 0:
            temp.data = 1
            cnt_one -= 1
        
        else:
            temp.data = 2
            cnt_two -= 1
            
        temp = temp.next
       
    return head */
        
    
    
    
   
            
    
    
            
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
    
     

