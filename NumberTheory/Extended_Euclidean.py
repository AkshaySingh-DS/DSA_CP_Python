"""
Problem Statement: ax + by = gcd(a, b):
get the value of x and y.
"""


#time complexity : O(log(max(a, b)))
import sys
def extendedEuclidean(a, b):

    #base case when gcd found
    if a == 0:
        gcd, x, y = b, 0, 1
        return gcd, x, y

    gcd, x1, y1 = extendedEuclidean(b % a, a)
    currentx = y1 - (b // a) * x1
    currenty = x1

    return gcd, currentx, currenty

def main():
    a = int(sys.stdin.readline().strip())
    b = int(sys.stdin.readline().strip())
    gcd, x, y = extendedEuclidean(a, b)
    print(f"Solution for x, y in {a}x + {b}y is x = {x} y = {y} with GCD = {gcd}")


if __name__ == "__main__": 
    main()
