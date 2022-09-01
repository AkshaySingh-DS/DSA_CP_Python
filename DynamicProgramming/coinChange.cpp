/* 
problem Statement: You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

problem link: https://leetcode.com/problems/coin-change/ 

*/
#include<iostream>
#include<vector>
using namespace std;


//plane Recursive solution - Exponential solutuon (Amount^N), space O(Amount)
int coinChange(vector<int> &coins, int amount) {

    //base case
    if(amount == 0) return 0;
    if(amount < 0) return INT_MAX;

    //rec case
    int mini = INT_MAX;
    for(int i = 0; i < coins.size(); i++){

        mini = min(mini, coinChange(coins, amount - coins[i])); 
    }
    
    if (mini != INT_MAX)
        return mini + 1;
    else
        return INT_MAX;
}

//Memoized DP : Top-Town, time complexity : O(Amount * N), SPACE: O(Amount)
int solveMem(vector<int> &coins, vector<int> &dp, int x){
        
        //base case
        if(x == 0) return 0;
        if(x < 0) return INT_MAX;
        
        //rec case
        int mini = INT_MAX;
        
        if(dp[x] == -1){
            
            for(int i = 0; i < coins.size(); i++)
                mini = min(mini, solveMem(coins, dp, x - coins[i])); 
            
            //update dp[x] ,  INT_MAX+1 will be overflow so we need to handle this
            dp[x] = mini != INT_MAX ? mini + 1 : INT_MAX;
        }
        
        return dp[x];
}
int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1, -1);
        int ans = solveMem(coins, dp, amount);
        
        if(ans != INT_MAX) return ans;
        
        return -1;
}

//Bottom UP DP - Tabulation, time complexity : O(Amount * N), SPACE: O(Amount)
int coinChange(vector<int>& coins, int amount) {
        
        vector<int>dp(amount+1, INT_MAX);
        dp[0] = 0;
        
        for(int i = 1; i < amount+1 ; i++){
            
            int mini = INT_MAX;
            
            for(int j = 0; j < coins.size(); j++){
                
                if (i - coins[j] >= 0)
                    mini = min(mini, dp[i - coins[j]]);
                
            }
            
            if(mini != INT_MAX) dp[i] = mini + 1; 
        }
        
        if (dp[amount] == INT_MAX) return -1;
        
        return dp[amount];
}


int main(){

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    int res = coinChange(coins, x);
    if(res != INT_MAX)
        cout << res;
    else cout << -1;

    return 0;
}

//Approach2 Using the idea of not pick and pick in subsequences

//Approach1 - Recursion
//time complexity: O(2^N), space complexity: O(N)
 int solveRec(vector<int>& coins, int i, int target){
        
        //base case
        if(target == 0) return 0;
        if(i == 0) {
            if(target % coins[0] == 0) return target/coins[0];
            return 1e8;
        }
        
        //rec case
            
            int notpick = 0 + solveRec(coins, i-1, target, dp);
        
            int pick = 1e8;
            if(coins[i] <= target)  
                pick = 1 + solveRec(coins, i, target - coins[i], dp);

        
        return min(pick, notpick);         
}

//Approach2 Using Memmoization
//time complexity: O(N * Amount), space complexity: O(N) + O(N * Amount) for dp array
   int solveMem(vector<int>& coins, int i, int target, vector<vector<int>> &dp){
        
        //base case
        if(target == 0) return 0;
        if(i == 0) {
            if(target % coins[0] == 0) return target/coins[0];
            return 1e8;
        }
        
        //rec case
        if(dp[i][target] == -1){
            
            int notpick = 0 + solveMem(coins, i-1, target, dp);
        
            int pick = 1e8;
            if(coins[i] <= target)  
                pick = 1 + solveMem(coins, i, target - coins[i], dp);

            dp[i][target] = min(notpick, pick); 
        }
        
        return dp[i][target];        
}


//Approach3 Using Tabulation
//time complexity: O(N * Amount), space complexity: O(N * Amount) for dp array
int coinChange(vector<int>& coins, int amount) {
        
        //edge case
        if (amount == 0) return 0;

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        
        //base cases
        for(int i = 0; i < n; i++)
            dp[i][0] = 0;
        
        for(int tar = 1; tar < amount+1; tar++){
            if(tar % coins[0] == 0) dp[0][tar] = tar/coins[0] ; //number of coins
            else dp[0][tar] = 1e8;
        }
        
        for(int i = 1; i < n; i++){
            
             for(int tar = 1; tar < amount + 1 ; tar++){
                 
                 int notpick = 0 + dp[i-1][tar];
        
                 int pick = 1e8;
                 if(coins[i] <= tar)  
                     pick = 1 + dp[i][tar - coins[i]];

                 dp[i][tar] = min(notpick, pick); 
             }
        }
        
        if (dp[n-1][amount] == 0 || dp[n-1][amount]  == 1e8) return -1;
        
        return dp[n-1][amount];
    }


//Approach4 Using Tabulation (More Space Optimization)
//time complexity: O(N * Amount), space complexity: O(Amount) prev and curr array
int coinChange(vector<int>& coins, int amount) {
        
        if (amount == 0) return 0;
        
        int n = coins.size();      
        //base cases
        vector<int> prev(amount+1, 0);
        vector<int> curr(amount+1, 0);
            
        for(int i = 0; i < n; i++)
            prev[0] = 0;
        
        for(int tar = 1; tar < amount+1; tar++){
            if(tar % coins[0] == 0) prev[tar] = tar/coins[0] ;
            else prev[tar] = 1e8;
        }
        
        for(int i = 1; i < n; i++){
            
             for(int tar = 1; tar < amount + 1 ; tar++){
                 
                 int notpick = 0 + prev[tar];
        
                 int pick = 1e8;
                 if(coins[i] <= tar)  
                     pick = 1 + curr[tar - coins[i]];

                 curr[tar] = min(notpick, pick); 
             }
            
            prev = curr;
        }
        
        if (prev[amount] == 0 || prev[amount]  == 1e8) return -1;
        
        return prev[amount];
    }