"""
Problem Stratement : Multiplicative Modulo Inverse i.e. calculate  multiplicative modulo inverse of A with M 

WHAT is Multiplicative Inverse of A ? i.e. if A.B = 1 then B is called  multiplicative inverse of A.

WHAT is multiplicative Modulo Inverse of A with M ?
i.e. if (A * B) % M == 1 THEN B is CALLED MULTIPLICATIVE MODULO INVERSE OF A , WE'VE TO FIND B??

(Multiplicative Modulo Inverse )'B' ONLY EXISTS IFF GCD(A, M) = 1, i.e they should be co prime

NOTE: MOREOVER WE ALWAYS WANT B AS +VE i.e. the value of B lies [1, M-1],
we can convert above problem using extended euclidean(Ax + By = GCD(A,B))
AB + MQ = 1 then get B.

Time Complexity: O(log max(A, M))
"""

import sys
def extendedEuclidean(a, b):
    if a == 0 :
        return b, 0, 1

    gcd, x1, y1 = extendedEuclidean(b % a, a)
    currentx = y1 - (b//a) * x1
    currenty = x1

    return gcd, currentx, currenty

def inverseModulo(A, M):
    gcd, x, _ = extendedEuclidean(A, M)

    return gcd, x

def main():
    a, m = map(int, sys.stdin.readline().split())

    # calculate b s.t. (13 * b) % 11 = 1.
    gcd, x = inverseModulo(a, m)

    if gcd == 1:
        #to make it positive if x is -ve since b-> [1, M-1]
        print('inverse modulo: ',  (x + m ) % m)
    else:
        print(f'Multiplicative Modolu Inverse of {a} w.r.t. {m} not exists')


if __name__=="__main__":
    main()


