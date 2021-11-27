"""
Problem Statement: Leetcode - reverse integer 
https://leetcode.com/problems/reverse-integer/

""" 


#method-2
def reverse2(integer):
    lower_lmt = - 1 << 31 ; high_lmt = (1 << 31) -1; 

    if integer > 0:
        temp = int(str(integer)[::-1])
    else:
        temp = -1 * int(str(integer * (-1))[::-1])
    
    if temp < lower_lmt or temp > high_lmt:
        return 0

    return temp
    

#method-1
def reverse(integer):
    reverse = 0
    lower_lmt = - 1 << 31 ; high_lmt = (1 << 31) -1; 
    if integer < 0:
        sign = -1
        integer = abs(integer)
    else:
        sign = 1

    #logic
    while integer:
        digit = integer % 10
        integer = integer //10
        if (reverse * sign * 10) < lower_lmt or (reverse * sign * 10) > high_lmt:
            return 0

        reverse = reverse * 10 + digit

    return reverse if sign > 0 else - reverse
    
"""
CPP solution :
class Solution {
public:
    int reverse(int x) {
       int reverse = 0;
       int digit; 
        //logic
        while(x){
            digit = x % 10;
            x = x/10;
            //boundary case - > overflow
            if(reverse > INT_MAX/10 || reverse < INT_MIN/10){
                return 0;
            }
            reverse = reverse * 10 + digit; 
        }
        
        return reverse;
    }
};
Time complexity : O(log(number))
"""
def main():
    integer  = int(input())
    print(reverse2(integer))

if __name__ == "__main__":
    main()