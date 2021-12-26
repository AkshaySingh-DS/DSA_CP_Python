"""
Problem Statement : https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
time complexity : O(N)
space complexity : O(1) not using any extra space
"""
def isSortedRotated(nums):
    i = 1; size = len(nums) 
    pair = 0
    while i <= size:
        if nums[i-1] > nums[i % size]:
            pair += 1
        i += 1
                 
    #pair -> 0 when all value will be same (Boundary case)
    #else for sorted and rotated pair = 1 for not (sorted/rotated) pair > 1 
    return pair <= 1

def main():
    l = list(map(int, input().split()))
    print(isSortedRotated(l))
    
if __name__ == "__main__":
    main()

"""
CPP Solution : 
class Solution {
public:
    bool check(vector<int>& nums) {
        
        int size = nums.size();
        int cnt = 0;
        
        for(int i = 1; i <= size; i++){
            
            if(nums[i-1] > nums[i % size]){
                
                cnt++;
            }
        }
        
        return cnt <= 1;
    }
};
"""
