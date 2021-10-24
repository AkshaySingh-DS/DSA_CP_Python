"""
Problem Statement: Find the key in the array which is sorted but might be rotated.
Time complexity -> O(log N)
"""

#method - 1 using Pivot Approch (the point where data is not sorted)
#worst/average case when data is not found o(log N)
#best case when data itself in first middle O(1)
#space O(1) excluding recursive calls
#The clue is that from pivot the data value from left side and the right side always be sorted and we can easily apply binary search
import binarySearch
def findPivot(arr, low, high):
    #no such pivot exist bcoz data is not rotated but sorted
    if low <= high:
        mid = (low + high)//2

        #found the pivot in these cases
        if arr[mid] > arr[mid+1] : 
            return mid
        if arr[mid-1] > arr[mid] :
            return mid-1

        #pivot would be reside @ left part when left part won't be sorted
        if arr[low] >= arr[mid]:
            return findPivot(arr, low, mid - 1)

        #else pivot will reside @ right part
        return findPivot(arr, mid + 1, high)
    
    #that is the idication when data values are not rotated
    return -1

def pivotedBinarySearch(arr, s, e , key):
    # get pivot
    pivot = findPivot(arr, s, e)

    #hence data is not raoted
    if pivot == -1:
        #normal binary serach that will also take care of if key not found
        return binarySearch.BinarySearch(arr, s, e, key)

    if arr[pivot] == key:
        return pivot


    #Hence data is lying between start and pivot
    if key >= arr[s]:
        return binarySearch.BinarySearch(arr, s, pivot-1, key)

    #else 
    return binarySearch.BinarySearch(arr, pivot+1, e, key)

#method - 2 using single pass recursive imporved binary search 
#O(log n)
def rotatedBinarySearch(arr, s, e , key):
    if s > e:
        return -1

    mid = (s+e)//2
    if key == arr[mid]:
        return mid

    #if left part is sorted
    if arr[mid] >= arr[s]:
        #Does key lies within range of left 
        if key >= arr[s] and key <= arr[mid]:
            return rotatedBinarySearch(arr, s, mid-1, key)

        #else it would be on right
        return rotatedBinarySearch(arr, mid+1, e, key)


    #If arr[l..mid] is not sorted, then arr[mid... r] must be sorted
    #if key lies within this range
    if arr[mid] <= key and key <= arr[e]:
        return rotatedBinarySearch(arr, mid+1, e, key)

    #else data will be in left side if not in right side --> which is unsorted part
    return rotatedBinarySearch(arr, s, mid-1, key)

if __name__ == "__main__":
    #arr = [8, 9, 10 , 11 ,1 ,2 , 3 ,5 ,6,7]
    #arr = [1, 2, 5, 6, 8 ,9 ,11, 16, 19, 25]
    # arr = [5, 6, 8, 9, 11, 16, 19, 25, 1, 2]
    arr = [4,5,1,2,3] 
    key = int(input())
    ans = pivotedBinarySearch(arr, 0, len(arr)-1, key)
    if ans != -1:
        print(ans)
    else:
        print(f'ITEM {key} NOT FOUND')
    """ans = rotatedBinarySearch(arr, 0, len(arr)-1, key)
    if ans != -1:
        print(ans)
    else:
        print(f'ITEM {key} NOT FOUND')"""