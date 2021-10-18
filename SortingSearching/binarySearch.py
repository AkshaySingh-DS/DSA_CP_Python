# Time complexity O(Log N)
import math
#iterative approach
def binarySearch(lis, s , e, key):
    left, right = s, e

    while(left <= right):
        #overflow in other langauge -> (left + right)//2 also works for floor division
        mid = math.floor((left+ right)/2)
        #to avoid overflow in binary search calculate mid -> mid = left + (right-left)//2

        if lis[mid] == key:
            return mid
        elif lis[mid]<key:
            left=mid+1
        else:
            right=mid-1

    return -1

#recursive approach
def BinarySearch(arr, s, e , key):
    if s > e:
        return -1
    mid_idx = (s + e)//2 # this cause overflow in other language-> l+ (r-l) //2
    if arr[mid_idx] == key:
        return mid_idx
    elif arr[mid_idx] > key:
        return BinarySearch(arr, s, mid_idx-1, key)
    else:
        return BinarySearch(arr, mid_idx+1, e, key)



if __name__=="__main__":
    arr = [1, 2, 5, 6, 8 ,9 ,11, 16, 19, 25]
    key = int(input())
    res = binarySearch(arr, 0, len(arr)-1, key)
    #res = BinarySearch(arr, 0, len(arr)-1, key)
    if res != -1:
        print(res)
    else:
        print('Not Found')