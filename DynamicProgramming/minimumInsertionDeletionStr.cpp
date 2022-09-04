/* https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/ */

#include <vector>
#include <iostream>
using namespace std;

/*
Logic : what stoopiong to make both string same ?-> answers is non common characters or (not common subsequences)
So string s1 have len(s1) characters and s2 have len(str2) characters.
What characters that could be maximum and in same ordered in both ? -> longest common subsequence
Hence rest charcaters are which is stopping to make s1 == s2
hence total characters which are stooping them to make equal => len(str1) + len(str2) - 2 * LCS (since LCS present in both s1 and s2 hence subtracting it twice)
*/
//Time Complexity : O(n * m)
//Space Complexity : O(m) 

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length(), m = word2.length();
        
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        //calculating lcs
        for(int i = 1; i < n + 1; i++){
            
            for(int j = 1; j < m + 1; j++){
                
                if(word1[i-1] == word2[j-1])   curr[j] = 1 + prev[j-1];
            
                else{
                    
                    if(prev[j] >= curr[j-1]) curr[j] = prev[j];
                    else curr[j] = curr[j-1];                    
                }
            }
            prev = curr;
        }
        
        return n + m - (2 * prev[m]);
    }
};