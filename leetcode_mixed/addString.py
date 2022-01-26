"""
Problem Statement : https://leetcode.com/problems/add-strings/
Time Complexity : O(log(max(N, M)))
"""

def addStrings(num1, num2):
    # return str(int(num1) + int(num2))
    cy = 0
    ans = ""
    r1 = len(num1) - 1
    r2 = len(num2) - 1 

    while r1 >= 0 or r2 >= 0 or cy:

        d1 = ord(num1[r1]) - ord('0') if r1 >= 0 else 0
        d2 = ord(num2[r2]) - ord('0') if r2 >= 0 else 0

        val = (d1 + d2 + cy) % 10
        cy =  (d1 + d2 + cy) // 10

        ans  = chr(val + ord('0')) + ans

        r1 -= 1
        r2 -= 1

    return ans    

if __name__ == "__main__":
    print(addStrings('8765', '2368'))

"""
CPP Solution : 
class Solution {
public:
    string addStrings(string num1, string num2) {
        int r1 = num1.length()-1, r2 = num2.length() -1;
        int carry = 0;
        string ans;
        
        while (r1 >= 0 or r2 >= 0 or carry){
            
            int d1 =  r1 >= 0 ? num1[r1] - '0' : 0 ;
            int d2 =  r2 >= 0 ? num2[r2] - '0' : 0 ;
            
            int val = (d1 + d2 + carry) % 10 ;
            carry = (d1 + d2 + carry)/10;
            
            //ans =  to_string(val) + ans;  

            ans.push_back(char(val + '0'));
            r1--;
            r2--;
        }
        reverse(ans.begin(),  ans.end());
        return ans;
             
    }
};

"""