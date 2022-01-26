"""
Problem Statement: https://leetcode.com/problems/reverse-vowels-of-a-string/submissions/

Complexity : O(n), O(1) space 
Howevrer, in case of python due to string immutable O(n) space
""" 

def reverseVowels(s):
    vowels = set("aeiouAEIOU")
    strings = ""
    rptr=len(s)-1
    for lptr in range(len(s)):
        if s[lptr] not in vowels:
            strings = strings + s[lptr]
        else:
            for r in range(rptr,-1,-1):
                if s[r] in vowels:
                    rptr = r-1
                    strings = strings + s[r]
                    break

 
    return strings

#above code in python is not optimized one we can easily optime this like below cpp

"""
CPP Solution:
class Solution {
private:
    bool isVowel(char ch){
        
        if (ch == 'a' or ch == 'A' or ch == 'e' or ch == 'E' or ch == 'i' or ch == 'I' or ch == 'o' or ch == 'O' or ch == 'u' or ch == 'U')
            return true;
        
        return false;
    }
public:
    string reverseVowels(string s) {
        
        int left = 0, right = s.length()-1;
        
        while (left < right){
            
            //one of them are not voewels 
            if(!isVowel(s[left]))
                left++;
            
            if(!isVowel(s[right]))
                right--;
            
            //when both are vowels
            if(isVowel(s[left]) and isVowel(s[right]))   
                swap(s[left++], s[right--]);  
        }  
        
        return s;     
    }
}; 
"""