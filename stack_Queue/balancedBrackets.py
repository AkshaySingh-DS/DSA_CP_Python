"""
Problem statement : https://leetcode.com/problems/valid-parentheses/
Time Complexity : O(N)
Space Complexity : O(N)

Python solution of valid brackets problem 
Using hashmap and stack approach
"""

class Solution(object):
    def isValid(self, s):
        mapp = {'(' : ')', '{' : '}', '[' :  ']'}

        stack = []

        for ch in s:
            if ch in mapp:
                stack.append(ch)
            
            #think about the false case only 
            elif not stack or ch != mapp[stack.pop()]:
                return False
            
        return stack == [] 