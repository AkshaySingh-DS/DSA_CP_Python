"""
Problem Statetement:
find the number of inversion in an unsorted array:
Inversion -> a[i] > a[j] such that i < j
"""

#Time complexity O(n logn) -> mergesort
#method-2 -> using the brute force with two loops by finding the number of inversion pair.
def merge(arr, s, mid, e):
    temp = []
    i, j = s, mid+1

    inv_count = 0
    while i <= mid and j <= e:

        # count inversion case
        if arr[i] > arr[j]:
            #mid - i + 1 number of possible inversion
            inv_count += mid - i + 1
            temp.append(arr[j])
            j += 1
        else:
            temp.append(arr[i])
            i += 1

    #either
    while i <= mid:
        temp.append(arr[i])
        i += 1
   
    #Or
    while j <= e:
        temp.append(arr[j])
        j += 1

    #copy the entire temp array in original array
    k = 0
    for i in range(s, e+1):
        arr[i] = temp[k]
        k += 1

    return inv_count

def mergeSort(arr, s, e):
    #base case
    if s >= e:
        return 0

    #recursion case only when more than one element
    mid = (s+e)//2  # overflow in other langauge -> l + (r-l) // 2
    l = mergeSort(arr, s, mid)
    r = mergeSort(arr, mid+1, e)
    CI = merge(arr, s, mid, e)
    return l + r + CI

#time complexity O(log n) space O(N)
def main():
    arr = [0, 5 ,2 ,3 ,1]
    #arr = [8, 3, 0, 1, 5 ,2]
    # arr = [4, 9, -1, 3, 2]
    # arr = [1, 2, 3, 5, 6]
    print(mergeSort(arr, 0, len(arr)-1))

if __name__ == "__main__":
    main()