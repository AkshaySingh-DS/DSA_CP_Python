class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def printList(self):
        temp = self.head

        while temp:
            print(temp.data, end="->")
            temp = temp.next

    def reverseList(self, head):
        # base case
        if head == None or head.next == None:
            return head

        # recursive case
        shead = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return shead

    def reverseListIterative(self):
        # assume we have a non empty list
        current = self.head
        prev = None

        # logic
        while current:
            temp = current.next
            current.next = prev
            prev = current
            current = temp

        self.head = prev

"""
NOTE: for recursive case space, time -> O(N) due to recursion stack_Queue 
for iterative approach space -> O(1) and time O(N).
"""

if __name__ == "__main__":
    first = Node("A")
    second = Node("B")
    third = Node("C")
    fourth = Node("D")
    llist = LinkedList()
    llist.head = first
    llist.head.next = second
    second.next = third
    third.next = fourth

    # traverse
    llist.printList()

    # reverse recursive approach
    llist.head = llist.reverseList(llist.head)
    print("\nAfter Reverse")
    llist.printList()

    # reverse iterative approach
    llist.reverseListIterative()
    print(" \nAgain after reverse")
    llist.printList()
