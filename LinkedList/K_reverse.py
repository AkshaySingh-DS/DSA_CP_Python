"""
Problem Statement : https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644?leftPanelTab=1
Time Complexity : O(N)
Space Complexity : O(N), recursion stack
"""

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList():

    def __init__(self):
        self.head = None

    def printList(self):
        temp = self.head

        while temp:
            print(temp.data, end="->")
            temp = temp.next


    def kreverse(self, head, k):
        prev = None
        current = head
        count = 1

        while current and count <= k:
            temp = current.next
            current.next = prev
            prev = current
            current = temp
            count+=1

        if temp:
            head.next = self.kreverse(temp, k)

        return prev


if __name__ == "__main__":
    llist = LinkedList()
    llist.head = Node("A")
    second = Node("B")
    third = Node("C")
    fourth = Node("D")
    fifth = Node("E")
    llist.head.next = second
    second.next = third
    third.next = fourth
    fourth.next = fifth

    # traversing
    llist.printList()


    #kreverse
    print()
    k = int(input())
    llist.head = llist.kreverse(llist.head, k)
    print('After the Kth reverse')
    llist.printList()

"""
CPP SOLUTION:
/****************************************************************
    Following is the Linked List node structure

    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/


Node* kReverse(Node* head, int k) {
    // Write your code here. 
    //iterative approach to reverse a linked list upto k node
    Node *prev = NULL;
    Node *temp = head;
    int cnt = 0;
    
    //reverse the first part of the list
    while (temp != NULL and cnt < k){
        
        Node *forward = temp -> next;
        temp -> next = prev;
        prev = temp;
        temp = forward;
        cnt ++;
    }
    
    //base case (where we have to stop the recursion)
    //head->next pointer point to prev of reverse list (which would be the head of the reversed list)
    if (temp != NULL)
    	head -> next = kReverse(temp, k);
    
    return prev; //is the new head of list
}
"""