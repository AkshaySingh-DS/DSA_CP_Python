/* Problem Statement : https://leetcode.com/problems/remove-duplicates-from-sorted-list/
Time complexity : O(N)
Space Complexity : O(1)
 */


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if (head == NULL or head -> next == NULL)
            return head;
        
        ListNode *curr = head;
        
        
        while(curr != NULL){
            
            
            //remove duplicates
            if ( curr -> next != NULL and (curr -> val) == (curr -> next -> val)){
                
                ListNode *temp  = curr -> next -> next;
                curr -> next -> next = NULL;
                delete (curr -> next) ;
                curr -> next = temp; 
            }
            else curr = curr -> next;       
        }  
        return head;   
    }
};

