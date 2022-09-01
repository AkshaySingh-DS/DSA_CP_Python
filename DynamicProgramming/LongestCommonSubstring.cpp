/* 
https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207 
*/

#include <iostream>
#include <vector>
using namespace std;

//Tabulation Approach:
//Time Complexity:  O(n * m), Space Complexity O(n * m) 
int lcs(string &str1, string &str2){
    
    //slight change in longest common subsequences tabulation approach (using 1 based indexiing)
    //dp[i][j] -> longest common substring from 0 to i in s1 and 0 to j in s2
    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n+1, vector<int> (m+1, 0)); //base case already covered here for i ==0 and j ==0
    
    int maxi = 0;
    
    for(int i = 1; i < n+1; i++){
        
        for(int  j = 1; j < m+1; j++){
            
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi = max(maxi, dp[i][j]);
             }
            else dp[i][j] = 0; // change is here since here the contnuity is breaking hence it would be zero, i and j no longer be the part of contguous substring 
        }
    }
    return maxi; 
}


//Tabulation Approach : Space Optimization 
//Time Complexity:  O(n * m), Space Complexity O(n+m)
int lcs(string &str1, string &str2){
    
    //slight change in longest common subsequences tabulation approach (using 1 based indexiing)
    //dp[i][j] -> longest common substring from 0 to i in s1 and 0 to j in s2
    int n = str1.length(), m = str2.length();
    //base case already covered here for i == 0 and j ==0
    vector <int> prev(m + 1, 0);
    vector <int> curr(m + 1, 0);
    
    int maxi = 0;
    
    for(int i = 1; i < n+1; i++){
        
        for(int  j = 1; j < m+1; j++){
            
            if(str1[i-1] == str2[j-1]){
                curr[j] = 1 + prev[j-1];
                maxi = max(maxi, curr[j]);
             }
            else curr[j] = 0; // change is here since here the contnuity is breaking hence it would be zero, i and j no longer be the part of contguous substring 
        }
        prev = curr;
    }
    
    return maxi; 
} 