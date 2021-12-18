""" 
Time complexity O(N loglogN) i.e where N is the given range
N/2 + N/3 + N/5 + N/7 upto we want the prime number list 

"""

#NOTE: key idea is to make all multipliers of prime as not prime, sounds Cool!
import time

def primeRangeSeive(number):

    #primeList indices which represent True are prime and rest of them are non-prime
    primeList = [True] * (number + 1)

    primeList[0], primeList[1] = False, False

    for i in range(2, number + 1):

        if primeList[i]:

            for mul in range(i * 2, number + 1, i):

                primeList[mul] = False


#More optimization can be possible i.e. goes upto root(N) and start from sqaure(num) since those numbers were already covered.
def primeRangeSeive2(number):

    primeList = [True] * (number + 1)
    primeList[0], primeList[1] = False, False

    i = 2
    while i * i <= number:

        if primeList[i]:

            for mul in range(i * i, number + 1, i):

                primeList[mul] = False

        i += 1

#one more little optimization i.e. check for odd numbers only skip the even's
def primeSeive3(number):

    p = [True] * (number+1)

    for i in range(0, number+1 , 2):

            p[i] = False

    p[1], p[2] = False, True

    i = 3
    while i * i <= number:

        if p[i]:

            #i is an odd ,look at the step size i.e. odd + odd => even, so that's why odd + even(2 * odd) -> odd

            for j in range(i * i, number + 1, 2 * i): 
                p[j] = False

        i += 2


def main():
    start_time = time.process_time()
    primeRangeSeive(1000000)
    print(f"\nExecution time {time.process_time()-start_time}")

    start_time = time.process_time()
    primeRangeSeive2(1000000)
    print(f"\nExecution time {time.process_time() - start_time}")

    start_time = time.process_time()
    primeSeive3(1000000)
    print(f"\nExecution time {time.process_time() - start_time}")


if __name__== "__main__":
    main()
    