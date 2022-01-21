#leetcode
class Solution(object):
    def reverseStr(self, s, k):
        """if len(s) <= k:
            return s[::-1]

        count = 0 
        revstring = ""
        original = ""

        for i in s:
            if count < k:
                revstring = i + revstring
                count += 1
            elif count >= k and count < 2 * k:
                revstring += i
                count += 1
            else:
                original = original + revstring
                revstring = i
                count = 1

        return original + revstring
        """

        #time compexity : O(n)
        #space complexity: O(k)
        #much more cleaner using list
        l = list(s)
        
        for i in range(0, len(s), 2 * k):
        
            l[i : i+k] = reversed(l[i : i + k])
        
        return "".join(l)



"""
cpp solution:
#time compexity : O(n)
#space complexity: O(1)
class Solution {
public:
    string reverseStr(string s, int k) {
        
        for(int i = 0; i < s.length(); i += 2*k)
            //reverse elements from i to k
            //in reverse 2nd parameter is upper bound
            reverse(s.begin() + i, s.begin() + i + k > s.end() ? s.end(): s.begin() + i + k); 
        
        return s;
    }
};
"""

        