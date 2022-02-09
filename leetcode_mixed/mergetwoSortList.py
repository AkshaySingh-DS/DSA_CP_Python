"""Problem Statement : https://leetcode.com/problems/merge-two-sorted-lists/
Time Complexity :  O(N)
Space Comlpexity : O(1) on iterative approach and O(n) in recursive approach
"""

# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next

class Solution(object):
    def mergeTwoLists(self, list1, list2):
       
        #dummy node for simplicity
        head = ListNode(None)
        tail = head
        
        #tail is the pointer which help where the sorted node need to push to
        #will perform this untill list1 and list2 is not null
        while list1 is not None and list2 is not None:
            
            if list1.val > list2.val:
                tail.next = list2
                tail = list2
                list2 = list2.next
            
            else:
                tail.next = list1
                tail = list1
                list1 = list1.next
        
        #no need to apply while loop since this is a dynamic list
        if list1 is not None: 
            tail.next = list1
        
         #no need to apply while loop since this is a dynamic list
        if list2 is not None:
            tail.next = list2
           
        #return the actual list by exluding the dummy node
        return head.next  
               
"""CPP SOLUTION : 
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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        
        //base cases
        if (head1 == NULL)
            return head2;
        
        if (head2 == NULL)
            return head1;
       
        //recursive case
        ListNode* tail;
        if (head1 -> val > head2 -> val){
            
            tail = head2;
            tail -> next = mergeTwoLists(head1, head2 -> next);
        }
        else{
            
            tail = head1;
            tail -> next = mergeTwoLists(head1 -> next, head2);
        }
        
        //tail will be the new head of the list at the end
        return tail;
        
    }
};
"""
