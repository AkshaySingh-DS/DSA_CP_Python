/* 
Problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
 */
#include <iostream>
#include<vector>

using namespace std;


//Method : plane Recursion (TLE)
// time complexity : Exponential
// Space Complexity: Auxillary Rec stack O(N)
class Solution1 {
public:
    int solveRec(vector<int>& prices, int i, int isBuy){
        
        //base case
        if(i == prices.size()) return 0;
        
        //rec case
        if(isBuy){
            
            int buy = -prices[i] + solveRec(prices, i+1, 0); //will not sell on same day since it make profits 0, and hold it by making flag 0
            int notbuy = 0 + solveRec(prices, i+1, 1); // keep buy flag as 1 since the since the current stock now yet bought
            
            return max(buy, notbuy);
        }
        else{
            
            int sell = prices[i] + solveRec(prices, i+1, 1); // make flag buy as 1 since the previously hold stock now sold
            int notsell = 0 + solveRec(prices, i+1, 0); // keep buy flag as 0 since the previously hold stock still on hold not sold yet
            
            return max(sell, notsell);
        }    
    }
    int maxProfit(vector<int>& prices) {
        
        return solveRec(prices, 0, 1);
    }
};

//Memoization : O(n*2) -> O(n) Time and Space O(n*2) + O(n) -> (n)
class Solution2{
public:
    int solveMem(vector<int>& prices, int i, int isBuy, vector<vector<int>> &dp){
        
        //base case
        if(i == prices.size()) return 0;
        
        //rec case
        if(dp[i][isBuy] == -1){
            if(isBuy){
            
                int buy = -prices[i] + solveMem(prices, i+1, 0, dp); //will not sell on same day since it make profits 0, and hold it by making flag 0
                int notbuy = 0 + solveMem(prices, i+1, 1, dp); // keep buy flag as 1 since the since the current stock now yet bought

                dp[i][isBuy] = max(buy, notbuy);
            }
            else{
            
                int sell = prices[i] + solveMem(prices, i+1, 1, dp); // make flag buy as 1 since the previously hold stock now sold
                int notsell = 0 + solveMem(prices, i+1, 0, dp); // keep buy flag as 0 since the previously hold stock still on hold not sold yet

               dp[i][isBuy] = max(sell, notsell);
            }    
        }
        
        return dp[i][isBuy];
        
    }
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1)); 
        return solveMem(prices, 0, 1, dp);
    }
};

//Tabulation: O(n*2) Time and Space O(n*2) for dp array
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0)); //base case covered
        
        for(int i = n-1; i >= 0; i--){
            
            for(int isBuy = 1; isBuy >= 0; isBuy--){
                
                if(isBuy){
            
                int buy = -prices[i] + dp[i+1][0]; 
                int notbuy = 0 + dp[i+1][1]; 

                dp[i][isBuy] = max(buy, notbuy);
                }
                
                else{

                    int sell = prices[i] + dp[i+1][1]; 
                    int notsell = 0 + dp[i+1][0]; 

                    dp[i][isBuy] = max(sell, notsell);
                }  
                
            }
        }
       
        return dp[0][1];
    }
};

//Tabulation: O(n*2) Time and Space O(1) for array size is just 2 Blocks
class Solution4 {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        vector<int> prev(2, 0), curr(2, 0); // can be solve using four varibles 2 for prev and 2 for curr 
        
        
        for(int i = n-1; i >= 0; i--){
            
            for(int isBuy = 1; isBuy >= 0; isBuy--){
                
                if(isBuy){
            
                int buy = -prices[i] + prev[0]; 
                int notbuy = 0 + prev[1]; 

                curr[isBuy] = max(buy, notbuy);
                }
                
                else{

                    int sell = prices[i] + prev[1]; 
                    int notsell = 0 + prev[0]; 

                    curr[isBuy] = max(sell, notsell);
                }  
                
            }
            prev = curr;
        }
       
        return prev[1];
    }
};

//solve using four variable approach
//wrote four vairiable approach in Buy & Sell Stock problem #6