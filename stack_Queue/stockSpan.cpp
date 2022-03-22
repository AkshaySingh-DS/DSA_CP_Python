/* 
Problem statement :https://leetcode.com/problems/online-stock-span/
or 
https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

Approach 1): 
Brute force approach by applying the two loops if price[j] >= price[i] count++ where j > i. or also calculate the index for prev greater and get the span 
Time Complexity: O(N^2)
Space Complexity: O(1)

Approach 2):
Using stack approach by putting the indices of arrays.

*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;


//two loop approach
class Solution
{
    private:
    
    vector<int> prevGreater(int price[], int n){
        
        stack <int> s;
        s.push(-1);
        
        vector<int>ans(n);
        
        for(int i = 0; i < n ; i++){
            
            int curr = price[i];
            
            while(s.top() != -1 and price[i] > price[s.top()])
                s.pop();
                
            ans[i] = s.top();
            s.push(i);
        }
        
        return ans;
    }
    
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
      vector <int> prevGre =  prevGreater(price, n);
      
      vector<int> ans;
      for(int i = 0 ; i < n ; i++){
          
          int span = prevGre[i] == -1 ? i + 1 : i - prevGre[i];
          
          ans.push_back(span);
         
      }
      
     return ans;
    }
};

//in a single pass 
class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
   vector <int> calculateSpan(int price[], int n)
    {
      //stack will track the next greater elements 
       stack <int> s;
       s.push(-1);
       
       vector<int> ans(n);
       
      //for prev greater better to start from 0th index 
      for(int i = 0 ; i < n ; i++){
          
          //get current price
          int currPrice = price[i];
          
          //untill we won't find the prev greater of current price from stack keep on popping
           while(s.top() != -1 and currPrice >= price[s.top()])
                s.pop();
                
        //update stock span answer, if no prev gretaer exits for current price then i+1 would be the asnwer       
          ans[i] = s.top() == -1 ? i + 1 : i - s.top();
          s.push(i);

      }
      
     return ans;
    }
};

//Leetcode
class StockSpanner {
public:
    stack <int> s;
    vector <int> stockPrice;
    int i = 0;
    
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        //push the price in array first
        stockPrice.push_back(price);
        
        
        //do this untill we are not able to find  prev greater 
        while(!s.empty() and price >= stockPrice[s.top()])
            s.pop();
        
        //i + 1 cause if ith element dont have the prev greater that stock soain would be i + 1 
        int ans = s.empty() ? i + 1 : i - s.top();// s.top() gives the prev higher value,
        
        //push the current index into stak for rest elements
        s.push(i);
        i++;
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */