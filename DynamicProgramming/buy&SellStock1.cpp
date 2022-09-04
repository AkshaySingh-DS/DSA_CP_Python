/* Problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */
#include <iostream>
#include<vector>

using namespace std;

//Brute force - O(N^2) time complexity, O(1) space
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int profit = 0;
        for(int i = n - 1; i > 0; i--){
            
            int mini = prices[i];
            for(int j = i-1; j >= 0; j--){
                 mini = min(mini, prices[j]);
            }
            
            profit = max(profit, prices[i] - mini);
        }
        
        return profit;
        
    }
};

// Bottom UP constructive Algorithm 
// time complexity : O(N), space: O(1)
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;
        
        for(int i = 1; i <  n; i++){
            
            profit = max(profit, prices[i] - mini);
            mini = min(prices[i], mini);// keep track minimum from 0 to i
        }
        
        return profit;
    }
};