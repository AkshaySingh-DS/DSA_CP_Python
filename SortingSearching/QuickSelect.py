"""
Problem : calculate the kth smallest element of the array
Assuming that k < size of array i.e. kth smallest element exist. 
"""


#Time complexity -> O(N^2) in worst case and O(N) in best/average case
#Note - 2nd way to sort using sorting and then select the kth one.(N^2) worst case and O(N logN)-> best/Avg case

def partition(arr, p, r):
    i= p-1
    pivot = r
    for j in range(p, r):
        if arr[j] <= arr[pivot]:
            i += 1
            arr[i], arr[j] = arr[j], arr[i] # swap(arr[i], arr[j])
    i += 1
    arr[i], arr[pivot] = arr[pivot], arr[i] # swap(arr[i+1], arr[pivot])
    return i # location of pivot


"""
Modification in the actual quick_sort:
Idea is to compare the kth smallest with pivot 
"""
def quickSelect(arr, p, r, k):
    #base case not needed because we'r assuming that that element exist

    #recursive
    pivot = partition(arr, p, r)
    if pivot == k:
        return arr[pivot]

    elif pivot < k:
        #kth smallest element can't be poosible in left of pivot, since all the elements left from pivot are less than pivot 
        #looking for right of pivot
        return quickSelect(arr, pivot+1, r, k)
    else:
        #looking for left
        return quickSelect(arr, p, pivot-1, k)

def main():
    arr = [10, 5, 2 ,0, 7, 6, 4]
    k = 3
    print(quickSelect(arr, 0, len(arr)-1, k-1))

if __name__=="__main__":
    main()