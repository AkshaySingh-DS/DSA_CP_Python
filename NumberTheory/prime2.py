"""
Problem Statement : Prime Numbers b/w 1 to N

contraints: 3 <= N <= 10^18
"""

import prime
import time

#Approach - 1:  O(N^2)
def primeRange1(number):
    return [num for num in range(2, number + 1) if prime.is_prime(num)]

#Approach - 2:  O(N^2)
def primeRange2(number):
    return [num for num in range(2, number + 1) if prime.is_prime2(num)]

#Approach - 3:  O(N root(N))
def primeRange3(number):
    return [num for num in range(2, number + 1) if prime.is_prime3(num)]

#little more optimized only 6n-1 and 6n+1 number is possible prime, except 2,3
def primeRange4(number):
    prime_list = [2, 3]

    for num in range(2, number + 1):

        if (num + 1) % 6 == 0 or (num - 1) % 6 == 0:
            
            if prime.is_prime3(num):
                
                prime_list.append(num)

    return prime_list

if __name__ =="__main__":
    start_time = time.process_time()
    print(primeRange1(1000))
    print(f"Execution time {time.process_time()-start_time}")
    print('--'*20)


    start_time = time.process_time()
    print(primeRange2(1000))
    print(f"Execution time {time.process_time() - start_time}")
    print('--' * 20)


    start_time = time.process_time()
    print(primeRange3(1000))
    print(f"Execution time {time.process_time() - start_time}")
    print('--' * 20)


    start_time = time.process_time()
    print(primeRange4(1000))
    print(f"Execution time {time.process_time() - start_time}")