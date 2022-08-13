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