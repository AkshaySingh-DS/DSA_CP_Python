/* Problem Statement : The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, 
such that each number is the sum of the two 

leetcod link : https://leetcode.com/problems/fibonacci-number/

Time Complexity : O(N)
Space Complexity : O(N) using memoization and recursion */
#include<iostream>
#include<vector>
using namespace std;
#define maxi 31

vector<int>dp(maxi, -1);

class Solution {
public:
    //bottom up solution
    int fibTabulation(int n) {
        if (n==0 or n==1) return n;
        
        vector <int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i < n+1; i++)
            dp[i] = dp[i-1] + dp[i-2];

        return dp[n];

    }
    
    //time complexity O(2^N)
    int fibRecursion(int n) {
        
        //base case
        if (n==0 or n==1) return n;

        //rec case
        return fibRecursion(n-1) + fibRecursion(n-2);

    }
    
    //top down solution
    int fibMemoization(int n){
        
        //base case
        if ( n == 0 or n == 1) return n;

        //rec case
        if (dp[n] == -1)
            dp[n] = fibMemoization(n-1) + fibMemoization(n-2);

        return dp[n];
    }
};