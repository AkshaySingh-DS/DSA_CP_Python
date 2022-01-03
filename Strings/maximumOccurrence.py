"""
Problem Statement : https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1#
Time Complexity : O(N)
N is the length of given string
space complexity O(26) --> O(1)
"""
def getMaxOccuringChar(string):
    charList = [0] * 26
    
    #get the counts of character O(N) time
    for ch in string:
        loc = ord(ch.lower()) - ord('a')
        charList[loc] += 1
    
    #get the maximum frquent character from string using O(26) --> O(1)
    maxi = 0
    ans = -1
    for i in range(26):

        if maxi < charList[i]:
            maxi, ans = charList[i], i
    
    #return lowecasse always
    return chr(ans + ord('a'))


import sys
#it wont work with stdin.readline() bcoz readline will appned \n character at end.
text = input()
print(getMaxOccuringChar(text))
"""
CPP Solution : 
class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char toLower(char ch){
        
        if (ch >= 'a' and ch <= 'z')
            return ch;
        
        return ch - 'A' + 'a';
    }
    
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int arr[26] = {0};
        for(ch : str){
            
            int loc = toLower(ch) - 'a'; 
            arr[loc]++;
        }
        
        int maxi = 0;
        int ans = -1;
        for (int i = 0 ; i < 26 ;i++){
            
            if (maxi < arr[i]){
                
                maxi = arr[i];
                ans = i;
            }
        }
        
        
        return ans + 'a';
    }

};
"""