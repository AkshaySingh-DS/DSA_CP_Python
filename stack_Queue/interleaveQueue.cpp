/* 
Problem Statement : https://www.codingninjas.com/codestudio/problems/interleave-the-first-half-of-the-queue-with-the-second-half_1169450?leftPanelTab=0 

Time Complexity: O(N)
Space Complexity: O(N)

Approach-1 (Optimal): Using extra queue, time -> O(N), space-> O(N)
Approach-2 : Using extra stack, time -> O(N), space-> O(N) 
*/
#include <iostream>
#include<queue>
using namespace std;

//using Queue (Optimal Approach)
void interLeaveQueue(queue < int > & q) {
    
    queue <int> newq;
    
    //get the first half of the queue;
    int size = q.size();
    int cnt = 0;
    
    while (cnt < size /2){
        
        cnt++;
        newq.push(q.front());
        q.pop();
    }
    
    //perform the logic for interleave queue
    while(!newq.empty()){
        
        //get the front of the new queue and push it into original queue
        q.push(newq.front());
        newq.pop();
        
        //get the original front of queue and push it in original itself
        q.push(q.front());
        q.pop();
    } 
}

//using Stack (Optimal Approach)
//approach-2 TLE by using stack (but doing recusion in stack make it TLE)
#include<stack>
#include<algorithm>
void insertAtBottom(stack <int> &s, int x){

    //base case
    if(s.empty()){
        s.push(x);
        return; 
    }
    //recursive case
    int top = s.top();
    s.pop();
    
    insertAtBottom(s, x);
    
    //now push top element
    s.push(top);
    
}
void reverseStack(stack <int> &s){
    
    //base case
    if (s.empty())
        return;
    
    //get top element
    int top = s.top();
    s.pop();
    
    //now reverse
    reverseStack(s);
    
    //now push the element at  bottom
    insertAtBottom(s, top);
}

void interLeaveQueue(queue < int > & q) {
    
    //move first half element in stack
    //reverse stack
    //now push the stack element into que in a interleave structure
    
    int size = q.size();
    
    stack <int> st;
    int cnt = 0;
 
    //get first half queue element and push in stack
    while(cnt < size /2){
        
        st.push(q.front());
        q.pop();
        cnt++;
    }
    
    //reverse stack
    reverseStack(st);
   
    
    //now push the stack elements in queue in a interleaving structure
    while (!st.empty()){
        
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    
}

//approach-3 using single stack
void interLeaveQueue(queue < int > & q) {
   
    //step1 get the first half of queue in stack
    //step2 push the stack elements in queue
    //step3 now pop the first half from queue and push it in queue
    //now take the first half from queue again in stack
    //the push in queue in interleave structure
    
    //get the first half of the queue;
    int size = q.size();
    int cnt = 0;
    stack <int> s;
    while (cnt < size /2){
        cnt++;
        s.push(q.front());
        q.pop();
    }
    
    //push in queue
    while (!s.empty()){
        
        q.push(s.top());
        s.pop();
    }
    
    //get first half again then push into queue
    cnt = 0;
    while(cnt < size /2){
        
        int x = q.front();
        q.pop();
        q.push(x);
        cnt++;
    }
    
    //get first half again in stack
    cnt = 0;
     while (cnt < size /2){
        cnt++;
        s.push(q.front());
        q.pop();
    }
    
    //push in queue in a interleaved structure
    while (!s.empty()){
        
        int x = s.top();
        s.pop();
        
        q.push(x);
        q.push(q.front());
        q.pop();
    }
}

//approach-4 using 2 stack
void interLeaveQueue(queue < int > & q) {
    
    //move first half element in stack
    //reverse stack
    //now push the stack element into que in a interleave structure
    
    int size = q.size();
    
    stack <int> st;
    int cnt = 0;
 
    //get first half queue element and push in stack
    while(cnt < size /2){
        
        st.push(q.front());
        q.pop();
        cnt++;
    }
    
    stack <int> news;  
    while (!st.empty()){
        
        news.push(st.top());
        st.pop();   
    }

    //now push the stack elements in queue in a interleaving structure
    while (!news.empty()){
        
        q.push(news.top());
        news.pop();
        q.push(q.front());
        q.pop();
    }
    
}

