"""
CONSEPT OF -> Ternary Search 
-> Array devided in the 3 parts to serahc for target
-> so we have 2 mids => mid1 => l + (r-l)/3 , mid2 => r + (r-l)/3
-> Simlar to binary search
-> Array should ne sorted
-> Divide and Conquer Approach

TIME COMPLEXITY : O(log base(3) n) -> due to comaparison in turn out that it takes more time than binary search

Where can we use: Need visulization
ALl problems of ternary search can be solved using binary search
"""

def ternarySearch(arr, size, key):

    left = 0 ; right = size - 1

    while left <= right:

        mid1 = left + (right - left)//3
        mid2 = right - (right - left)//3

        if (arr[mid1] == key):
            return mid1
        elif (arr[mid2] == key):
            return mid2

        elif (arr[mid1] > key):
            right = mid1 - 1

        elif (arr[mid2] < key):
            left = mid2 + 1 
        else:
            left = mid1 + 1
            right = mid2 - 1
    
    return -1


def main():
    arr = list(range(11))
    print(ternarySearch(arr, 11, 5))

if __name__ == "__main__":
    main()
    
