"""
Problem Statement: https://www.codingninjas.com/codestudio/problems/modular-exponentiation_1082146?leftPanelTab=1
Time complexity : log O(b)
Space Complexity : O(log(n)) in case of recursion, in case of iterative O(1)
"""
# a^b mod c
import time

#using recursion
def moduloExp2(a, b, c):
    if b == 0:
        return 1
    if b & 1:
        return (a * (moduloExp2(a ,b >> 1, c) %c ) * (moduloExp2(a, b >> 1, c)%c)) % c
    else:
        return ((moduloExp2(a ,b >> 1, c) % c) * (moduloExp2(a, b >> 1, c) % c)) % c

#using iterative Approach
def moduloExp(a, b, c):
    ans_ = 1
    while b:
        if b & 1:
            ans_ = (ans_ * a) % c
        a = (a * a) % c
        b >>= 1

    return ans_

def main():
    start = time.process_time()
    print(moduloExp(2, 5, 5))
    print(time.process_time()-start)

    start = time.process_time()
    print(moduloExp2(2, 5, 5))
    print(time.process_time()-start)

if __name__ == "__main__":
    main()


