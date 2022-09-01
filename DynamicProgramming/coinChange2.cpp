/* Problem Statement: 
You are given an integer array coins representing coins of different 
denominations and an integer amount representing a total amount of money. Return the number 
of combinations that make up that amount. If that amount of money cannot be made up by any 
combination of the coins, return 0. 

Problem Link: https://leetcode.com/problems/coin-change-2/
*/

#include <iostream>
#include <vector>
using namespace std;


//plane Recursive solution - Exponential solutuon O(2^N), Auxillary Recursive Stack Space O(N)
class Solution {
public:
    int solveRec(int target, int i,  vector<int> &coins){
        
        //base case
        if(target == 0) return 1;
        if(i == 0){
            if(target % coins[0] == 0) return 1;
            return 0;
        }
        
        //rec case
        
        int notpick = solveRec(target, i-1, coins);
        
        int pick = 0;
        if(coins[i] <= target)
            pick = solveRec(target - coins[i], i, coins);
        
        return pick + notpick;
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        //vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solveRec(amount, n-1, coins);
    }
};

//Using Memoization
//Time complexity: O(N * Amount), space complexity: O(N) + O(N * Amount) for dp array
class Solution2 {
public:
    int solveMem(int target, int i,  vector<int> &coins,  vector<vector<int>> &dp){
        
        //base case
        if(target == 0) return 1;
        if(i == 0){
            if(target % coins[0] == 0) return 1;
            return 0;
        }
        
        //rec case
        if(dp[i][target] == -1){
            
            int notpick = solveMem(target, i-1, coins, dp);
        
            int pick = 0;
            if(coins[i] <= target)
                pick = solveMem(target - coins[i], i, coins, dp);

            dp[i][target] = pick + notpick;
        }
        return dp[i][target];
    }
    
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solveMem(amount, n-1, coins, dp);
    }
};

//Using Tabulation
//Time complexity: O(N * Amount), space complexity: O(N * Amount) for dp array
class Solution3 {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        //base cases
        for(int i = 0;i <n; i++) dp[i][0] = 1;
        
        for(int tar = 0; tar < amount + 1 ; tar++){
            if(tar % coins[0] == 0) dp[0][tar] = 1;
            else dp[0][tar] = 0; 
        }
        for(int  i = 1; i < n ; i++){
            
            for(int target = 0; target < amount + 1 ; target++){
                
                int notpick = dp[i-1][target];
                int pick = 0;
                if(coins[i] <= target)
                    pick = dp[i][target - coins[i]];

                dp[i][target] = pick + notpick;
            }
        }
        return dp[n-1][amount];
    }
};

//Using Tabulation with space optimization
//Time complexity: O(N * Amount), space complexity: O(Amount) for prev array
class Solution4 {
public:
    int change(int amount, vector<int>& coins){
        int n = coins.size();
        
        //vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        vector<int> prev(amount+1, 0);
        vector<int> curr(amount+1, 0);
        
        //base cases
        prev[0] = 1;
        for(int tar = 0; tar < amount + 1 ; tar++){
            if(tar % coins[0] == 0) prev[tar] = 1;
            else prev[tar] = 0; 
        }
        for(int  i = 1; i < n ; i++){
            for(int target = 0; target < amount + 1 ; target++){
                
                int notpick = prev[target];
        
                int pick = 0;
                if(coins[i] <= target)
                    pick = curr[target - coins[i]];

                curr[target] = pick + notpick;
            } 
            prev = curr;
        }
        return prev[amount];
    }
};
