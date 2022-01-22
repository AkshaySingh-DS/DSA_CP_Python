"""
Problem Statement: https://leetcode.com/problems/is-subsequence/

Time complexity : O(M + N), length of subsequence M, N given string
"""

class Solution(object):
    def isSubsequence(self, s, t):
        #iterate over he subsequnce
        for ch in s:
            
            #do we have this character in given string t (more optimized way using binary search)
            idx = t.find(ch)
            
            # character not found not possible subsequece
            if idx == -1:
                return False
            
            #if found then start searching after that index
            t = t[idx+1:] 
        
        return True

"""
CPP solution :

 //two poinetrs approach  
class Solution {
public:
    
    bool isSubsequence(string s, string t) {
        
    //straignt forward case -> not needed
    if (s.length() > t.length())
        return false;
      
    int i = 0, j = 0;
    
    while (i < t.length() and j < s.length()){
        
        //charcater matched
        if(t[i] == s[j])
            j++;    
            
        i++;     
     }
        
    //subsequenes found sign
    if( j >= s.length())
        return true;
    
    return false;
        
    }
};

Follow UP : using binary search. If there are k number of subsequences, and k > N(given string)
then use binary search -> O((k*M*log N))
"""