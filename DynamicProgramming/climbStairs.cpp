/* Problem Statement : TYou are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

leetcod link : https://leetcode.com/problems/climbing-stairs/

Time Complexity : O(N)
Space Complexity : O(N) using memoization and recursion */
#include <iostream>
#include<vector>
#define maxi 46
using namespace std;
vector<int> dp(maxi, -1);

class Solution {
public:
    //time complexity -> O(2^N)
    int climbStairsRec(int n) {
        
        //base case
        if (n==0 or n==1) return 1;

        //rec case
        int ways = climbStairsRec(n-1) + climbStairsRec(n-2);
        return ways;
    }
    
    int climbStairsMemo(int n){

        //base case
        if (n==0 or n==1) return 1;

        //rec case
        if (dp[n] == -1)
            dp[n] = climbStairsMemo(n-1) + climbStairsMemo(n-2);

        return dp[n];

    }
    
    int climbStairsTab(int n){

        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < n+1; i++)
            dp[i] = dp[i-1] + dp[i-2];

        return dp[n];
    }

};