/* https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542?leftPanelTab=1 */

#include <iostream>
#include<vector>

using namespace std;

//Approach: Plaine Recursion
//Time Complexity: O(2^N), Space Complexity: O(N) for Auxillary Recursive Stack
int solveRec(vector<int> &weight, vector<int> &value, int i, int w){
    
    //base case
    if(i == 0){
        if(weight[0] <= w) return value[0];
        return 0;
    }
    //rec case
    int notpick = 0 + solveRec(weight, value, i-1, w);
    
    int pick = -1e8;
    if(weight[i] <= w)
        pick = value[i] + solveRec(weight, value, i-1, w - weight[i]);
   
    return max(pick, notpick);
    
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	
    //vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1))
    return solveRec(weight, value, n-1, maxWeight);
}

//Approach: Memoization aka Top down dp
//Time Complexity: O(N*W), Space Complexity: O(N*W) for dp array + O(N) for Aux Rec Stack
int solveMem(vector<int> &weight, vector<int> &value, int i, int w, vector<vector<int>> &dp){
    
    //base case
    if(i == 0){
        if(weight[0] <= w) return value[0];
        return 0;
    }
    //rec case
    if(dp[i][w] == -1){
        int notpick = 0 + solveMem(weight, value, i-1, w, dp);
        int pick = -1e8;
        if(weight[i] <= w)
            pick = value[i] + solveMem(weight, value, i-1, w - weight[i], dp);

        dp[i][w] = max(pick, notpick);
    }
    
    return dp[i][w];
    
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    return solveMem(weight, value, n-1, maxWeight, dp);
}

//Approach: Bottom UP DP aka Tabulation 
//Time Complexity: O(N*W), Space Complexity: O(N*W) for dp array
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    
    //base cases, dp[i][0] will be zero since w==0 no weight can be assign 
    for(int w = 1; w < maxWeight+1; w++){
        if(weight[0] <= w) dp[0][w] = value[0];
    }
        
    for(int i = 1; i < n; i++){
        
       for(int w = 1; w < maxWeight+1; w++){
            int notpick = 0 + dp[i-1][w];
            int pick = -1e8;
            if(weight[i] <= w)
                pick = value[i] + dp[i-1][w - weight[i]]; // w-weight[i] >= 0 

            dp[i][w] = max(pick, notpick);
       }
    }  
    return dp[n-1][maxWeight];
    //return solveMem(weight, value, n-1, maxWeight, dp);  
}

//Approach: Bottom UP DP aka Tabulation with space optimization
//Time Complexity: O(N*W), Space Complexity: O(W)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
    //base cases, dp[i][0] will be zero since w==0 no weight can be assign 
    //State dp[i][w] -> get the maximum value of knapsack sizwe w by selecting 0 to ith items
    vector <int> prev(maxWeight+1, 0);
    vector <int> curr(maxWeight+1, 0);
    for(int w = 1; w < maxWeight+1; w++){
        if(weight[0] <= w) prev[w] = value[0];
    }
        
    for(int i = 1; i < n; i++){
       for(int w = 1; w < maxWeight+1; w++){
            int pick = weight[i] <= w ? value[i] + prev[w - weight[i]]: -1e8;
            curr[w] = max(pick, prev[w]);
       }
        prev = curr;
    }  
    return prev[maxWeight]; 
}