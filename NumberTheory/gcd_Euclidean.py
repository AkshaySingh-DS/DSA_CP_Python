"""
Problem Statement : Calculate the Greatest (Highest) Common Divisior b/w two numbers  
and with that help also calculate LCM of two numbers.

"""
import sys, time
#time complexity : O(min(a,b))
def gcd_bruteForce(a, b):
    
    #max value of GCD can be the minimum value b/w (a, b)  i.e. 1 <= GCD <= min(a,b)  
    gcd = 1
    for i in range(2, min(a,b) + 1):
        if a % i == 0 and b % i == 0:
            gcd = i

    return gcd 

#time complexity : O(log A) where A max(a, b)
def gcd_Euclidean(a, b):

    if a == 0:
        return b
    
    return gcd_Euclidean(b % a, a)

""" 
LCM(a,b) * HCF(a,b) = a * b
"""
def LCM(a, b):
    return (a * b)//gcd_Euclidean(a, b)

def main():
    a = int(sys.stdin.readline().strip())
    b = int(sys.stdin.readline().strip())

    starttime = time.process_time() 
    print(f'GCD of given Number is:{gcd_bruteForce(a, b)}')
    print(time.process_time() - starttime)
    
    starttime = time.process_time() 
    print(f'GCD of given Number is: {gcd_Euclidean(a, b)}')
    print(time.process_time() - starttime)

    print(f'LCM of two number is : {LCM(a, b)}')

if __name__=="__main__":
    main()