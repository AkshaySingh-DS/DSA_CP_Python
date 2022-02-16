/* Problem statement : Built Stack from scratch using array

time complexity : O(1) for push, pop, peek, isEmpty operations.
space complexity : O(N) where N size of stack 
The array stack is easy to implement but it is not dynamic in nature
*/

#include <iostream>
using namespace std;

class Stack{


    //properties -> keeping data members as a private is a good practice
    int size;
    int top;
    int *arr;

    //behaviours
    public:
        Stack(int size){

            this -> size = size;
            arr = new int[size];
            top = -1;
        }

        //push 
        void push(int data){

            //if we have at least one element size left
            if (size - top > 1)
                arr[++top] = data;
            else{

                cout << "stack overflow" << endl;
            }
        }

        //pop
        void pop(){

            if (top == -1){
                cout << "stack underflow" << endl;
            }
            else{
                top--;
            }
        }

        //peek
        int peek(){

            if(top == -1)
                return -1;
            
            return arr[top];
        }

        //empty
        bool isEmpty(){

            if (top == -1)
                return true;
            else
                return false;
        }
};

int main(){

    //create the stack of size 'n'
    Stack st(4);

    //push elemnt
    st.push(10);
    st.push(12);
    st.push(13);
    st.push(9);
    
    cout << st.isEmpty() << endl;
    cout << st.peek() << endl ;
    
    //stack overflow check
    st.push(22);
    
    //pop element
    st.pop();
    st.pop();
    cout << st.peek() << endl;
    
    //stack underfloew check
    st.pop();
    st.pop();
    st.pop();
    
    //stack empty check
    cout << st.isEmpty() << endl;    
    return 0;
}

/* #python implementation using list
class stack:
    
    def __init__(self):
        self.arr = []
        
    def push(self, data):
        #since python list is dynamic in nature no need for overflow condition
        self.arr.append(data)
        
    def pop(self):
        #if we have at least one element in list
        if self.arr:
            self.arr.pop()
        
        else:
            print("stack is empty")
    
    def peek(self):
        if self.arr:
            #top element from stack
            return self.arr[-1]
        else:
            return -1
        
    def isEmpty(self):
        if not self.arr:
            return True
            
        return False
            
            
if __name__ == "__main__":
    st = stack()
    
    #check initially stack is empty
    print(st.isEmpty())

    #push the elements to stack
    st.push(23)
    st.push(25)
    
    #check now stack is empty
    print(st.isEmpty())
    
    #check the top of the stack
    print(f'Top of Stack : {st.peek()}') if not st.isEmpty() else print("stack is Empty")
    
    #pop the item from stack
    st.pop()
    
    #get peek
    print(f'Top of Stack : {st.peek()}')
    
    #check stack underflow
    st.pop()
    
    #now stack is empty
    st.pop()
 */