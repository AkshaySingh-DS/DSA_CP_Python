"""
Problem Statement : Codestdio
https://www.codingninjas.com/codestudio/problems/duplicate-in-array_893397?leftPanelTab=0
TIME COMPLEXIT Y : O(n)
"""
#assuming that there must be a duplicate
import sys
def findDuplicates(arr, size):
    hashmap = {}
    for i in range(size):
        if hashmap.get(arr[i]):
            return arr[i]
        
        hashmap[arr[i]] = True


def main():
    t = int(sys.stdin.readline().rstrip())
    while t > 0:

        size = int(sys.stdin.readline().rstrip())
        arr = list(map(int, sys.stdin.readline().rstrip().split()))
        print(findDuplicates(arr, size))
        t -= 1


if __name__ == "__main__":
    main()
"""
CPP solution : 
"""