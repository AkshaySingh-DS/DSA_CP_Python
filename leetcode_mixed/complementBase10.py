"""
Problem Statement Leetcode : Complement of Base 10 Integer
https://leetcode.com/problems/complement-of-base-10-integer/
"""


class Solution:

    #method-1 (Approach) => get the binary representation then -> complement it -> then convert it into decimal
    # Eventually => decimal to binary -> then complement -> binary to decimal  
    #get the decimal equivalant
    def getDecimal(self, temp):
        decimal = 0
        i = 0 
        for ch in temp:
            if int(ch) == 1:
                #1<<2 -> 2^2 and 1<<0 -> 2^0
                decimal = decimal + (1 << i) 
            
            i += 1
        
        return decimal
    #get the complement
    def bitwiseComplement1(self, num):

        #bin(11) -> '0b1011'
        temp = bin(num)[2:]
        complement = ''

        for i in temp:
            if int(i) & 1:
                complement += '0'
            else:
                complement += '1'

        #get decimal equivalant
        return self.getDecimal(complement[::-1])

    #method - 2 (Approach) =>   idea is just to create the mask number then do the anding with given numbers complement 
    def bitwiseComplement2(self, num):
        #boundary case when num => 0
        if num == 0:
            return 1

        #1's complement -> log(number)
        complement = ~num

        #create mask-bits -> log(number) when number is 0 then this loo will not work
        mask = 0
        while num:
            num = num >> 1
            mask = (mask << 1) | 1 
        
        #get the required complement
        return mask & complement


"""
CPP Solution:
class Solution {
public:
    int bitwiseComplement(int n) {
        int mask = 0;
        int temp = n;

        //boundary case
        if (n == 0){
            return 1;
        }

        //logic create mask-bits
        while (temp){
            temp >>= 1;
            mask = mask << 1 | 1;
        }

        return (~n) & mask;
    }
};
Time complexity: O(log(number))
"""

def main():
    num = int(input())
    sl = Solution()
    print(sl.bitwiseComplement2(num))

if __name__ == "__main__":
    main()