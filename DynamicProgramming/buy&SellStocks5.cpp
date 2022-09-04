/* 
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
*/

#include <iostream>
#include<vector>

using namespace std;

//Same as Buy And Sell Stock IV
//Method : Plaine Recursion (TLE)
// Time complexity : Exponential
// Space Complexity: Auxillary Rec stack O(N)
class Solution1 {
public:
    int solveRec(vector<int>& prices, int i, int isBuy, int trasactions){
        
        //base case
        if(trasactions == 0 or i == prices.size()) return 0;
        //rec case
        if(isBuy)   return max(-prices[i] + solveRec(prices, i+1, 0, trasactions), solveRec(prices, i+1, 1, trasactions));
            
        else   return max(prices[i] + solveRec(prices, i+1, 1, trasactions-1), solveRec(prices, i+1, 0, trasactions));
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        return solveRec(prices, 0, 1, k);
        
    }
};

//Same as Buy And Sell Stock IV with slight change instead of two transactions there is K transactions
//Memoization: O(N * K * 3) Time Complexity and Space Complexity O(N * K * 3) for dp array + Aux Rec stack O(N)
class Solution2 {
public:
    int solveMem(vector<int>& prices, int i, int isBuy, int trasactions, vector<vector<vector<int>>> &dp){
        
        //base case
        if(trasactions == 0 or i == prices.size()) return 0;
        //rec case
        if(dp[i][isBuy][trasactions] == -1){
            
            if(isBuy)   
                dp[i][isBuy][trasactions] = max(-prices[i] + solveMem(prices, i+1, 0, trasactions, dp),
                                                solveMem(prices, i+1, 1, trasactions, dp));
            
            else  
                dp[i][isBuy][trasactions] =  max(prices[i] + solveMem(prices, i+1, 1, trasactions-1, dp), 
                                                solveMem(prices, i+1, 0, trasactions, dp));
        }
        
        return dp[i][isBuy][trasactions];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solveMem(prices, 0, 1, k, dp);
        
    }
};

//Tabulation: O(N * K * 2) Time Complexity and Space Complexity O(N * K * 2) for dp array
class Solution3{
public:    
   int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, 0))); //base cases covered
        
        for(int i = n-1; i >=0 ; i--){
            
            for(int isBuy = 1; isBuy >= 0; isBuy--){
                
                for(int trasactions = k; trasactions > 0; trasactions--){
                    
                     if(isBuy)   
                        dp[i][isBuy][trasactions] =  max(-prices[i] + dp[i+1][0][trasactions], 
                                                        dp[i+1][1][trasactions]);
            
                    else   
                        dp[i][isBuy][trasactions] =  max(prices[i] + dp[i+1][1][trasactions-1],
                                                 dp[i+1][0][trasactions]);    
                }
            }
        }
        return dp[0][1][k];     
    }
};


//Tabulation (Space Optimization): O(N * K * 2) Time Complexity and Space Complexity O(K * 2)-> O(K) for dp array
class Solution4 {
public:    
   int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> prev(2, vector<int>(k+1, 0));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        
        for(int i = n-1; i >= 0 ; i--){
            
            for(int isBuy = 1; isBuy >= 0; isBuy--){
                
                for(int trasactions = k; trasactions > 0; trasactions--){
                    
                     if(isBuy)   
                        curr[isBuy][trasactions] =  max(-prices[i] + prev[0][trasactions], 
                                                        prev[1][trasactions]);
            
                    else   
                        curr[isBuy][trasactions] =  max(prices[i] + prev[1][trasactions-1],
                                                 prev[0][trasactions]);    
                }
                
                prev = curr;
            }
        }
        return prev[1][k];     
    }
};