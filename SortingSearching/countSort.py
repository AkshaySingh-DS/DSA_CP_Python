"""

NOTE: Clue is that we need to play with indices no comparison at all by maintaing a frequecny array. 
1. Time complexity O(N+R) where R is maximum number in array and N is the number of elements in list/array
2. space complexity O(R)
3. Where to use -> crucioal Point:- This algorithm is useful when we have data almost in a consecutive manner.
4. This algorithm may worst than Bubble sort if there is high sparsity in frequency array.

"""

def countSort(arr):
    # Auxillarry list with count zero initially , last index represent the maximum element  max(arr) + 1
    freArrLength = max(arr) + 1
    freqArr = [0] * freArrLength

    #logic --> count frequecy of each occurrence
    for val in arr:
        freqArr[val] += 1

    sortArr = []

    #logic to sort the array without any comparision
    for idx in range(freArrLength):

        #keep on adding untll element is not zero 
        while freqArr[idx]:
            sortArr.append(idx)
            freqArr[idx] -= 1

    return sortArr


def main():
    #given data is almost a consuctive manner
    lis = [3, 5, 2, 1, 3, 5, 4, 2, 1, 8, 10, 7]
    size = len(lis)
    print(countSort(lis))

if __name__ == "__main__":
    main()