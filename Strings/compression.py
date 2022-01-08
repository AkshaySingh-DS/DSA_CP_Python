"""
Problem Statement: https://leetcode.com/problems/string-compression/submissions/ 

Time Complexity : O(N)
Space Complexity : O(1)
"""

class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        arrIndx, cnt = 0, 0
        length = len(chars)
        i = 0
        
        while i < length:
            
            j = i + 1
            #skip the characters if they match
            while (j < length) and (chars[i] == chars[j]):
                j += 1
                
            #add character
            chars[arrIndx] = chars[i]
            arrIndx += 1
            
            #get matched length
            cnt = j - i
            
            if cnt > 1:
                #if cnt >= 10, and one character at a time in list
                for ch in str(cnt):
                    chars[arrIndx] = ch
                    arrIndx += 1
            i = j

        return arrIndx

"""
CPP SOLUTION:
class Solution {
public:
    int compress(vector<char>& chars) {
        
        int size = chars.size();
        int i = 0, j;
        int cnt = 0, indx = 0;
        
        while (i < size){
            
            j = i + 1;
            
            while (j < size and chars[i] == chars[j])
                j++;
            
            chars[indx++] = chars[i];
            
            cnt = j - i;
            
            if (cnt > 1) {
                
                string digits = to_string(cnt);
                
                for (auto ch : digits) 
                    chars[indx++] = ch;
            }
            
            i = j;
        }
        
        return indx;
    }
};
"""
 