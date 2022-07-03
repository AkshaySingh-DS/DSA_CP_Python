# exponential time complexity
def fibo(num):
    if num == 0:
        return 0
    if num == 1:
        return 1
    return fibo(num-1) + fibo(num-2)

# let's try to use memoization O(N)
def fibonacci(num):
    fibo=[0, 1] #considering 0 as 0th term
    for i in range(2, num + 1):
        fibo.append(fibo[i-1] + fibo[i-2])

    return fibo[num]

if __name__ == "__main__":
    print(fibo(int(input())))
    print(fibonacci(int(input())))

#task here to calculte log(N) time