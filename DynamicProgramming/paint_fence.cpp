/* Probelem Statement: Given a fence with n posts and k colors, find out the number of 
ways of painting the fence so that not more than two consecutive fences have the same 
colors. Since the answer can be large return it modulo 10^9 + 7.

problem link: https://practice.geeksforgeeks.org/problems/painting-the-fence3727/1
or https://www.codingninjas.com/codestudio/problems/ninja-and-the-fence_3210208

*/
#include <vector>
#include <iostream>
#define MOD 1000000007
using namespace std;

// Using plaine Recursion
//time complexity: O(2^N), space O(N)[Rec Stack]
int solveRec(int n, int k){

    //base case
    if(n == 1) return k;

    if(n == 2) return k * k;
    
    //rec case
    int sameColorAtLast  =  solveRec(n-2, k) * (k-1);
    int diffClorAtLast = solveRec(n-1, k) * (k-1);

    return sameColorAtLast + diffClorAtLast;

}

// Top Down DP
//time complexity: O(N), space O(N)[Rec Stack] + O(N)  for dp array 
long long solveMem(int n, int k, vector<long long> &dp){

    //base case
    if(n == 1) return (k % MOD);
    if(n == 2) return ((k % MOD) * (k % MOD)) % MOD;
    
    //rec case
    if(dp[n] == -1){
        long long sameColorAtLast  =  ((solveMem(n-2, k, dp) % MOD)  * ((k-1) % MOD)) % MOD;
        long long diffClorAtLast = ((solveMem(n-1, k, dp) % MOD) * ((k-1) % MOD) % MOD);

        dp[n] = (sameColorAtLast + diffClorAtLast) % MOD;
    }
    return dp[n];
}

// Bottom up DP aka Tabulation 
//time complexity: O(N), space O(N) for dp array 
int numberOfWays(int n, int k){
    //return solveRec(n, k);
    vector <long long> dp(n+1);
    //return solveMem(n, k, dp);

    dp[1] = k;
    dp[2] = ((k % MOD) * (k % MOD)) % MOD;

    for(int i = 3; i < n+1 ;i++){

        long long sameColorAtLast  =  ((dp[i-2] % MOD)  * ((k-1) % MOD)) % MOD;
        long long diffClorAtLast = ((dp[i-1] % MOD) * ((k-1) % MOD) % MOD);
        dp[i] = (sameColorAtLast + diffClorAtLast) % MOD;
    }

    return dp[n];
}

// Bottom UP DP with space optimization
//time complexity: O(N), space O(1) 
int numberOfWays(int n, int k){
    long long prev2 = k;
    if(n==1) return prev2; 

    long long prev1 = ((k % MOD) * (k % MOD)) % MOD;
    if(n == 2) return prev1;


    for(int i = 3; i < n+1 ;i++){

        long long sameColorAtLast  =  ((prev2 % MOD)  * ((k-1) % MOD)) % MOD;
        long long diffClorAtLast = ((prev1 % MOD) * ((k-1) % MOD) % MOD);
        prev2 = prev1;
        prev1 = (sameColorAtLast + diffClorAtLast) % MOD;
    }
    return prev1;
}