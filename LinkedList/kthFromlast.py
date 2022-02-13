""" 
Problem Statement : https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1#

Approach (1): Time O(2N), Reverse the list and get the kth from head approach
Approach (2): Time O(N), Traverse the list using ptr2 pointer untll k count from head node, then ptr1(poiting to the head node) will start traversing 
untill ptr2 != NULL 
Distance b/w ptr2 and ptr1 will be the k including ptr1 node and excluding ptr2 node.
Approach (3): Time O(2N), calculate size then get (Listsize - k + 1)th node from starting.
"""

#python code will not work if k > ListSize, but CPP code is correct, in python I'm assuming k < ListSize
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
            print(temp.data + "-->", end="")
            temp = temp.next
        print()

    def getKfromLast(self, k):
        main_ptr, ref_ptr = self.head, self.head

        count = 0
        while count < k:
            count += 1
            ref_ptr = ref_ptr.next

        while ref_ptr:
            ref_ptr, main_ptr = ref_ptr.next, main_ptr.next

        print("\n", main_ptr.data)
        # only one pass-> O(N), instead of size-k+1 will take two pass ->O(2N) one pass
        # for size



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
    fifth.next.next = Node("G")
    fifth.next.next.next = Node("H")
    listt.printList()
    k = int(input())
    listt.getKfromLast(k)

"""
CPP Solution : 
//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n){
       // Your code here
        Node *ptr1, *ptr2;
    
        ptr1 = ptr2 = head;
        
        int cnt = 1;
        
        
        while (cnt < n){
            
            ptr2 = ptr2 -> next;
            cnt++;
            
            //boundary case if n > list size
            if (ptr2 == NULL)
                return -1;
        }
        //now the distance between the ptr2 to ptr1 is k, hence nth node from last will be the 
        //when ptr2 -> null and ptr1 will give the correct position
        ptr2 = ptr2 -> next ;
        while (ptr2 != NULL){
            
            ptr2 = ptr2 -> next;
            ptr1 = ptr1 -> next;
        }
        
        return ptr1 -> data;
}

"""