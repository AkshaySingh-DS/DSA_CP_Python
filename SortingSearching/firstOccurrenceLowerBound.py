"""
problem: Find first occurrence of given element 
time complexity : O(Log N)

NOTE: Clue is that we have to store the occurence first when we are searching 
data value if found then also search for left 
i.e [1,2,2,2,2,2,2,2,2,2,3,3,3] answer 1 for key = 2 and for key = 3 answer is 10
"""
import math
def binarySearchfirstOcc(lis, key):
    ans = -1
    left, right = 0, len(lis)-1

    #logic
    while left <= right:
        mid = math.floor((left+ right)/2)
        if lis[mid] == key:
            ans = mid
            right = mid - 1

        elif lis[mid] < key:
            left = mid + 1

        else:
            lis[mid] > key
            right = mid - 1
    
    return ans

def main():
    lis = [1, 1, 2, 2 , 2, 2, 2, 2, 2, 2, 3, 3, 4, 7]
    Key_item1 = 3
    res = binarySearchfirstOcc(lis, Key_item1)
    print(res) if res != -1 else print(f'item {Key_item1} Not found')

if __name__ == "__main__":
    main()
