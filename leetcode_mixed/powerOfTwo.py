"""
Problem Statement Leetcode: Power of Two
https://leetcode.com/problems/power-of-two/
"""
import sys
def isPowerOfTwo(number):
    temp = 1

    #logic
    while temp <= number:
        if temp == number:
            return True
        
        temp <<= 1

    return False

#binary search
def isPowerTwoBinarySearch(number):
    #search space -> will create overflow issue -2^31 <= n <= 2^31 - 1 maximum power of 2 would be  2^30
    left = 0; right = 30

    #logic
    while left <= right:

        mid = (left + right)//2
        temp = 2 ** mid
        if temp == number:
            return True
        
        elif temp < number:
            left = mid + 1

        else:
            right = mid - 1

    return False


#time coplexity O(log(number))
def isPowerOfTwo3(number):
    
    setBitCnt = 0

    while number:
        
        #get bit either 0 or 1
        setBit = number & 1

        #add this
        setBitCnt += setBit

        #if greater than power than power 2 wont be possible
        if setBitCnt > 1:
            return False

        number = number >> 1
    
    #else
    return True
 

""" 
CPP Problem:
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int temp = 1;
        
        //logic
        //while (temp <= n) will create overflow issue -2^31 <= n <= 2^31 - 1
        for(int i = 0; i < 31; i++) {
            if (temp == n){
                return true;
            }
            
         temp <<= 1;   
        }
        
        return false;
    }
};

Time complexity: O(log(number))
"""
def main():
    number = int(sys.stdin.readline().rstrip())
    #print(isPowerOfTwo(number))
    #print(isPowerTwoBinarySearch(number))
    print(isPowerOfTwo3(number))


if __name__ == "__main__":
    main()