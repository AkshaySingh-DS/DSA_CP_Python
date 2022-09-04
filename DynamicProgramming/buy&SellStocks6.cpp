/* 
Problem Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
*/

#include <iostream>
#include<vector>

using namespace std;

//Memoization: O(N * 2)-> O(N) Time Complexity, and Space Complexity O(N * 2) -> O(N) for dp array + Aux Rec stack O(N)
class Solution1 {
public:
    int solveRec(vector<int>& prices, int i, int isBuy, int fee, vector<vector<int>> &dp){
        
            //base case
            if(i == prices.size()) return 0;

            //rec case
            if(dp[i][isBuy] == -1){
                
                if(isBuy){

                    dp[i][isBuy] = max(-prices[i] + solveRec(prices, i+1, 0, fee, dp),
                                       solveRec(prices, i+1, 1, fee, dp));
                }
                else{

                    dp[i][isBuy] = max(prices[i] + solveRec(prices, i+1, 1, fee, dp) - fee, 
                                       solveRec(prices, i+1, 0, fee, dp));
                } 
            }
        
        return dp[i][isBuy];
               
    }
    int maxProfit(vector<int>& prices, int fee) {
        
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solveRec(prices, 0, 1, fee, dp);
        
    }
};

//Tabulation: O(N * 2) -> O(N) Time Complexity and, Space Complexity O(N * 2) -> O(N) for dp array

class Solution2 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));//base case covered
        
        for(int i = n - 1; i >= 0; i--){
            
            for(int isBuy = 1; isBuy >=0; isBuy-- ){
                
                if(isBuy){

                    dp[i][isBuy] = max(-prices[i] + dp[i+1][0],
                                       dp[i+1][1]);
                }
                else{

                    dp[i][isBuy] = max(prices[i] + dp[i+1][1] - fee, 
                                       dp[i+1][0]);
                } 
            }
        }
        return dp[0][1] ;  
    }
};

//Tabulation (Space Optimization): O(N * 2) -> O(N) Time Complexity and, Space Complexity 2 * O(2) -> O(1) for dp array
class Solution3 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));//base case covered
        vector<int> prev(2, 0);
        vector<int> curr(2, 0);
        
        for(int i = n - 1; i >= 0; i--){
            
            for(int isBuy = 1; isBuy >=0; isBuy-- ){
                
                if(isBuy){

                    curr[isBuy] = max(-prices[i] + prev[0],
                                       prev[1]);
                }
                else{

                    curr[isBuy] = max(prices[i] + prev[1] - fee, 
                                       prev[0]);
                } 
            }
            prev = curr;
        }
        return prev[1] ;  
    }
};

//Tabulation (Space Optimization - 4 variables): O(N * 2) -> O(N) Time Complexity and, Space Complexity O(1) for dp array
class Solution4 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0)); //base case covered
        
        //using four variable insted of array
        int prev_0, prev_1, curr_0, curr_1;
        curr_0 = curr_1 = prev_0 = prev_1 = 0;
        
        for(int i = n - 1; i >= 0; i--){
            
            for(int isBuy = 1; isBuy >=0; isBuy-- ){
                
                if(isBuy){

                    curr_1 = max(-prices[i] + prev_0,
                                       prev_1);
                }
                else{

                    curr_0 = max(prices[i] + prev_1 - fee, 
                                       prev_0);
                } 
            }
            prev_0 = curr_0;
            prev_1 = curr_1; 
        }
        return prev_1 ;  
    }
};