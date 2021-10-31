"""
Problem Statement: We have given k strings a1, a2, a3 ... , ak our task is to find out the lexicographically smallest concatination all of these strings 
"""

"""
NOTE - i)
time complexity O(N log N * M)where M is maximum string length and N number of string in list
to make key argument as 2 object argument we have to import the the cmp_to_key function from functools
However key only takes one argument
"""

"""

NOTE - ii)
perfect example 
[0, 10, 11, 12, 13, 17, 19]
l.sort(key = cmp_to_key(lambda a, b: 1 if a>b else -1)) # if a > b then b is smallest and first put this in an array
apply merge sort and merge fuction worked base on the above compare logic
"""


#code
#method-1 Brute force : backtracing method using permutation, time -> O(N! * M)
from functools import cmp_to_key, reduce
def permute(arr, l, r, smallestContString):
    #base
    if l == r:
        return min(''.join(arr), smallestContString)
        
    #recursive case
    for i in range(l, r + 1):
        #swap
        arr[i] , arr[l] = arr[l], arr[i]

        #permutation
        smallestContString = permute(arr, l + 1, r, smallestContString)

        #swap -> backtracking
        arr[i] , arr[l] = arr[l], arr[i]
    
    return smallestContString 

def lexicogSmallestStringConcatination(arr, size):
    lenConctString = len(reduce(lambda k1, k2: k1 + k2, arr ))
    smallestContString = 'z' * lenConctString
    return permute(arr, 0, size-1, smallestContString)



def smallestString(arr):
    #custom compare comparision that will return 1 if after concatination s1 + s2 < s2 + s1 then in merge sort it will take s1 else s2  
    arr.sort(key = cmp_to_key(lambda s1, s2: 1 if s1 + s2 > s2 + s1 else -1)) # cmp_to_key(compare)

def main():
    arr = ['a', 'ab', 'aba'] #sorting all the keys lexicographically and concatination won't work
    print(''.join(arr))
    print('Method-1:')
    smallestString(arr)
    print(''.join(arr))
    print('Method-2:')
    arr = ['a', 'ab', 'aba'] 
    print(lexicogSmallestStringConcatination(arr, len(arr)))

if __name__== "__main__":
    main()