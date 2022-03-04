/* 
Problem Statement : https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1#
Time Complexity: O(N)
Space Complexity: O(K) to main the deque of size k

Approach1 : Use two pointer approach, then get the first -ve with in those ponters limit
O(N^2)
space complexity:O(1)

Approach2 : Use deque/queue data structure where we'll store only -ve numbers.
and front of the deque/queue will be the answers.
*/
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    deque <long long int> dq;
    vector<long long> ans;
    //process the first window assuming k << N
    
    long long int i = 0;
    
    while(i < K){
        
        if(A[i] < 0)
            dq.push_back(i);
        
        i++;
    }
 
    //first store the ans for first window if is there then only
    
    if(!dq.empty()){
        ans.push_back(A[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
    
    //now process the ramaining window
    
    for(long long int i = K ; i < N ; i++){
        
        //removal logic (shrink the window)
        if (!dq.empty() and (i - dq.front()) >= K)
            dq.pop_front();
        
        //addition of one element
        if(A[i] < 0)
            dq.push_back(i);
            
        //get the answer after inserting the element in window, if possible
        if(!dq.empty())
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
    }
    
    return ans;
                                             
 }

 //Optimized Shorter code in single pass
 vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                                                 
    deque <long long > dq;
    vector<long long> ans;
    
    
    long long int i = 0;
    //process the first window k-1 assuming  k<< N
    while(i < K-1){
        
        if(A[i] < 0)
            dq.push_back(i);
        
        i++;
    }

    
    //now process the ramaining window from k-1 to next
    
    for(; i < N ; i++){
        
        //removal logic (shrink the window)
        long long int idx = i - K ; 
        if (!dq.empty() and dq.front() == idx)
            dq.pop_front();
        
        //addition of one element
        if(A[i] < 0)
            dq.push_back(i);
            
        //get the answer after inserting the element in window, if possible
        if(!dq.empty())
            ans.push_back(A[dq.front()]);
        else
            ans.push_back(0);
    }
    
    return ans;
                                             
 }