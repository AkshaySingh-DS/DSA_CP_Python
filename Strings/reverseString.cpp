/* 
Problem Statement : 
https://leetcode.com/problems/reverse-string/

Time complexity O(n) space is also O(1) 
 */


//using two pointer approach
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        
    int start = 0, end = s.size()-1;

    while (start < end)
        swap(s[start++], s[end--]);
    }
    
};

//python solution (3 Approach)
/* class Solution(object):
    def  helper(self, s, left, right):
        #base case
        if (left >= right):
            return 
        
        s[left], s[right] = s[right], s[left]
        
        self.helper(s, left+1, right-1)
        
        
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        
        #mirror image solution
        """"mid = len(s)//2
        
        for i in range(mid): 
            s[i], s[-i-1] = s[-i-1], s[i]
        """
        
        #two pointer already knows
        #recursion O(n) time, O(n) space
        left, right = 0, len(s)-1
        self.helper(s, left, right) */