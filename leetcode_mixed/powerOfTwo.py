"""
Problem Statement Leetcode: Power of Two
https://leetcode.com/problems/power-of-two/
"""
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
    number = int(input())
    #print(isPowerOfTwo(number))
    print(isPowerTwoBinarySearch(number))

if __name__ == "__main__":
    main()