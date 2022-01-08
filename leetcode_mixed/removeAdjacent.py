"""
Problem Statement: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

Time complexity : O(N), n length of given string
Space Complexity : O(N) using stack
"""

class Solution(object):
    def removeDuplicates(self, s):
        stack = []
        for ch in s:
            if len(stack) == 0:
                stack.append(ch)
            elif ch == stack[-1]:
                stack.pop()
            else:
                stack.append(ch)
                
        ans = ""
        return ''.join(stack)

"""
CPP SOLUTION:
APPROACH-1
class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> st;

        for (char ch : s){
            if (st.empty()) st.push(ch);
            else if (ch == st.top()) st.pop();  
            else st.push(ch);
        }
        
        string ans = "";
        while (!st.empty()){
            char val = st.top();
            st.pop();
            ans += val;
        }   
       
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
APPROACH-2
class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";

        for (char ch : s){
            if (ans.empty()) ans.push_back(ch);
            else if (ch == ans.back()) ans.pop_back();  
            else ans.push_back(ch);
        }
        
        return ans;
    }
};
"""