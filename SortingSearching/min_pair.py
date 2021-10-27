"""
Problem Statememt:
Find the pair which have the minimum difference in b/w two unsorted arrays.
time complexity :
let size of a1 is M and a2 is N, O(M log M) + O(N * log(M))-> if both are same size then O(N log N)

Bisect Algorithm:- Bisect algorithm is a DC(Devide and Conquer) algorithm similar to binary search
that takes O(log N) in execution

The purpose of Bisect algorithm is to find a position in list where
an element needs to be inserted to keep the list sorted.
NOTE : Three main function in bisect module based on Binary Search requires O(log N) time , hence array must be sorted
check this for more corner cases like if element are same and having same diff from both sides etc.
URL:- https://www.geeksforgeeks.org/bisect-algorithm-functions-in-python/ 
"""

import bisect
def min_Pair(a1, a2):
    a1.sort()
    diff = 10000
    pair = []

    #left index
    for key in a2:
        left = bisect.bisect_left(a1, key)

        #handle cases when diff b/w key and a(left-1) is smaller 
        if left >= 1 and diff > key-a1[left-1]:
            diff, pair = key-a1[left-1], [key, a1[left-1]]

        #handle corner cases when "left will be equal to zero and left will be the index after last". as well as diff b/w a(left) and key is smaller. 
        if left != len(a1) and diff > a1[left]-key:
            diff, pair = a1[left]-key, [a1[left], key]
            print(left, a1[left])

    return pair


#method -2 using two pointer approach
def minPairTwoPointer(a1, a2, n1, n2):
    a1.sort()
    a2.sort()

    smallestDiff = 100000000
    minpair = []

    #logic
    i = 0; j = 0; 
    while i < n1 and j < n2:
        currentDiff = abs(a1[i] - a2[j])
        
        if currentDiff < smallestDiff:
            #update diff and pair
            minpair = [a1[i], a2[j]]
            smallestDiff = currentDiff
        
        #move the pointers to reduce the space -> a1[i] < a2[j] then a1[i] will get the higher diff from all elements of a2[j] so now that is useless
        if a1[i] < a2[j]:
            i += 1
        else:
            j += 1
    
    return minpair


def main():
    a1 = [35, 23, 17, 40]
    a2 = [8, 11, 25, 27, 34, 24,  29, 45]

    print(min_Pair(a1, a2))
    #print(minPairTwoPointer(a1, a2, len(a1), len(a2)))

if __name__ == "__main__":
    main()