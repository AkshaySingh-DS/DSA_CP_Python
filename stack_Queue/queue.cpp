/* Problem statement : Built Circular Queue class from scratch using array
https://www.codingninjas.com/codestudio/problems/circular-queue_1170058?leftPanelTab=1

or 
https://leetcode.com/problems/design-circular-queue/

Time Complexity : O(1) for Enqueue, Dequeue, front, isEmpty, isFull operations.
Space Complexity : O(N) where N size of stack 
The array Queue is difficult to implement and also it is not dynamic in nature.
*/

class CircularQueue{
    int *arr;
    int rear;
    int front;
    int size;  
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        size = n;
        arr = new int[size];
        rear = -1;
        front = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if(!isFull()){
            
            //case1 when empty
            if(isEmpty()){
                rear = 0;
                front = 0;
                arr[rear] = value;
            }
            //case2 when circular
            else if(rear == size-1 and front != 0){
                rear = 0;
                arr[rear] = value;
            }        
            //case3 for general
            else{
                arr[++rear] = value;         
            }
            
            return true;
        }
        
        return false;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
         if(isEmpty()){
            return -1;
        }
        
        int ans =  arr[front];
        arr[front] = -1;
        
        //case1 when we have single element
        if(rear == front)
            front = rear = -1;     
       
         //case2 when circular 
        else if(front == size-1) 
            front = 0;
        //case3 delete general element 
        else
            front++;
   
        return ans;
    }
    
    bool isEmpty() {
        if (front == -1) 
            return true;
        else 
            return false;
    }
    
    bool isFull() {
        if(  (front == 0 and rear == size-1) or (  rear == (front-1) % (size-1)  ) )
            return true;
        else
            return false;
    }
};