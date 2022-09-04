/* 
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/ 
*/

#include <iostream>
#include<vector>

using namespace std;


//Method : Plaine Recursion (TLE)
// Time complexity : Exponential
// Space Complexity: Auxillary Rec stack O(N)
class Solution {
public:
    int solveRec(vector<int>& prices, int i, int isBuy, int trasactions){
        
        //base case
        if(trasactions == 0 or i == prices.size()) return 0;
        //rec case
        if(isBuy)   return max(-prices[i] + solveRec(prices, i+1, 0, trasactions), solveRec(prices, i+1, 1, trasactions));
            
        else   return max(prices[i] + solveRec(prices, i+1, 1, trasactions-1), solveRec(prices, i+1, 0, trasactions));
    }
    
    int maxProfit(vector<int>& prices) {
        
        return solveRec(prices, 0, 1, 2);
    }
};

//Memoization: O(N * 2 * 3) Time Complexity and Space Complexity O(N * 2 * 3) for dp array + Aux Rec stack O(N)
class Solution2 {
public:
    int solveRec(vector<int>& prices, int i, int isBuy, int trasactions, vector<vector<vector<int>>> &dp){
        
        //base case
        if(trasactions == 0 or i == prices.size()) return 0;
        
        //rec case
        if (dp[i][isBuy][trasactions] == -1){
            
            if(isBuy)   
                dp[i][isBuy][trasactions] =  max(-prices[i] + solveRec(prices, i+1, 0, trasactions, dp), solveRec(prices, i+1, 1, trasactions, dp));
            
            else   
                dp[i][isBuy][trasactions] =  max(prices[i] + solveRec(prices, i+1, 1, trasactions-1, dp), solveRec(prices, i+1, 0, trasactions, dp));
        }
        
        return dp[i][isBuy][trasactions];
        
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        
        return solveRec(prices, 0, 1, 2, dp);
    }
};

//Tabulation: O(N * 2 * 3) Time Complexity and Space Complexity O(N * 2 * 3) for dp array 
class Solution4 {
public:    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0))); //base cases covered
   
        for(int i = n-1; i >= 0; i--){
            
            for(int isBuy = 1; isBuy >= 0; isBuy--){
                
                for(int trasactions = 2; trasactions > 0; trasactions--){
                    
                    if(isBuy)   
                        dp[i][isBuy][trasactions] =  max(-prices[i] + dp[i+1][0][trasactions], 
                                                        dp[i+1][1][trasactions]);
            
                    else   
                        dp[i][isBuy][trasactions] =  max(prices[i] + dp[i+1][1][trasactions-1],
                                                 dp[i+1][0][trasactions]);    
                }
            }
        }
        
        return dp[0][1][2];
    }
};

//Tabulation: O(N * 2 * 3) Time Complexity and Space Complexity O(2 * 3) -> O(1) for dp array 
class Solution5 {
public:    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0))); //base cases covered
        
        vector<vector<int>> prev(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));
            
        for(int i = n-1; i >= 0; i--){
            
            for(int isBuy = 1; isBuy >= 0; isBuy--){
                
                for(int trasactions = 2; trasactions > 0; trasactions--){
                    
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
        
        return prev[1][2];
    }
};