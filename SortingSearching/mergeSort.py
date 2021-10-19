#time complexity for merge procedure- > O(N)
def merge(arr, s, mid, e):
    i, j = s, mid + 1
    temp = []

    #sorting code
    while j <= e and i <= mid:
        if arr[i] < arr[j]:
            temp.append(arr[i])
            i += 1
        else:
            temp.append(arr[j])
            j += 1

    #copy the remaining elements left
    while j <= e:
        temp.append(arr[j])
        j += 1
    while i <= mid:
        temp.append(arr[i])
        i += 1

    # copy all the element in right place
    k = 0
    for i in range(s, e+1):
        arr[i] = temp[k]
        k += 1

#time complexity for mergeSort -> O(N log N)
def mergeSort(arr, s, e):
    if s < e:
        mid = (s+e)//2
        mergeSort(arr, s, mid)
        mergeSort(arr, mid+1, e)
        merge(arr, s, mid, e)

#time complexity thetha(N Log N) for any cases, Hence this algorithm not as
#much smart as Randomized QuickSort
if __name__ == "__main__":
    arr = [2, 8, 7, 1, 3, 5, 6, 4, 11 , 9]
    print(f"Before Sorting {arr}")
    mergeSort(arr, 0, len(arr)-1)
    print(f"After Sorting {arr}")