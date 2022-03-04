/* 
Problem Statement : https://www.codingninjas.com/codestudio/problems/reverse-first-k-elements-of-queue_982771
Time Complexity: O(N)
Space Complexity: O(K) using the stack of size k

Approach: reverse the queue by using the stack data structure
*/
#include <iostream>
#include<stack>
#include<queue>
using namespace std;

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    
     stack <int> st;
    
    //push first k elements into stack
    int size = q.size();
    for(int i = 0; i < k; i++){
        
        st.push(q.front());
        q.pop();
    }
    
    //push_back all eleemets of stack in queue
    while(!st.empty()){
        
        q.push(st.top());
        st.pop();
    }
    
    //pop first size - K elements from queue and again push them
    for(int i = 0; i < size - k; i++){
        
        //int x = q.front();
        //q.pop()
        q.push(q.front());
        q.pop();
    }
    
    return q;
    
}