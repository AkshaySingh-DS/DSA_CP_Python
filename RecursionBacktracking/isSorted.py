def isSorted(lis):
    for i in range(1, len(lis)):
        if lis[i] < lis[i-1]:
            return 0
    else:
        return 1

# implement using recursion
def IsSorted(arr, size, i):
    if i == size:
        return True
    elif arr[i-1] > arr[i]:
        return False
    else:
        return IsSorted(arr, size, i+1)

# NOTE
# Time complexity O(N) for both method but space complexity get's increased due to recursive call in stack_Queue

if __name__ == "__main__":
    lis = [-1, -5, 6, 12, 15, 20]
    lis2 = [-1, 5, 6, 12, 15, 20]
    print('Without - Recursion')
    print ('Sorted Array') if isSorted(lis) else print("Not Sorted array")
    print('Sorted Array') if isSorted(lis2) else print("Not Sorted array")
    print('--' * 20)
    print('With - Recursion')
    print('Sorted Array') if IsSorted(lis, len(lis), 1) else print("Not Sorted array")
    print('Sorted Array') if IsSorted(lis2, len(lis2), 1) else print("Not Sorted array")
