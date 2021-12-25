"""
problem statement : https://leetcode.com/problems/move-zeroes/
Time complexity O(N)
"""
import sys
def moveZeroes(nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        nonZero, i = 0, 0
        while i < len(nums):
            
            if nums[i] != 0:
                #swap elements
                nums[i], nums[nonZero] = nums[nonZero], nums[i]
                nonZero += 1
            
            i += 1

def main():
    arr = list(map(int , sys.stdin.readline().split()))
    moveZeroes(arr)
    print(arr)

main()

"""
CPP solution: 7 times faster than python
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        //location of non zero element
        int nonZero = 0;
        
        for(int i = 0; i < nums.size(); i++){
            
            if (nums[i] != 0)   
                swap(nums[i], nums[nonZero++]);
            
        }
    }
};
"""