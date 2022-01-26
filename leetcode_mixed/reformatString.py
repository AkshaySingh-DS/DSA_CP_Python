"""
Problem Statement : https://leetcode.com/problems/reformat-the-string/
Time Complexity : O(n)
Space Comlpexity : O(n)

"""

def reformat(s):
    digits = [ch for ch in s if ch.isdigit()]
    letters = [ch for ch in s if ch.isalpha()]
        
    len_digits = len(digits)
    len_letters = len(letters)
    ans = ""
        
    #boundary cases where not possible such permutation     
    if abs(len_digits - len_letters) > 1:
        return ""
        
    #swap the letters and digits
    if len_digits > len_letters:
        digits, letters = letters, digits
            
    while letters:
        ans += letters.pop()
        if digits:
            ans += digits.pop()
        
    return ans



"""
CPP Solution : 
class Solution {
public:
    string reformat(string s) {
        
        string digits;
        string letters;
        for(auto ch : s){
            
            if (isdigit(ch))
                digits.push_back(ch);
            else
                letters.push_back(ch);
        }
        
        //making digits bigger than letters
        if (letters.length() > digits.length())
            swap(digits, letters);
        
        
        string ans;        
        if (digits.length() - letters.length() > 1)
            return ans;
    
        int i = 0;
        while(i < digits.length()){
            
            ans.push_back(digits[i]);
            if (i < letters.length())
                ans.push_back(letters[i]);
            
            i++;   
        }
        
        return ans;
    }
};
"""