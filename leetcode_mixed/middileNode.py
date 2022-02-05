"""
Problem statement : https://leetcode.com/problems/middle-of-the-linked-list/
Time Complexity : O(N)
Space Complexity : O(1) but in recursion O(n) 
"""

class Node:
    def __init__(self,data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def printList(self):
        temp = self.head
        while temp:
            print(temp.data+"-->", end="")
            temp = temp.next

    def getMiddleNode(self):
        fast, slow = self.head, self.head

        while fast and fast.next:
            slow, fast = slow.next, fast.next.next

        return slow

"""
Python 2nd solution using length parameter
def getLength(head):
    temp = head
    cnt = 0
    while temp:
        temp = temp.next
        cnt += 1
        
    return cnt
     
    
def findMiddle(head):
    # Write your code here
    # head denoted head of linked list
    if (head == None or head.next == None):
        return head
    
    #at least node 
    length = getLength(head) 
    temp = head  
    cnt = 1
    while cnt <= length//2:
        temp = temp.next
        cnt += 1
        
    return temp;
"""



if __name__ == "__main__":
    listt = LinkedList()
    listt.head = Node("A")
    sec = Node("B")
    thr = Node("C")
    forth = Node("D")
    fifth = Node("E")
    listt.head.next = sec
    sec.next = thr
    thr.next = forth
    forth.next = fifth
    fifth.next = Node("F")

    listt.printList()
    print("\nmiddle value: ", end="")
    node = listt.getMiddleNode()
    print(node.data)

"""
CPP Solotion :
Approach-1 
int lengthOfLinkedList(Node *head){   
    // empty list
    if(head == NULL)
        return 0;
    
    Node * temp = head;
    int l = 0;
    
    while (temp){
        temp = temp -> next;
        l++;
    }  
    return l;  
}

Node *findMiddle(Node *head) {
    // Write your code here
    Node *t = head;
    int cnt = 1; 
    int length = lengthOfLinkedList(head);
    
    while (cnt <= length){       
        t = t -> next;
        cnt++;   
    }    
    return t;
}

#approach-2 using recursion
Node * getMiddle(Node *slow, Node *fast){
    
    //base case
    if (fast == NULL or fast -> next == NULL)
        return slow;
   
    //recursive case
    return getMiddle(slow -> next, fast -> next -> next);
 
}
Node *findMiddle(Node *head) {
    //for one and empty list
    if (head == NULL or head -> next == NULL)
        return head;
    
   //first head is the slow pointer and 2nd head is our fasdt pointer 
   getMiddle(head, head);
}
"""