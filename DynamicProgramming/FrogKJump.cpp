/* Problem Statement : https://atcoder.jp/contests/dp/tasks/dp_b
Time Complexity : O(N*K)
Space Complexity : O(N)*/
#include <iostream>
#include <vector>
using namespace std;

//using plaine recursion time complexity : O(K^n), space : O(k^N)
int frogKJump(vector <int> &cost, int n, int k){
    //base case
    if(n <= 0) return 0;
    if (n == 1) abs(cost[1] - cost[0]);

    //rec case
    int ans = INT_MAX;
    for(int j = 1; j <= k; j++){
    
        if(n-j >= 0){
            int costt = frogKJump(cost, n-j, k) + abs(cost[n] - cost[n-j]);
            ans = min(costt, ans);
        }
    }
    return ans;
}

//using memoized dp - topdown approach  time: O(N*K), space O(N)
int frogKJump(vector <int> &cost, int i, int k, vector<int> &dp){
    //base case
    if(i <= 0) return 0;
    if (i == 1) abs(cost[1] - cost[0]);

    //rec case
    if (dp[i] == -1){
       int ans = INT_MAX;
        for(int j = 1; j <= k; j++){
        
            if(i-j >= 0){
                int costt = frogKJump(cost, i-j, k, dp) + abs(cost[i] - cost[i-j]);
                ans = min(costt, ans);
            }
        }
        dp[i] = ans;
    }
    return dp[i];
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int>cost(n);
    for(int i = 0; i < n; i++)
        cin >> cost[i];
    //vector<int> dp(n, -1);
    cout << frogKJump(cost, n-1, k);
    
    return 0;
}