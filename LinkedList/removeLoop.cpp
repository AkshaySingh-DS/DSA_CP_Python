/* Problem Statement : https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
Time complexity : O(N)
Space Complexity : O(1) but using map O(N) space but less complex

O(1) space approach just get the start node of cycle then remove the cycle by puuting NULL in the end of cycle.
 */
class Solution
{
    public:
    
        Node* getLoopStartNode(Node *head){
            
            Node *slow, *fast;
            slow = fast = head;

            //if fast and fast of next not null that means there is a cycle else there is no cycle 
            while (fast != NULL and fast -> next != NULL){
                 
                 fast = fast -> next -> next;
                 slow = slow -> next;
                 if (slow == fast)
                    break;
            }

            //if not cycle then 
            if (fast == NULL or fast -> next == NULL)
                return NULL;

            //means there is a cycle return the start pointer of cycle     
            slow = head;
            
            //move the slow and fast with same space 
            while (slow != fast ){
                slow = slow -> next;
                fast = fast -> next;
            } 
            return slow;     
    }
    public:
    //Function to remove a loop in the linked list.
    
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *start = getLoopStartNode(head);
        
        if (start == NULL) return;
        
        Node *temp = start;
        
        while (temp -> next != start)
            temp = temp -> next;
        
        temp -> next = NULL;
    }
         
};

//cpp solution : but code is not working ? check with two nodes with cycle only two nodes
 void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
         Node *slow, *fast;
         slow = fast = head;
         
         while (fast != NULL and fast -> next != NULL){
             
             fast = fast -> next -> next;
             slow = slow -> next;
             if (slow == fast)
                break;
         }
         
         if (fast == NULL or fast -> next == NULL)
            return;
            
        slow = head;
        
        while (slow -> next != fast -> next){
            slow = slow -> next;
            fast = fast -> next;
        }
            
        fast -> next = NULL;
    }

