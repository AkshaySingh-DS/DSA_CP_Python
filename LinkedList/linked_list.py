"""
SINGLY LIKNKED LIST In Python

Basic Operation
1. Insertion
2. Deletion
3. Creation
4. Searching
5.Traversing
6. Merging
"""
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None

class Linkedlist:

    def __init__(self):
        self.head = None

    #traverse the list
    def printList(self):
        temp = self.head

        #untill temp is not null keep on printing
        while temp:
            print(temp.data, end="->")
            temp = temp.next

    #insetion in linked list all methods

    #insert at front
    def push(self, data):
        #create node then update the head
        node = Node(data)
        node.next = self.head
        self.head = node

    #insert at end of the list
    def insertAtEnd(self, data):
        if self.head == None:
            self.head = Node(data)
            return

        #else executes this one
        temp = self.head
        while temp.next != None:
            temp = temp.next

        temp.next = Node(data)
    
    #insert at some general position
    def insertAtPos(self, data, pos):
        
        #insert at front
        if pos == 1:
            self.push(data)
            return
        
        cnt = 1
        t = self.head
        node = Node(data)
        while (cnt < pos-1):
            t = t.next
            cnt += 1
        
        node.next = t.next
        t.next = node 

    """ def insertAtmiddle(self, data):

        if self.head == None:
            self.head = Node(data)
            return

        #else executes this one
        slow = self.head
        fast = self.head.next

        # reach @ the middle

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        node = Node(data)
        node.next = slow.next
        slow.next = node """

    #deletions methods in lnked list

    #deletion at front
    def deleteAtFront(self):
        #dont need to free the memory python memory management will take care of this
        self.head = self.head.next


    #deletion at end 
    def deleteAtEnd(self):
        t = self.head 

        while t.next.next != None:
            t = t.next
        
        t.next = None

    #deletion at some general position
    def deletionAtPos(self, pos):

        if  pos == 1:
            self.deleteAtFront()
            return

        prev = None
        current = self.head
        cnt = 1

        while cnt < pos:
            prev = current
            current = current.next
            cnt += 1
        
        prev.next = current.next
        current.next = None


    
    def deleteBykey(self, key):

        # empty list
        if self.head== None:
            return False

        # if head node to be deleted
        if self.head.data == key:
            self.head = self.head.next
            return True

        prev_temp = self.head
        temp = self.head.next

        while temp != None:
            if temp.data == key:
                prev_temp.next = temp.next
                return True

            prev_temp = temp
            temp = temp.next

        return False

    
    
           
        
"""     def mergingList(self, llist2):
        if self.head == None:
            self.head = llist2.head
            return

        temp = self.head
        while temp.next != None:
            temp = temp.next

        temp.next = llist2.head """


if __name__ == "__main__":

    #create first list where head initially pointing to the null
    llist1 = Linkedlist()

    #assign some values to list
    llist1.head = Node(20)
    second = Node(30)
    third = Node(40)
    llist1.head.next = second
    second.next = third
    #now we have 3 values in list1 :- 20 -> 30 -> 40 

    #traversing
    llist1.printList()

    
    print("\n----------All Insertion Methods----------")
    #add node at front
    llist1.push(10)
    print()
    llist1.printList()

    #insert at Last
    llist1.insertAtEnd(45)
    print()
    llist1.printList()

    #insert at position
    llist1.insertAtPos(60, 6)
    print()
    llist1.printList()

    print("\n----------All Deletion Methods----------")
    #deletion at front
    print()
    llist1.deleteAtFront()
    llist1.printList()

    #deletion at last
    print()
    llist1.deleteAtEnd()
    llist1.printList()

    #deletiion at general
    print()
    llist1.deletionAtPos(4)
    llist1.printList()    
    

    """ # insertAtmiddle(check this not workin g for even)
    llist1.insertAtmiddle(7)
    print()
    llist1.printList() """

    """ llist1.insertAtmiddle(70)
    print()
    llist1.printList() """

    """# searching
    print()
    key_item = int(input())
    print(llist1.searchByKey(key_item))

    # deletion
    print()
    ans = llist1.deleteBykey(key_item)
    if ans:
        print(f"{key_item} has been deleted successfully")
        llist1.printList()
    else:
        print(f'{key_item} not found')
        """

    """ # merging linkedList
    llist2 = Linkedlist()
    llist2.head = Node('a')
    llist2.head.next = Node('b')
    llist2.head.next.next = Node('c')
    print()
    llist2.printList()
    print()
    llist1.mergingList(llist2)
    llist1.printList() """