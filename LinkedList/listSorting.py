#merge sort from scratch

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
            print(temp.data ,"-->", end="")
            temp = temp.next
        print()


def middleNode(head):
    slow, fast = head, head.next

    while fast and fast.next:
        slow, fast = slow.next, fast.next.next

    return slow

def mergeSort(head):
    # base case
    if head.next == None or head==None:
        return head

    mid = middleNode(head)
    a, b = head, mid.next
    mid.next = None

    #recursive case
    a = mergeSort(a)
    b = mergeSort(b)

    return merge(a, b)

def merge(head1, head2):
    # base
    if head1 == None:
        return head2

    if head2 == None:
        return head1

    # recursive case
    if head1.data > head2.data:
        c = head2
        c.next = merge(head1, head2.next)
    else:
        c = head1
        c.next = merge(head1.next, head2)

    return c

if __name__ == "__main__":
    listt = LinkedList()
    listt.head = Node(5)
    sec = Node(4)
    thr = Node(6)
    forth = Node(1)
    fifth = Node(3)
    listt.head.next = sec
    sec.next = thr
    thr.next = forth
    forth.next = fifth
    fifth.next = Node(7)
    fifth.next.next = Node(2)
    print("Before Sorting")
    listt.printList()

    #merge Sort
    listt.head = mergeSort(listt.head)
    print("\nAfter Sorting\n")
    listt.printList()