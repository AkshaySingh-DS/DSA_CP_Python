/* Problem Statement : https://leetcode.com/problems/palindrome-linked-list/
Time Complexity : O(n)
Space Comlpexity :O(1)
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

//approach 1 Using an temp array store the all list values in the temp array.
//then check whether the array is palindrome.(using the array logic)
class Solution {
public:
    bool isPalindromeArray(vector <int> arr){
        
        int left = 0, right = arr.size() - 1;
        
        while (left < right){
            
            if (arr[left++] != arr[right--])
                return false;
            
        }
        return true;
        
        
    }
public:
    bool isPalindrome(ListNode* head) {
        
        vector <int> temp;
        
        ListNode *t = head;
        
        while (t != NULL){
            
            temp.push_back(t -> val);
            t = t -> next;
        }
        
        return isPalindromeArray(temp);
            
    }
};

//approach2 using reverse list and middle of the linked list method 
//time complexity : O(N) but space O(1)

//python solution below
/* # Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    #step-1 get the middle
    #step-2 reverse from middle->next
    #step-3 compare each elements
    
    def getMiddle(self, head):
        slow, fast = head, head.next
        
        while (fast != None and fast.next != None):
            fast = fast.next.next
            slow = slow.next
            
        return slow
    
    def reverseList(self, head):
        
        prev, curr = None, head
        
        while (curr != None):
            forward = curr.next
            curr.next = prev
            prev = curr
            curr = forward
        
        return prev    
        
    def isPalindrome(self, head):
        
        #boundary case
        if head.next == None:
            return True
        
        middle = self.getMiddle(head)
        
        middle.next = self.reverseList(middle.next)
        
        head1 = head
        head2 = middle.next
        
        while (head2 != None):
            if (head1.val != head2.val):
                return False
            
            head1 = head1.next
            head2 = head2.next
            
        return True */