"""
Problem Statement : Leetcode
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
"""

#CONTRAINTS: O(1) spaces
# TIME COMPLEXITY : O(N) -> number of elements 

import sys
def removeDuplicates(values):
    #two pointer approach unique -> current_unique position, current -> cuurent_elemet for investigate
    unique = 0 ; current = 1
    size = len(values)

    #boundary cases
    if size == 0 or size == 1:
        return size 

    while current < size:

        if values[unique] != values[current]:
            unique += 1
            values[unique] = values[current]
        
        #bypass the duplicates
        current += 1
    
    #unique reprsent the current_unique index so we want no of elements
    return unique + 1


def main():
    values = list(map(int, sys.stdin.readline().rstrip().split()))
    k = removeDuplicates(values)
    for i in range(k):
        print(values[i], end = " ")

if __name__ == "__main__":
    main()

"""
CPP SOLUTION :
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int unique = 0, current = 1;
        if(size == 1 || size == 0){
            return size;
        } 
        
        while (current < size){
            
            if(nums[unique] != nums[current]){
                
                nums[++unique] = nums[current];
            
            }   
            
            current ++;
        }
       
        return unique + 1;
    }
};
"""