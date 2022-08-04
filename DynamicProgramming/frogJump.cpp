/* problem Statement : https://www.codingninjas.com/codestudio/problems/frog-jump_3621012?leftPanelTab=0 

Time Complexity : O(N) and O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

//Memoization top down solution time: O(N) space O(N)
int solveMem(vector<int> &heights, int n, vector<int> &dp){
    //base case
    if(n == 0) return 0;
    if(n == 1) return abs(heights[1] - heights[0]);

    //rec case
    if (dp[n] == -1){
        
        int oneStep = INT_MAX, twoStep = INT_MAX;  
        oneStep = solveMem(heights, n-1, dp) + abs(heights[n] - heights[n-1]);
        twoStep = solveMem(heights, n-2, dp) + abs(heights[n] - heights[n-2]);
        dp[n] = min(oneStep, twoStep);
    }
    
    return dp[n];
    
}
int frogJump(int n, vector<int> &heights){
    vector<int>dp(n, -1);
    return solveMem(heights, n-1, dp);  
}

//Bottom Up approach - Tabulation time : O(N), space : O(1)
int frogJump(int n, vector<int> &heights){

    if(n == 0) return 0;
    if(n == 1) return abs(heights[1] - heights[0]);

    int prev1 =  0, ans;
    int prev2 = abs(heights[1] - heights[0]);

    for(int i = 2; i < n; i++){

        int one = prev2 + abs(heights[i] - heights[i-1]);
        int two  = prev1 + abs(heights[i] - heights[i-2]);

        ans = min(one, two);
        prev1 = prev2;
        prev2 = ans;
    }
    return ans;
}

//below is pure recursive solution time: O(2^N) space O(N)
int solveMem(vector<int> &heights, int n){

    //base case
    if(n == 0) return 0;

    //rec case
    int oneStep = INT_MAX, twoStep = INT_MAX;  
  
    oneStep = solveMem(heights, n-1) + abs(heights[n] - heights[n-1]);
        
    if(n > 1)
         twoStep = solveMem(heights, n-2) + abs(heights[n] - heights[n-2]);
        
    return min(oneStep, twoStep);
}
int frogJump(int n, vector<int> &heights)
{
    //vector<int>dp(n+1, -1);
    return solveMem(heights, n-1);
    
}