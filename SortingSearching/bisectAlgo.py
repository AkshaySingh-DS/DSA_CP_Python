""" 
Bisect Algorithm:- Bisect algorithm is a DC(Devide and Conquer) algorithm similar to binary search
that takes O(log N) in execution

The purpose of Bisect algorithm is to find a position in list where
an element needs to be inserted to keep the list sorted.
URL:- https://www.geeksforgeeks.org/bisect-algorithm-functions-in-python/ 

"""

import bisect
def bisectIndex(a, key):
    left = bisect.bisect_left(a, key)
    right = bisect.bisect_right(a, key)
    return left, right 

a = [17 ,13, 35, 40]
# case1 smae key present in array
key = 33
left, right = bisectIndex(a, key)
print('case 1 : ', left, right)

#case2 have same distance from both sides
key = 14
left, right = bisectIndex(a, key)
print('case 2 : ', left, right)

#case3 general case
key = 25
left, right = bisectIndex(a, key)
print('case 3 : ', left, right)

#case4 key need to be placed at start
key = 3
left, right = bisectIndex(a, key)
print('case 4 : ', left, right)

#case5 key need to be placed at end(Crucial)
key = 49
left, right = bisectIndex(a, key)
print('case 4 : ', left, right)