/* 
https://www.codingninjas.com/codestudio/problems/ninja-s-contract_1459321
*/

#include <iostream>
#include<limits.h>
#include <vector>
using namespace std;

//Plane Recursion
//time complexity : , Space Complexity: 
int solveRec(int n, int k, int lastColor, vector<vector<int>> &costs){
    //base case
    int minCost = INT_MAX;
    if(n == 0){
        for(int c = 0; c < k; c++){
            if(c != lastColor)
                minCost = min(minCost, costs[0][c]);
        }
        return minCost;
    }

    //rec case
    for(int c = 0; c < k; c++){

        if(c != lastColor){

            int amount = costs[n][c] + solveRec(n-1, k, c, costs);
            minCost = min(amount, minCost);
        }
    }

    return minCost;
}

//memoization
//time complexity : , Space Complexity:  
int solveMem(int n, int k, int lastColor, vector<vector<int>> &costs, vector<vector<int>> &dp){
    //base case
    int minCost = INT_MAX;
    if(n == 0){
        for(int c = 0; c < k; c++){
            if(c != lastColor)
                minCost = min(minCost, costs[0][c]);
        }
        return minCost;
    }

    //rec case
    if(dp[n][lastColor] == -1){

        for(int c = 0; c < k; c++){

            //try all colors and take the ans which will give the minimum 
            if(c != lastColor){

                int amount = costs[n][c] + solveMem(n-1, k, c, costs, dp);
                minCost = min(amount, minCost);
            }
        }
        //update the dp array
        dp[n][lastColor] = minCost;
    }

    return dp[n][lastColor];
}

int paintCost(int n, int k, vector<vector<int>> &costs){
   
   //return solveRec(n-1, k, k, costs);
   vector<vector<int>> dp(n, vector<int>(k+1, -1));
   return solveMem(n-1, k, k, costs, dp);
}
