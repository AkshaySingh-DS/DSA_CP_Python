""" https://leetcode.com/problems/word-break/ """

#using recursion exponetial in time
class Solution(object):
    #time complexity : O(W^N), where W is the length of wordDict and N is the length of string
    def helperRec(self, wordDict, i, s):
        #base case
        if i == len(s):
            return True
        
        #rec case
        for word in wordDict:
            l = len(word)
            if word == s[i: i + l] and self.helperRec(wordDict, i + l, s):
                return True
            
        return False
        
    def wordBreak(self, s, wordDict):
    
        return self.helperRec(wordDict, 0, s)


#using top down dp aka memoization
class Solution(object):

    def helperRec(self, wordDict, i, s, dp):
        #base case
        if i == len(s):
            dp[i] = True
        
        if i in dp:
            return dp[i]

        #rec case
        for word in wordDict:
            l = len(word)
            if word == s[i: i + l] and self.helperRec(wordDict, i + l, s, dp):
                dp[i + l] = True
                return True
            
        dp[i] = False
        return False
        
    def wordBreak(self, s, wordDict):
        
        dp = {}
        return self.helperRec(wordDict, 0, s, dp)
        