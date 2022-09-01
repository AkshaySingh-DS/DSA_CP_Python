//problem : print the longest common subsequence 

#include <iostream>
#include <vector>
using namespace std;


void PrintlongestCommonSubsequence(string text1, string text2) {      
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        //base cases
        for(int i = 0; i < n+1; i++){
            dp[i][0] = 0;
        }
        for(int j = 0; j < m+1; j++){
            dp[0][j] = 0;
        }
        
        for(int i = 1 ;i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){

                 if(text1[i-1] == text2[j-1]) dp[i][j]  = 1 + dp[i-1][j-1];
                 else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        int index =  dp[n][m];     
        string ans= "";
        for(int i = 0; i < index; i++) ans += '$';
        
        int i = n;
        int j = m;
        while(i > 0 and j > 0){

            //if match 
            if(text1[i-1] == text2[j-1]){
                ans[--index] = text1[i-1];
                i--; j--;
            }
            //if not match
            else{
                
                if(dp[i-1][j] >= dp[i][j-1])
                i--;

                else j--;
            }  
        }

    cout << ans << endl;
}

int main(){

    string s1, s2;
    cin >> s1 >> s2;

    PrintlongestCommonSubsequence(s1 ,s2);
    return 0;
}