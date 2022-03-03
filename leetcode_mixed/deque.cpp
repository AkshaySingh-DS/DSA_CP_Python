 /* Problem statement : Built Circular Deqeue class from scratch using array
https://www.codingninjas.com/codestudio/problems/deque_1170059?leftPanelTab=1

or 
https://leetcode.com/problems/design-circular-deque/

Time Complexity : O(1) for Enqueue, Dequeue, front, isEmpty, isFull operations.
Space Complexity : O(N) where N size of stack 
The array dueue is difficult to implement and also it is not dynamic in nature.
*/


class MyCircularDeque {
    
    //members variable
    int *arr;
    int size;
    int rear;
    int front;
    
    //memeber functions
public:
    MyCircularDeque(int k) {
        
        size = k;
        arr = new int[size];
        front = rear = -1;
    }
    
    bool insertFront(int value) {
        
        //when deque is not full
        if(!isFull()){
            
            //if deque is empty
            if(front == -1)
                front = rear = 0;
            
            //if pushing the element from front in circular case
            else if(front == 0 and rear != size-1)
                front = size-1;
            
            //nor case while pushing from front
            else
                front--;
            
            arr[front] = value;
            
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        
        if(!isFull()){
            
            if(front == -1)
                rear = front = 0;
            
            else if( (rear == size-1) and front != 0 )
                rear = 0;
            
            else
                rear++;
            
            arr[rear] = value;
            
            return true;
        }
        
        return false;
    }
    
    bool deleteFront() {
        
         if(!isEmpty()){
            
            //int ans = arr[front];
            arr[front] = -1;
            
            if(front == rear)
                rear = front = -1;
            
            else if (front == size-1)
                front = 0;
            
            else
                front++;
            
           return true;
   
        }
        return false;
    }
    
    bool deleteLast() {
        
        if(!isEmpty()){
            
            //case1 When single element
            arr[rear] = -1; // not needed
            
            if (front == rear)
                front = rear = -1;
            
            //case2 When circular case
            else if(rear == 0 )
                rear = size - 1;
            
            //case3  When normal scenerio
            else
                rear --;
                         
            return true;    
        }
        return false;
    }
    
    int getFront() {
        
        if(!isEmpty())
            return arr[front];
        
        return -1;
    }
    
    int getRear() {
        
        if(!isEmpty())
           return arr[rear];
        
        return -1;
    }
    
    bool isEmpty() {
        
        if (front == -1)
            return true;
        
        return false;
    }
    
    bool isFull() {
        if ( (front == 0 and rear == size-1)  or ((front != 0 ) and (rear == (front-1) % (size-1) ) ) )
            return true;
        
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */