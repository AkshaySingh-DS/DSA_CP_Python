/* Problem Statement : https://leetcode.com/problems/copy-list-with-random-pointer/  
or https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1

Three approaches:
Approach-1 Naive Approach:- 
1) Create a list using next pointer
2) Now get the count for random pointer in original one and apply same in cloned one 

Time complexity : O(N^2)
Space Complexity: O(1) not considering the cloned list

Approach-2 Using map
1) Create a list using next pointer
2) Create a map of original to cloned node
3) Now append the random pointers in cloned Nodes using map

Time complexity : O(N)
Space Complexity: O(N) since we are using map, not considering the cloned list

Approach-3 By changing the links in both list (original + cloned)
1) Create a list using next pointer
2) Add the cloned node in b/w the original nodes using next pointer
3) Now add the random pointers in cloned nodes
4) revert the changes in step 2)
*/

#include <iostream>
#include <unordered_map>
using namespace std;

//approach-2
struct Node{
    int data;
    Node * next;
    Node * arb;

    Node(int x){
        data = x;
        next = NULL;
        arb = NULL;
    }

}
class Solution{
    private:
        //insert the node at tail
        void insertAtTail(Node* &head, Node* &tail, Node* original){
            
            //if list is empty
            Node *newnode = new Node(original -> data);
            if (head == NULL){
                
                head = newnode;
                tail = head;
                return;
            }
            
            tail -> next = newnode;
            tail = newnode;
        }
    
    public:
    Node *copyList(Node *head)
    {
        Node *original =  head;

        //head of the clone list
        Node *clonehead = NULL;
        Node *clonetail = NULL;
        
        //create map that will map the original to newnode
        unordered_map <Node*, Node*> nodeMap;
        
        //crating the map as well as cloning the list as well in a single loop
        while(original != NULL){
            
            insertAtTail(clonehead, clonetail, original);
            
            nodeMap[original] = clonetail;
            
            original = original -> next;
            
        }
        
        original = head;
        Node *cptr = clonehead;
        while (original != NULL){
            
            //nodeMap[original -> arb] will create issue if key not found in case of python
            //if (original -> arb != NULL){
                
            cptr -> arb = nodeMap[original -> arb];
            //}
            
            original = original -> next;
            cptr = cptr -> next;
        }
        
        return clonehead; 
};

//approach - 3 using O(1) space
class{
    private:
        void insertAtTail(Node* &head, Node* &tail, Node* original){
            
            //if list is empty
            Node *newnode = new Node(original -> data);
            if (head == NULL){
                
                head = newnode;
                tail = head;
                return;
            }
            
            tail -> next = newnode;
            tail = newnode;
        }
    
    public:
    Node *copyList(Node *head)
    {
        Node *original =  head;
        Node *clonehead = NULL;
        Node *clonetail = NULL;
        
        //step-1 creating the list from the original one
        while(original){
            
            insertAtTail(clonehead, clonetail, original);
            original = original -> next;
        }
        
        original = head;
        Node *cptr = clonehead;
        
        //step-2 adding the cloned list node in b/w the original ones
        while (original != NULL){
            
            //save the next of original
            Node *next = original -> next; 
            
            //update the orginal so that it points to the cloned list node
            original -> next = cptr;
            
            //update original again to next
            original = next;
            
            //save the next of cloned list
            next = cptr -> next;
            
            //update the cloned node so that it points to the original list node
            cptr -> next = original;
            
            //update cloned node ptr again to next
            cptr = next;
        }
        
        //step-3 update the random pointers to cloned list as well 
        original = head;
        while (original != NULL){
            
            //if original hacve the random point to some node
            
            //original -> next will be the corrsponding cloned node and random of that we want to update
            if (original -> arb != NULL)
                original -> next -> arb = original -> arb -> next ;// cloned list node where, cloned node of random correspoding to the orginal will point to 
                
            original = original -> next -> next;
            
        }
        
        //step-4 now revert back the 2nd step where we ahve added the cloned node in b/w the original nodes 
        original = head;
        
        while (original != NULL){
            
            //get the clone node
            Node *clone = original -> next;
            
            //update the original list
            original -> next = clone -> next;
            
            //update the original position 
            original = original -> next;
            
            //for last original node case original might be NULL and then null->next will create issue
            if(original != NULL)
                clone -> next = original -> next;
            
            //else clone ->next already consist the null 
        }
        
        return clonehead;
    } 

};
