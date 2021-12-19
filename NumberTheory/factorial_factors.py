"""
Problem Statement : Calculate the no of factors in a factorial 'N'
Approach :  
Time Complexity : O(N LogLogN) + (N)

"""

import sys
#O(N LogLogN)
def primeSieve(number):
    #make all even's non prime except 2
    p = [True] * (number + 1)

    for i in range(0, number + 1, 2):
        p[i] = False
    p[1], p[2] = False, True

    #logic for seive i.e. make all prime factors as non prime 
    i = 3
    while i * i <= number:
        if p[i]:
            #look at step size i.e.  i(odd) + 2n(even) -> odd (check only for Odd)
            for j in range(i * i, number + 1, 2 * i):  
                p[j] = False

        i += 2

    #return only primeList
    return [i for i in range(0, number + 1) if p[i]]

def factorial_NumberOfFactor(Num):
    #get PrimeList updated
    primeList = primeSieve(Num)

    result_ = 1
    for i in range(0, len(primeList)):
        #get prime
        prime = primeList[i]
        sum = 0

        while Num//prime:
            #calculate power of 2
            sum += Num// (prime)
            prime *= primeList[i]

        result_ *= (sum + 1)

    return result_

def main():
    number = int(sys.stdin.readline().strip())
    print(factorial_NumberOfFactor(number))

if __name__ =="__main__":
    main()
    
