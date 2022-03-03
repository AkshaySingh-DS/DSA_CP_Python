/* Problem statement : 
https://www.codingninjas.com/codestudio/problems/reversing-a-queue_982934?leftPanelTab=0
or 

https://practice.geeksforgeeks.org/problems/queue-reversal/1
Time Complexity : O(N) 
Space Complexity : O(N) where N size of queueThe array Queue is difficult to implement and also it is not dynamic in nature.
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//Approach-1 Using recusive stack way;
//Function to reverse the queue.
void solver(queue <int> &q){
     
    //base case
    if (q.empty())
        return;
    
    //recursive case, save the front
    int front = q.front();
    q.pop();
    solver(q); // get all elements reversed
    
    //push the front again in the reversed queue
    q.push(front);
}
queue<int> rev(queue<int> q)
{
    solver(q);
    return q;
}

//Apprach-2 Using iterative stack way;
#include <stack>
queue<int> reverseQueue(queue<int> q)
{
    stack <int> s;
    
    //copy all the elements from queue and push it on stack
    while (!q.empty()){
        
        //get the front of queue
        s.push(q.front());
        
        //pop the front of queue
        q.pop();
    }
    
    //push all the elments from stack to queue again
    while(!s.empty()){
        
        //get the top of stack
        q.push(s.top());
        
        //pop the top of stack
        s.pop();
    }
     
    return q;   
}