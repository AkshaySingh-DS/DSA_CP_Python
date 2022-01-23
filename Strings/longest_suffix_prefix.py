"""
problem Statement : https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1#
"""

"""
Approach 1: What can be the maximum prefix which is equal to suffix len/2.
Hence we'll start from mid by selecting maximum prefix and suffix if match return len else 
reduce the window from both the side i.e. from left and right.
Time complexity : O(n^2)
space: O(1)
"""
def longestPrefixSuffix(string):
    #using two pointer approach
    i = len(string)//2 - 1
    j = i+2 if len(string) & 1 else i+1

    while i >= 0 and j <= len(string)-1:

        prefix = string[0 : i+1]
        suffix = string[j : len(string)]

        if prefix == suffix:
            return i+1
        
        i -= 1
        j += 1

    return 0


#Approach - 2 using KMP method
# time complexity:O(n)
# space : O(n) 
def computeLPS(s):
    patternlen = len(s)
    lps = [0] * patternlen

    # logic
    i = 1; j = 0
    while i < patternlen and j < i:
        if s[i] == s[j]:
            lps[i] = j+1
            i += 1
            j += 1
        else:
            if j != 0:
                j = lps[j-1]
            else:
                lps[i] = 0
                i += 1
    return lps[patternlen-1]
    #overlapping region not acceptible if mention use below (max prefix length would be paatern /2)
    #return lps[patternlen-1] if lps[patternlen-1] < patternlen//2 else lps[patternlen-1]//2


"""
CPP SOLUTION:
class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    
	    int size = s.length();
	    int i = 1, j = 0;
	    
	    int lps[size] = {0};
	    lps[0] = 0;
	    
	    while (i < size){
	        
	       if (s[i] == s[j]){
	           
	           j++;
	           lps[i] = j;
	           i++;
	       }
	       
	       else{
	           
	           if (j != 0) j = lps[j-1];
	           else lps[i++] = 0;
	       }
	    }
	    
	    return lps[size-1];
	}
};
"""