def partition(arr , p, r):
    i = p-1 ; j = p
    pivot = r
    while j <= r-1:
        if arr[j] <= arr[pivot]:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
        j += 1
    
    i += 1
    arr[i], arr[pivot] = arr[pivot], arr[i]
    return i
    

def quickSelect(arr, p, r, k, size):
    #No base case required assuming we have the element
    #recursive case
    pivot = partition(arr, p, r)
    if pivot == size - k:
        return arr[pivot]
    
    elif  pivot > size - k:
        #looking for left 
        return quickSelect(arr, p, pivot-1, k, size)
    else:
        #looking for right
        return quickSelect(arr, pivot + 1, r, k, size)


def main():
    arr = [1, 5, 3, 0, 7, 4, 10, 2, 8]
    k = 2 ; size = len(arr)
    print(quickSelect(arr, 0, size - 1, k, size))

if __name__ == "__main__":
    main()
