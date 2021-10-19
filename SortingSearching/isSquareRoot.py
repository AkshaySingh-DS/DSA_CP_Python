"""
problem : if i'll give you a number say X, can you find this number is a square of any number?
"""
#moethod - 1  O(log N)
import time
def isSquareRootBinarySearch(n):
    l = 0; r = n//2
    #logic
    while l <= r:
        mid = (l + r ) //2
        if mid * mid == n:
            return "YES"
        elif mid * mid > n:
            r = mid - 1
        else:
            l = mid + 1

    return "NO"

#moethod - 2 O(N)
def isSquareRootLinearSearch(n):
    for i in range(1, n//2):
        if i * i == n:
            return "YES"

    return "NO"

def main():
    number = int(input())
    start_time = time.process_time()
    print(isSquareRootLinearSearch(number))
    print(time.process_time()-start_time)
    print("-" * 20)
    start_time = time.process_time()
    print(isSquareRootBinarySearch(number))
    print(time.process_time() - start_time)


if __name__ == "__main__":
    main()
