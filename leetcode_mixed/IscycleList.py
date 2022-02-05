"""
Problem Statement : https://leetcode.com/problems/linked-list-cycle/
Time Complexity : O(N)
Space Complexity : O(1) using floyds' runner approach, space O(N) due to hash-map
However hasp-map method is quite fast than runner's approach
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        nodeMap = dict()
        temp = head
        while temp:
            
            #if node present already then there is a cycle
            if nodeMap.get(temp) :
                return True
            
            #else put this node in map and go to next
            nodeMap[temp] = True
            temp = temp.next      

        #means there is no cycle and we hit the null     
        return False
    

    #take O(N) time and space O(1)--> runner Approach
    def isCycleBest(self):
        slow, fast = self.head, self.head

        # logic
        while fast and fast.next: #note using slow makes its bit faster will executes less than O(2N)
          slow, fast = slow.next, fast.next.next

          if slow == fast:
              return True

        return False




"""
CPP Solution :
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;
        
        //floyd's cycle detection algorithm
        while (fast != NULL and fast -> next != NULL){
            
            slow = slow -> next;
            fast = fast -> next -> next;
            
            if(slow == fast)
                return true;          
        }      
        return false;
    }
};
"""