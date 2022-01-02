"""
Problem statement: 
https://leetcode.com/problems/valid-palindrome/
space complexity : O(1) using two pointers approach
"""


class Solution(object):
    
    def toLower(self, ch):
        if (ch >= 'a' and ch <= 'z') or (ch >= '0' and ch <= '9'):
            return ch

        return ch.lower()
    
    def isPalindrome(self, s):
        start = 0; end = len(s) - 1

        while start < end:
            #check the number is alphanumeric 
            if s[start].isalnum() and s[end].isalnum():
                if self.toLower(s[start]) != self.toLower(s[end]):
                    return False

                start += 1
                end -= 1
                
            #skip the steps for non-alphanumeric i.e. special characters
            else:
                if not s[start].isalnum() :
                    start += 1 

                if not s[end].isalnum():
                    end -= 1  

        return True

"""
CPP Solution:
 bool isValid(char ch){
    
    if((ch >= 'a' and ch <= 'z') || (ch >= 'A' and ch <= 'Z') || (ch >= '0' and ch <= '9'))
        return true;
   
    return false;
}

char toLower(char ch){
    //it handles the intger also
    if((ch >= 'a' and ch <= 'z') || (ch >= '0' and ch <= '9'))
        return ch;
        
    return ch - 'A' + 'a';
}


bool checkPalindrome(string s)
{
    // Write your code here.
   	int start = 0, end = s.length() - 1;

    while (start < end){
        if(isValid(s[start]) and isValid(s[end])){
            
            if(toLower(s[start++]) != toLower(s[end--]))
               return false;             
        }
           
        else{
            
            if(!isValid(s[start]))
                start++;
            
            if (!isValid(s[end]))
                end--;
        }
    }
    return true;
}
"""