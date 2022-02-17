/* 
Problem Statement : https://www.codingninjas.com/codestudio/problems/two-stacks_983634
Time Complexity: O(1), push and pop operation.
Space Complexity: O(N) for array size to implement stack, however O(1)
 */

#include <iostream>
using namespace std;

//use only a single data structure to implement two stack.
//approach:1 Provide the stack1 and stack2 equal half memory(inefficient utilization of meomory)
//approach:2 Provide the memory for both stacks based on their requirements

//aprroach-2 below
class TwoStack {
    //data strcuture property
    int *arr;
    int top1;
    int top2;
	int size;
    
    
    public:
    // Initialize TwoStack.
    TwoStack(int s) {
        //initialize data strcuture
        size = s;
        arr = new int[size];
        top1 = -1;
        top2 = s;
    }
    
    // Push in stack 1.
    void push1(int num) {
        //check overflow first
        if (top2 - top1 > 1)
            arr[++top1] = num;   
    }

    // Push in stack 2.
    void push2(int num) {
        //check overflow first i.e. there must be space to push the element onto stack
        if (top2 - top1 > 1)     
            arr[--top2] = num;
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        //if stack is empty
        if (top1 == -1)
  			return -1;
         
        return arr[top1--];   
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (top2 == size)
  			return -1;
         
        return arr[top2++]; 
    }
};

