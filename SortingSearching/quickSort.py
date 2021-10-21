def partition(arr, p, r):
    i, j = p-1, p
    pivot = r
    while j <= r-1:
        if arr[j] <= arr[pivot]:
            i += 1
            arr[i], arr[j] = arr[j], arr[i] # swap(arr[i], arr[j])
        j += 1
    i += 1
    arr[i], arr[pivot] = arr[pivot], arr[i] # swap(arr[i+1], arr[pivot])
    return i # location of pivot


def quickSort(arr, p, r):
    # base case
    if p >= r: # only single element left
        return

    # recursive case
    pivot = partition(arr, p, r)
    quickSort(arr, p, pivot-1)
    quickSort(arr, pivot+1, r)

# Time complexity --> O(N log N) and space O(1) (best case)
# Time complexity --> O(N^2) i.e when data is already sorted either in reverse order or vice versa
def main():
    #arr = [2, 8, 7, 1, 3, 5, 6, 4]
    arr = [10, 9, 8, 7 , 6, 5 , 4 , 3, 2, 1]
    print(f'Before Sorting {arr}')
    quickSort(arr, 0, len(arr)-1)
    print(f'After Sorting {arr}')

if __name__ =="__main__":
    main()