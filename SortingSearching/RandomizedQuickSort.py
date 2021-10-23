import random
def partition(arr, p, r):
    i, j = p-1, p
    pivot = r
    while j <= r-1:
        if arr[j] <= arr[pivot]:
            i += 1
            arr[i], arr[j] = arr[j], arr[i] # swap(arr[i], arr[j])
        j += 1
    arr[i+1], arr[pivot] = arr[pivot], arr[i+1] # swap(arr[i+1], arr[pivot])
    return i+1 # location of pivot

 
def quickSort(arr, p, r):

    # base case
    if p >= r: # only single element left
        return

    # recursive case
    pivot = partition(arr, p, r)
    quickSort(arr, p, pivot-1)
    quickSort(arr, pivot+1, r)


def fastQuickSort(arr, start, end):
    #idea is to SWAP pivot element to some random array element 
    #random = arr.index(choice(arr))
    r = random.randrange(start, end)

    #swap pivot with random index(end of the index is the pivot element)
    arr[r], arr[end] = arr[end], arr[r]
    quickSort(arr, start, end)

#time complexity in amortized analysis found O(N log N)
def main():
    arr = [1, 2, 3, 8, 5, 6, 7]
    print(f'Before Sorting: {arr}')
    fastQuickSort(arr, 0, len(arr)-1)
    print(f'After Sorting: {arr}')

if __name__ =="__main__":
    main()