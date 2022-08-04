/* Problem Statement : TYou are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

leetcod link : https://leetcode.com/problems/climbing-stairs/

Time Complexity : O(N)
Space Complexity : O(N) using memoization and recursion */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    //pure recursion time complexity : O(2^N)
    int solve(vector<int>&cost, int k){
        //base case
        if(k == 0 or k == 1) return cost[k];

        //rec case 
        int costt;
        if (k == cost.size()) costt = 0;
        else costt = cost[k];

        return costt + min(solve(cost, k-1), solve(cost, k-2));
    }
    
   int minCostClimbingStairsRec(vector<int>& cost) {
        
        int size = cost.size();
        return solve(cost, size);
   }

    //using memoization
    int solveMem(vector<int>& cost, int k, vector<int> &dp){
    
        //base case
        if (k == 0 or k == 1) return cost[k];

        //rec case
        int costt = 0;
        if(k != cost.size()) costt = cost[k]; 

        if (dp[k] == -1)
            dp[k] = costt+ min(solveMem(cost, k-1, dp), solveMem(cost, k-2, dp));
        return dp[k];
   }

   int minCostClimbingStairsMem(vector<int>& cost) { 
        int size = cost.size();
        vector<int> dp(size+1, -1);
        return solveMem(cost, size, dp);
   }
    
    //using tabulation aka bottum up
    int solveTab(vector<int>& cost, int n, vector<int> &dp){

        for(int i = 2; i < n+1; i++){

            int costt = 0; // for i --> n cost will be 0

            if(i != n)
                costt = cost[i]; //for others stairs
            
            dp[i] = costt + min(dp[i-1], dp[i-2]);
        }

        return dp[n];
   }
    
   int minCostClimbingStairs(vector<int>& cost) {    
        int size = cost.size();

        vector<int> dp(size+1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        return solveTab(cost, size, dp);
   }
       
};