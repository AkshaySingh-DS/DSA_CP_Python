/* 
Problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
 */
#include <iostream>
#include<vector>

using namespace std;


//Method : Plaine Recursion (TLE)
// Time complexity : Exponential
// Space Complexity: Auxillary Rec stack O(N)
class Solution1 {
public:
      int solveRec(vector<int>& prices, int i, int isBuy){
        
            //base case
            if(i >= prices.size()) return 0;

            //rec case
            if(isBuy){

                int buy = -prices[i] + solveRec(prices, i+1, 0); //similar case of buy & sell Stocks problem 2
                int notbuy = 0 + solveRec(prices, i+1, 1); // similar case of buy & sell Stocks problem 2

                return max(buy, notbuy);
            }
            else{

                int sell = prices[i] + solveRec(prices, i+2, 1); //similar, but since trasaction completed make cooldown(wil not try for i+1)
                int notsell = 0 + solveRec(prices, i+1, 0); // similar case of buy & sell Stocks problem 2

                return max(sell, notsell);
            }    
    }
    int maxProfit(vector<int>& prices) {
        
        return solveRec(prices, 0, 1);
    }
};

//Memoization: O(n*2) Time and Space O(n*2) for dp array
class Solution2 {
public:
      int solveMem(vector<int>& prices, int i, int isBuy, vector<vector<int>> &dp){
        
            //base case
            if(i >= prices.size()) return 0;

            //rec case
            if(dp[i][isBuy] == -1){
                
                if(isBuy){

                    int buy = -prices[i] + solveMem(prices, i+1, 0, dp); //similar case of buy & sell Stocks problem 2
                    int notbuy = 0 + solveMem(prices, i+1, 1, dp); // similar case of buy & sell Stocks problem 2

                    dp[i][isBuy] = max(buy, notbuy);
                }
                else{

                    int sell = prices[i] + solveMem(prices, i+2, 1, dp); //similar, but since trasaction completed make cooldown(wil not try for i+1)
                    int notsell = 0 + solveMem(prices, i+1, 0, dp); // similar case of buy & sell Stocks problem 2

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
        
        vector<vector<int>> dp(prices.size() + 2, vector<int>(2, 0)); //base case covered why (n+2) size ?
        //Since there is n+1 in line#24 which leads to overflow for i = n-1
        int n = prices.size();
        
        for(int i = n-1; i >= 0; i--){
            
                for(int isBuy = 1; isBuy >= 0; isBuy--){

                    if(isBuy){

                        int buy = -prices[i] + dp[i+1][0]; 
                        int notbuy = 0 + dp[i+1][1]; 

                        dp[i][isBuy] = max(buy, notbuy);
                    }

                    else{

                        int sell = prices[i] + dp[i+2][1]; 
                        int notsell = 0 + dp[i+1][0]; 

                        dp[i][isBuy] = max(sell, notsell);
                    }  

                }
        }
       
        return dp[0][1];
    }
};

//try to optimize space further 