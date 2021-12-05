"""
Problem Statement : Leetcode
https://leetcode.com/problems/unique-number-of-occurrences/
"""

#TIME COMPLEXITY : O(N)
#SPACE COMPLEXITY : O(N)
from sys import stdin

#using collections module
from collections import Counter

def isUniqueOccurrence2(nums):
    #will give dictionary, each element of list as key with its frequecy
    freMap = Counter(nums)

    #number of values
    c = len(freMap.values())

    #find how many unique freq_count
    k = len(set(freMap.values()))

    if c == k:
        return True
    
    return False

    #one liner python beauty
    return ((len(set(Counter(nums).values()))) == (len(Counter(nums).values())))


#using normal method without using module
def isUniqueOccurrences(nums):
    freqMap = {}

    #count the frequency of elements
    for val in nums:

        if freqMap.get(val):
            freqMap[val] += 1
        else:
            freqMap[val] = 1
    
    
    #make the frequency count as key if freqCount will repeat then false else 
    #after array exausted all occurrences will be distict
    hasMap = {}
    for val in freqMap.values():
        if hasMap.get(val):
            return False
        
        hasMap[val] = True
    
    return True
        
def main():
    nums = map(int, stdin.readline().strip().split())
    #print(isUniqueOccurrences(nums))

    print(isUniqueOccurrence2(nums))


if __name__ == "__main__":
    main()