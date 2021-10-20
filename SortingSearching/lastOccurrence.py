"""
problem : Find the last occurrence/upperbound of given element 
Time Complexity O(Log N)
NOTE: Clue is that Once we found the key start, then search on right side and store previous found.
"""

import math
def binarySearch(lis, key):
    ans = -1
    left, right = 0, len(lis)-1

    #logic Binary search on answer
    while(left <= right):
        mid = math.floor((left + right)/2)
        if lis[mid] == key:
            ans = mid
            left = mid + 1
        elif lis[mid] < key:
            left = mid + 1
        else:
            right = mid - 1
    
    return ans

def main():
    array = [1,1,2,2,2,2,2,2,2,12]
    Key_item = 2
    search_result = binarySearch(array, Key_item)
    print(search_result) if search_result != -1 else print('Not Found')

    Key_item2 = 10
    search_result2 = binarySearch(array, Key_item2)
    print(search_result2) if search_result2 !=-1 else print('Not Found')


if __name__ == "__main__":
    main()