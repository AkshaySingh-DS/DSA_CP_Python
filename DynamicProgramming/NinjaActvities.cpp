/* 
Probelem Statement: https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003 
Time Complexity : 
Space Complexity : 

*/

#include <vector>
#include <iostream>
using namespace std;

//Using Recursion 
//time complexity : O(2^N), Space Complexity : (N)
int solveRec(int n, vector<vector<int>> &points, int lastActivity){

    //base case
    if(n < 0) return 0;

    //rec case
    int maxPoints = INT_MIN;
    for(int i = 0; i < points[0].size(); i++){
        if(i != lastActivity){

            int task = points[n][i] + solveRec(n-1, points, i);
            maxPoints = max(maxPoints, task);
        } 
    }
    return  maxPoints;
}

//Using Memoization
//time complexity : O(N), Space Complexity : O(N) (rec Stack) + O(N) (dp array) --> O(N)
int solveMem(int n, vector<vector<int>> &points, int lastActivity, vector<vector<int>> &dp){
    //base case
    if(n == 0){
        int maxi = 0;
        for(int i = 0; i < 3; i++){
            if(i != lastActivity) maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    
    //rec case
    int maxPoints = 0;
    if(dp[n][lastActivity] == -1){
        for(int i = 0; i < 3; i++){
            if(i != lastActivity){
                
                int p = points[n][i] + solveMem(n-1, points, i, dp);
                maxPoints = max(maxPoints, p);            
           } 
        } 
        dp[n][lastActivity] = maxPoints;
    }
    
    return dp[n][lastActivity];
}

//Using Tabulation
//time complexity : O(N * 4 * 3) -> O(N), Space Complexity : + O(N*4) (dp array) --> O(N)
int ninjaTraining(int n, vector<vector<int>> &points){

    //vector<vector<int>> dp(n, vector<int>(4, -1));
    //return solveMem(n-1, points, 3, dp);
    vector <vector<int>> dp(n, vector<int>(4));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][2], points[0][0]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(points[0][2], max(points[0][0], points[0][1]));
    
    for(int i = 1; i < n; i++){
       
        for(int last = 0; last < 4; last++){
            int maxi = 0;

            for(int task = 0; task < 3; task++){
                if(last != task)
                    maxi = max(maxi, points[i][task] + dp[i-1][task]);
            }

           dp[i][last] = maxi;
        }
    }

    return dp[n-1][3];  
}

//Using Tabulation with Space Optimization 
//time complexity : O(N * 4 * 3) -> O(N), Space Complexity : + O(4) (array) --> O(1)
int ninjaTraining(int n, vector<vector<int>> &points){

    //vector<vector<int>> dp(n, vector<int>(4, -1));
    //return solveMem(n-1, points, 3, dp);
    vector <int> prev(4);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][2], points[0][0]);
    prev[2] = max(points[0][1], points[0][0]);
    prev[3] = max(points[0][2], max(points[0][0], points[0][1]));

    for(int i = 1; i < n; i++){
       vector <int> temp(4);
        for(int last = 0; last < 4; last++){
            int maxi = 0;

            for(int task = 0; task < 3; task++){
                if(last != task)
                    maxi = max(maxi, points[i][task] + prev[task]);
            }
           temp[last] = maxi;
        }
        prev = temp;
    }

    return prev[3];  
}