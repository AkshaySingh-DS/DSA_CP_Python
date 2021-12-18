""" 
Problem Statement : Check a number is prime or not.
COMPOSITES NUMBER : Composites numbers are those which are not prime except 1.
NOTE : 
1 is the only number which is not prime as well as not composite 
"""

import time, sys

# brute force O(N)
def is_prime(k):
    if k == 2:
        return True
    
    #k would be a prime if k cant be devided by number lying from 2 to k - 1
    for i in range(2, k):
        if k % i == 0:
            return False
    
    #else block will execute when any number in b/w 2 to k-1 cant devide k
    return True

#skipping even numbers - > O(N/2) consider O(N)
def is_prime2(k):
    if k == 2:
        return True

    #for even
    if k & 1 == 0:
        return False

    #for odd numbers only
    for i in range(3, k, 2):
        if k % i == 0:
            return False
    
    return True

#skipping even's and more optimization over factor O(root(N))
def is_prime3(k):
    if k == 2:
        return True

    #for even numbers 
    if k & 1 == 0:
        return False

    #we are not using sqrt method which take O(log N) time to calculate square.
    i = 3
    while i * i <= k:  
        if k % i == 0:
            return False
        
        #skip evens
        i += 2
    
    return True


if __name__=="__main__":
    number = int(sys.stdin.readline().strip())

    #Arroach - 1
    start_time = time.process_time()
    print(is_prime(number))
    print(time.process_time() - start_time)

    #Arroach - 2
    start_time = time.process_time()
    print(is_prime2(number))
    print(time.process_time() - start_time)

    #Arroach - 3
    start_time = time.process_time()
    print(is_prime3(number))
    print(time.process_time() - start_time)