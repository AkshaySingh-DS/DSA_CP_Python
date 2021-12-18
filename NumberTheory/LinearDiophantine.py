"""
Application of Extended-Euclidean-Algorithm : Linear Diophintine Equation
2 - Variable Equation Solution
references about the problem:
https://brilliant.org/wiki/linear-diophantine-equations-one-equation/
https://cp-algorithms.com/algebra/linear-diophantine-equation.html

Best Application -> like 10 Rs. per apple x kg we bought, 15 Rs per banana and y kg we bought, hence,
10X + 15Y = 50 then tell us X, Y ?
NOTE: Time complexity same of above is same as extended euclidean algo O(log max(A,B))
"""
import sys
def extendedEuclidean(a, b):
    if a == 0 :
        return b, 0, 1

    g, x1, y1 = extendedEuclidean(b % a, a)
    x = y1 - (b//a) * x1
    y = x1
    return g, x, y


def linearDiophintine_one_Solution(a, b, c):
    gcd, x, y = extendedEuclidean(a, b)
    if c % gcd != 0:
        return "No integer solution Exist"

    #else
    x = x * c /gcd
    y = y * c /gcd

    return x, y, gcd


"""
    now all the possible solution
    x = x0 + b/g * t and y = y0 - a/g * t where t = 0, 1, 2, 3, ... 
"""

def main():
    a, b, c = map(int, sys.stdin.readline().split())
    x, y, gcd = linearDiophintine_one_Solution(a, b, c)


    print(f"One solution of {a}x + {b}y = {c} is x = {x}, y = {y}")
    # five solution
    solutions = [(x, y)]
    for t in range(1, 5):
        x1 = x + (b/gcd) * t
        y1 = y - (a/gcd) * t
        solutions.append((x1, y1))

    print(f"possible 5 solutions are : {solutions}")

if __name__== "__main__":
    main()