"""
Problem Statement : 
https://leetcode.com/problems/reverse-words-in-a-string/

Time complexity O(n) space is also O(n) since [::-1] and split will create extra copy
[::-1] is slightly faster than reversed
"""

def reverseWords(s):
      return ' '.join(s.split()[::-1])

text = input()
reverseWords(text)
"""
CPP Solution
class Solution {
public:
    bool isSpace(char ch){
        
        if (ch == ' ')
            return true;
        
        return false;
}
    
    string reverseWords(string s) {
        
        string word = "";
        string ans = "";
        
        int i = 0;
        while(true){
            
            //skip spaces
            while(isSpace(s[i]) and i < s.length())
                i++;
            
            //help to handle boundary case loke "  hello world   "
            if (i >= s.length()){
                break;
            }
            
            //get word
            while (!isSpace(s[i]) and i < s.size())
                word.push_back(s[i++]);
            
            
            //reverse word , then append word to ans 
            reverse(word.begin(), word.end());
            ans += word + " ";
            word.clear();
              
    }
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;     
    }
};
"""