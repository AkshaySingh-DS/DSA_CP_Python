def insertionSort(arr, n):
    for i in range(1, n):
        temp, j = arr[i], i-1 # j's not vanished while shifting

        while temp < arr[j] and j >= 0:
            arr[j+1] = arr[j] # shifting
            j -= 1

        arr[j+1] = temp


def insertionSort2(arr):
    for i in range(1, len(arr)):
        temp, j  = arr[i], i-1
        for j in range(i-1, -2, -1):
            if arr[j] > temp:
                arr[j+1]  = arr[j]
            else:
                break
        arr[j+1] = temp
# just do shifting in case of insertion sort
# Worst case O(N^2) when data already sorted in descending order and best case O(N) time when data is sorted in ascending

if __name__ == "__main__":
    lis = [2, 1, 3, 4, 5, 6, 7, 9, -10, 8, 11, 12, 13, -14, 15, 10, 18, 19]
    print('Before Sorting', lis) # pass by reference
    #insertionSort(lis)
    insertionSort(lis, len(lis))
    print('After Sorting', lis)