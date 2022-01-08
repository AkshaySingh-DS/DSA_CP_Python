"""
Problem Statement: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

Time complexity : O(N+K)
Space Complexity : O(1) using CPP
"""

"""THIS PROBLEM CAN BE SOLVE USING KMP AND Z ALGOS"""
class Solution(object):
    
    def removeOccurrences(self, s, part):
        #space complexity O(N) -> strings are immutable in python
        partSize = len(part)
        while part in s:
            idx = s.find(part)
            s = s[:idx] + s[idx + partSize:]
        
        return s

"""
CPP SOLUTION:
space complexity : O(1)
class Solution {
public:
    string removeOccurrences(string s, string part) {
        
        //keeping on erasing the pattern if it's present
        //time O(N + K) -> k is the pattern length, N is the string
        int idx = s.find(part);
        while(idx < s.length()){
            s.erase(idx, part.length());
            idx = s.find(part);
        }

        return s;
    }
};
"""