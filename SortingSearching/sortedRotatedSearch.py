"""
Roatated Binary Serach iterative solution
Time complexity O(log N)
"""

#clue is that we will check the sorted part where is key is present if not then go to unsorted part 
from math import floor
def rotatedBinarySearch(lis, size, key):
    left, right = 0, size - 1

    #logic of improved binary search
    while left <= right:
        mid = floor((left+right)/2)

        if lis[mid] == key:
            return mid

        #left data is sorted --> arr[l...mid]
        if lis[left] <= lis[mid]:
            #key lies within this range
            if lis[mid] >= key and key >= lis[left]:
                #go to left
                right = mid - 1
            else:
                #got to right
                left = mid + 1
        
        #else data of arr[l...mid] is not sorted hence right part must be sorted
        #key must lies in the nsorted range
        if key >= lis[mid] and key <= lis[right]:
            #go to right
            left = mid + 1
        else:
            #got to left
            right = mid - 1

    return None  

if __name__ == "__main__":
    # sorted rotated array
    lis = [4,5,1,2,3] 
    size = len(lis)
    key_item = int(input())

    searched_result = rotatedBinarySearch(lis, size, key_item)
    print(searched_result) if searched_result != None else print('Data Not Found')