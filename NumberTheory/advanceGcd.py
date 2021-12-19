"""
Problem Statement : Calculate gcd of two numbers

Constraints: 
1 <= Number1 <= 40000
1 <= Number2 <= 2^250

TIME Complexity: O(a) + O(log b))
"""


import sys
def gcd_euclidean(a, b):
    #base
    if a == 0:
        return b
    
    return gcd_euclidean(b % a, a)


#preprocess the string -> time complexity len of (a) i.e. O(a)
def largeMudulo(a, m):
    #base
    if a == "":
        return 0
    
    #get a[:-1], read string from a[0] to a[n-2], not the last character
    return (largeMudulo(a[:-1], m) * 10 + int(a[-1])) % m


def advancedGCD(a, b):
    #let say a is string i.e. range of 10^250
    a = largeMudulo(a, b)
    return gcd_euclidean(a, b)

    
def main():
    #assuming a is always be a string whose range can be 2 ^ 250
    a = sys.stdin.readline().strip()
    b = int(sys.stdin.readline().strip())

    print(advancedGCD(a, b))

if __name__ == "__main__":
    main()