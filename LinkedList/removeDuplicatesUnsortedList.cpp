/*Problem Statement :https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1
or, https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/
Time Complexity : 
Space Comlpexity :    
*/ 

//Method-1 Brute force O(n^2) time, O(1) space
//Method-2 Sort the list, then remove duplicates in sorted list O(NlogN) time, O(1) space
//Method-3 Use the map method O(N) time, O(N) space

//method-3
class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) {
     // your code goes here
        Node *prev = NULL, *curr = head;
        
        //this map is going to be our visited list of node->data
        unordered_map <int, bool> map;
        
        while(curr != NULL){
            
            //duplicate found -> remove the duplicate 
            if(map.find(curr -> data) != map.end()){
                
                prev -> next = curr -> next;
                curr -> next = NULL;
                delete curr;
                curr = prev -> next;
                
            }
            //unseen data value then keep this unseen in map for future to find the duplicates
            else{
                map[curr -> data] = true;
                prev = curr;
                curr = curr -> next;
            }
        }
        
        return head;
    }
};