# Here we assume that number is always +ve or 0(Non negative)
def factorial(num):
    if num == 0:
        return 1
    return num * factorial(num-1)

# time complexity in worst case O(N) and
# since it is recursion space complexity also O(N) becoz of call stack_Queue

# memoization(usually fast check using time import)
def fact(num):
    fact=[1, 1]
    for i in range(2, num+1):
        fact.append(fact[i-1] * i)
    return fact[num]

if __name__ == "__main__":
     print(f"{factorial(int(input()))}")
     print(fact(int(input())))

#task here to minimize it < O(N)