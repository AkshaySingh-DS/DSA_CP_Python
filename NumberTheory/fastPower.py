"""
Problem Statement : Power of A ^ B.
->using bitwise calculate the power(a, b) that takes O(logN) time
->max no of bits to reperesent N is log(N).
->we can do same thing using recusrion O(log N) but it takes some extra space recursion stack
"""
import time
def powerRec(a, b):
    if b == 0:
        return 1
    if b&1:
        return a * powerRec(a, b>>1) * powerRec(a, b>>1)
    else:
        return powerRec(a, b>>1) * powerRec(a, b>>1)


def power(a, b):
    pow = 1
    while b > 0:
        if b & 1:
            pow = pow * a
        a = a * a
        b = b>>1
    return pow

def main():
    a=int(input())
    b=int(input())
    start = time.process_time()
    print('power is :', power(a, b))
    print(time.process_time() - start)
    start = time.process_time()
    print(f"power is : {powerRec(a, b)}")
    print(time.process_time() - start)

if __name__=="__main__":
   main()