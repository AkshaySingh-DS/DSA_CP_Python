/* https://www.codingninjas.com/codestudio/problems/paint-house_1460385
 */

#include<limits.h>
#include <iostream>
#include <vector>
using namespace std;

//memoization
//Time Complexity: O(N*4*3) -> O(12N)-> O(N) which is linear, Space Complexity: O(N)[rec stack]+ O(N*4)[dp array] 
int solveMem(vector<vector<int>> &cost, vector<vector<int>> &dp, int n, int lastColor){
    //base case
    int minCost = INT_MAX;
    if(n == 0){
        for(int c = 0; c < 3; c++){
            if(c != lastColor){
                minCost = min(minCost, cost[0][c]);
            }
        }
        return minCost;
    }
    //rec case
    if(dp[n][lastColor] == -1){
        for(int c = 0; c < 3; c++){
            if(c != lastColor)
                minCost = min(minCost, cost[n][c] + solveMem(cost, dp, n-1, c));
        } 
        dp[n][lastColor] = minCost;
    }
    
    return dp[n][lastColor];
}
int minCost(vector<vector<int>> &cost){
    
    int n = cost.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    
    //memoization
    return solveMem(cost, dp, n-1, 3);
}

//time complexity : O(N*4*3) linear, Space Complexity: O(N * 4) -> O(N)
int minCostTabulation(vector<vector<int>> &cost){

    //Tabulation
    int n = cost.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));

    //dp[i][k] represent paint the ith house but remeber it's adjacent has been painted by kth color already

    dp[0][0] = min(cost[0][1], cost[0][2]);
    dp[0][1] = min(cost[0][0], cost[0][2]);
    dp[0][2] = min(cost[0][1], cost[0][0]);
    dp[0][3] = min(min(cost[0][1], cost[0][2]), cost[0][0]);

    for(int i = 1; i < n; i++){

        for(int lastColor = 0; lastColor < 4; lastColor++){
            int minCost = INT_MAX;
            for(int c = 0; c < 3; c++){

                if( c != lastColor)
                    minCost = min(minCost, cost[i][c] + dp[i-1][c]);
            }

            dp[i][lastColor] = minCost;
        }
    }

    return dp[n-1][3];
}

//space optimization from O(N) - > O(1) on tabular method.
int minCost(vector<vector<int>> &cost){
    //Tabulation with space optimization O(N*4) to O(4) -> O(1) 
    int n = cost.size();
    vector<int>dp(4);
    
    //dp[i][k] represent paint the ith house but remeber it's adjacent has been painted by kth color already
    
    dp[0] = min(cost[0][1], cost[0][2]);
    dp[1] = min(cost[0][0], cost[0][2]);
    dp[2] = min(cost[0][1], cost[0][0]);
    dp[3] = min(min(cost[0][1], cost[0][2]), cost[0][0]);

    for(int i = 1; i < n; i++){
        
        vector <int> temp(4); //using this we'll optimize the stage since only last row is needed not
        //the entire array thats why 
        for(int lastColor = 0; lastColor < 4; lastColor++){
            int minCost = INT_MAX;
            for(int c = 0; c < 3; c++){

                if( c != lastColor)
                    minCost = min(minCost, cost[i][c] + dp[c]);
            }
            temp[lastColor] = minCost;
        }
        dp = temp;  
    }
    
    return dp[3];
}