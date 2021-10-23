def lowerBoundkey(arr, key, n):
    #code
    start, end = 0, n-1
    leftidx_ans = -1
    while start <= end:
        mid = (start+end)//2
        if arr[mid] == key:
            end = mid-1
            leftidx_ans = mid
        elif arr[mid] < key:
            start = mid+1
        else:
            end = mid-1
    
    return leftidx_ans


def upperBoundkey(arr, key, n):
    #code
    start, end = 0, n-1
    rightidx_ans = -1
    while start <= end:
        mid = (start+end)//2 
        if arr[mid] == key:
            start = mid + 1
            rightidx_ans = mid
        elif arr[mid] > key:
            end = mid - 1
        else:
            start = mid + 1

    return rightidx_ans

def countFrequency(arr, key, n):
    left = lowerBoundkey(arr, key, n)
    right = upperBoundkey(arr, key, n)

    #key not found
    if left == -1 or right == -1:
        return 0

    return right - left + 1

def main():
    arr = [0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 5, 5, 5, 10]
    key = int(input())
    size = len(arr)
    print(countFrequency(arr, key, size))
    
    #using list method in python
    print(arr.count(key))

#try to accomplish it using recursion.

if __name__ == "__main__":
    main()