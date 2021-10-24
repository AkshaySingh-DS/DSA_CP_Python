""" 
Prooblem statement: Find the maximum element in the rotated sorted array 
note: assume that given array must be rotated

time complexity O(log N) time.
because it is already given that data is already sorted but rotated
NOTE: Assuming array is not strictly decreasing order.
"""


""" 
def rotatedMaximum(lis):
    left, right = 0, len(lis)-1
    while left <= right:
        mid = (left + right) //2

        if lis[mid] > lis[mid+1] and lis[mid] > lis[mid-1]: #also check for exact decreasing
            return mid
        if lis[mid]<lis[mid-1] and lis[0]<lis[mid-1]: # also check for exact decreasing
            return mid-1
        elif lis[mid]<lis[mid-1] and lis[0]>lis[mid-1]:
            return 0
        if lis[mid] >= lis[right]:
            left = mid+1
        else:
            right = mid-1 """

def maxRotatedPivot(arr, left, right):
    #base 
    if left < right:

        mid = (left + right)//2

        #location of pivot
        if arr[mid] > arr[mid + 1]:
            return mid 
        if arr[mid-1] > arr[mid]:
            return mid - 1

        #recursive case
        #else search for location
        #pivot location will be at unsorted data side
        if arr[left] > arr[mid]:
            #go to left unsorted part
            return maxRotatedPivot(arr, left, mid - 1)
        else:
            #go to right unsorted part
            return maxRotatedPivot(arr, mid + 1, right)
    
    # this is when the data is sorted but not rotated
    return left



if __name__=="__main__":
    array= [5, 6, 7, 8, 9, 10, 11, 1, 2]
    print(array[maxRotatedPivot(array, 0, len(array)-1)])

#NOTE: Clue is that we have to search for maximum, only where the data is unsorted