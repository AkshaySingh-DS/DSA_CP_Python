/* Problem Statement : https://leetcode.com/problems/linked-list-cycle-ii/
Time complexity : O(N) in both methods
Space Complexity : O(1) using Floyd's but in case of map it would be O(N)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//cpp solution: using floyd's cycle detection
class Solution{
public:
    ListNode *detectCycle(ListNode *head) {
        
        //boundary case 1 node and empty list
        if (head == NULL or head -> next == NULL)
            return NULL;
            
        ListNode *slow, *fast;
        slow = fast = head;
        
        //floyd's cycle detection algorithm
        while(fast != NULL and fast -> next != NULL){
            
            fast = fast -> next -> next;
            slow = slow -> next;
            
            if (slow == fast)
                break;
        }
        
        if (fast == NULL or fast -> next == NULL)
            return NULL;
        
        slow = head;
        
        while( slow != fast){
            
            fast = fast -> next;
            slow = slow -> next;
        }
        
        return slow;       
    }
};

/*
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
    ListNode *detectCycle(ListNode *head) {
        
        //boundary case 1 node and empty list
        if (head == NULL or head -> next == NULL)
            return NULL;
            
        ListNode *slow, *fast;
        slow = fast = head;
        
        //floyd's cycle detection algorithm
        while(fast != NULL and fast -> next != NULL){
            
            fast = fast -> next -> next;
            slow = slow -> next;
            
            //come out from the loop if cycle found
            if (slow == fast)
                break;
        }
        
        //there are two wyas we can come out from this loop 

        //way1
        if (fast == NULL or fast -> next == NULL)
            return NULL;
        
        //way2 when cycle is present
        slow = head;
        //now make the pace of slow and fast same
        while( slow != fast){
            
            fast = fast -> next;
            slow = slow -> next;
        }    
        return slow;       
    }
};

/*
Pyhton solution using floyd's Cycle Detection 
class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None or head.next == None:
            return None
        
        slow, fast = head, head
        
        while fast != None and fast.next != None:
            fast = fast.next.next
            slow = slow.next
            
            if slow == fast:
                break
        
        if fast == None or fast.next == None:
            return None
        
        slow = head

               
        while fast != slow:
            fast = fast.next
            slow = slow.next
        
        return slow

Python Solution Using the hash-Map
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        #boundary case
        if head == None or head.next == None:
            return None
        
        #creating the hash map of node
        temp = head
        nodeMap = dict()
        
        while temp != None:
            #found return the pointer
            if nodeMap.get(temp):
                return temp
            
            #not found
            nodeMap[temp] = True
            temp = temp.next
          
        #means no cycle is there 
        return None
/*

/*
Concept : Distance covered by fast pointer  = 2 * distance covered by slow pointer
A + k1 * C + B = 2 (A + k2 * C + B)
A + B = C * constant , B is the pont where fast is present, so only A distancve is required (which is nothing but the distance from head pointer to cycle start point)

CPP SOLUTION : using map
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        //boundary case 1 node and empty list
        if (head == NULL or head -> next == NULL)
            return NULL;
        
        unordered_map <ListNode *, bool> map;
        
        ListNode *temp = head;
        
        while (temp != NULL){
            
            if (map.find(temp) != map.end())
                return temp;
            
            map[temp] = true;
            temp = temp -> next;       
        }
        
        return NULL;
    }
};
*/