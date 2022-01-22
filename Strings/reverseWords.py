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

"""
follow up: space O(1) in CPP
class Solution {
public:
    bool isSpace(char ch){
        
        if (ch == ' ')
            return true;
        
        return false;
}
    
    string reverseWords(string s) {
    
        int i = 0, r = 0, l = 0;
        int size = s.length();
        
        //reverse the string
        reverse(s.begin(), s.end());
        
        
        //two pointers approach
        while (i < size){
            //fill the words to 
            while (i < size and !isSpace(s[i]))
                s[r++] = s[i++];
            
            //get the space and get the word
            if (l < r){
                
                //reverse the word
                reverse(s.begin() + l, s.begin() + r); // here r pointing to space but it is upperbound in reverse
                
                //append the space after word
                if (r >= size) break;
                 
                //else append space 
                s[r++] = ' ';
                
                //remmeber where next word we have to place (starting index)
                l = r;
            }
           
            //pointing to the next word or next space 
            i++;           
        }
        
        if(s[r-1] == ' ') r--; //skip the space after the last word
        
        s.resize(r);   
        return s;
    }
};


Algorithm:
Reverse whole string.
Again maintain two indices i and j for starting and ending of word, Twist is this time i will not point to 
starting of word but instead to the first leading space, Reason for the same is when we will call reverse 
on i..j, It will brinng word in the front and spaces to the back, In this way we will make all space to the 
trailing ones.
One more thing is we will rev(i,j) when i==0. Reason is in this there might not be a single space, 
For other cases it is clearly mentioned that there will be at least 1 space b/w words.
"""