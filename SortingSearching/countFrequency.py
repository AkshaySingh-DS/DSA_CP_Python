def binarySearch(arr, key, size):
    #code 
    left = 0; right = size - 1
    while left <= right:
        mid = (left  + right) // 2 
        if arr[mid] == key:
            return mid

        elif arr[mid] < key:
            left = mid + 1
        
        else:
            right = mid - 1
    
    #key not found
    return -1

def countFrequency(arr, key, n):
    idx = binarySearch(arr, key, n)

    if idx == -1:
        return 0

    #else
    left_ans = idx; right_ans = idx
    left = 0; right = idx - 1
    #looking for left
    while left <= right:
        mid  = (left + right)//2

        if arr[mid] == key:
            left_ans = mid
            right = mid - 1
        else:
            left = mid + 1

    #looking for right 
    left = idx + 1; right = n-1
    while left <= right:
        mid = (left + right)//2

        if arr[mid] == key:
            right_ans = mid
            left = mid + 1
        else:
            right = mid - 1

    return right_ans - left_ans + 1

# time complexity O(log N)
def main():
    arr = [0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 5, 5, 5, 10]
    key = int(input())
    size = len(arr)
    print(countFrequency(arr, key, size))
    
    #using list method in python
    #count method of python takes O(n) time.
    print(arr.count(key))

#try to accomplish it using recursion.

if __name__ == "__main__":
    main()