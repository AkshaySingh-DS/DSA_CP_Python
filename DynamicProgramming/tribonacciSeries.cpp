/* Problem Statement : The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
leetcod link : https://leetcode.com/problems/n-th-tribonacci-number/

Time Complexity : O(N)
Space Complexity : O(N) using memoization and recursion */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    //using memoizated dp time and space : O(N)
    int solveMem(int n, vector<int> &dp){
        //base case
        if(n == 0) return 0;
        if(n == 1 or n == 2) return 1;

        //rec case
        if(dp[n] == -1)
            dp[n] = solveMem(n-1, dp) + solveMem(n-2, dp) + solveMem(n-3, dp);

        return dp[n];

    }
    int tribonacciMemo(int n) { 
        vector<int>dp(n+1, -1);
        return solveMem(n, dp);
    }
    
    //time complexity : O(N) and space Complexity: O(1)
    int tribonacci(int n) { 
        int first = 0, sec = 1, third = 1;
        if(n == 0) return 0;
        if(n == 1 or n == 2) return 1;
        int sum;
        for(int i = 3; i < n+1; i++){
            
            sum = first + sec + third;
            first = sec;
            sec = third;
            third = sum;
        }
        return sum;
    }
};