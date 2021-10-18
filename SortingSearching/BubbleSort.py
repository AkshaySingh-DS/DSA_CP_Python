# Time complexity O(N^2)
def bubbleSort(arr):
    for round in range(1,len(arr)):
        for i in range(len(arr)-round):
            if arr[i] > arr[i+1]:
                arr[i],arr[i+1] = arr[i+1], arr[i] # Swap
    return round

# Time complexity O(N) when data is already sorted
def fastBubbleSort(arr):
    flag = True
    round = 1
    while flag and round <= len(arr)-1:
        flag = False
        for i in range(len(arr)-round): # becoz iteration not required entire comparision
            if arr[i] > arr[i+1]:
                arr[i],arr[i+1] = arr[i+1], arr[i] # Swap
                flag = True # avoid unnecessary passes when data is already sorted
        round += 1
    return round


def main():
    #method-1 O(n^2) 
    lis = [1,2,3,4,5,6,7,9,10,8,11,12,13,14,15,18,19]
    print(f"before Sorting -- {lis}")
    print(f"Number of Passes : {bubbleSort(lis)}")
    print(f"After Sorting -- {lis}")

    #method-2 O(n) best case
    lis = [1,2,3,4,5,6,7,9,10,8,11,12,13,14,15,18,19]
    print(f"before Sorting -- {lis}")
    print('--Fast Bubble Sort--')
    print(f"Number of Passes : {fastBubbleSort(lis)}")
    print(f"After Sorting -- {lis}")

if __name__ == "__main__":
    main()
