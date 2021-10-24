# 1st Approach Using MinIndex(min value)
def minIndex(arr, current):
    minIndex = current
    for i in range(current+1, len(arr)):
        #update minindex
        if arr[minIndex] > arr[i]:
            minIndex = i

    return minIndex 
    
def SelectionSort(arr):
    for current in range(len(arr)-1):
        minInx = minIndex(arr, current)
        if minInx != current:
            #swap --> place the data in correct palce
            arr[minInx], arr[current] = arr[current], arr[minInx] 
#In above Clue is that we are try to place minimum value at sorted sub array side

#2nd Approach Using MaxIndex(max value)
def maxIndex(arr, current):
    maxIndex = current
    for i in range(current-1, -1,-1): # upto 0th
        if arr[maxIndex] < arr[i]:
            maxIndex = i
    return maxIndex


def SelectionSort_2(arr):
    for current in range(len(arr)-1, 0,-1): # Upto 1th
        maxInx= maxIndex(arr, current)
        if arr[maxInx] != arr[current]:
            arr[maxInx], arr[current] = arr[current], arr[maxInx]
#In above Clue is that we are try to place maximum value at sorted sub array side
#Time complexity of this O(N^2).
 
def main():
    lis = [-3,-10,-7,2,0,1,5,6]
    print('-----------------Method-1 MinValue----------------')
    print("Before Sorting", lis)
    SelectionSort(lis)
    print("After Sorting", lis)
    print('\n-----------------Method-2 MaxValue-------------')
    lis2 = [-4,5,1,0,8,10,12,-8]
    print("Before Sorting", lis2)
    SelectionSort_2(lis2)
    print("After Sorting", lis2)

if __name__ =="__main__":
    main()
