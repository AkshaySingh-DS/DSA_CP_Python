import time
# time complexity : O(3^N) and space O(N) for recursion stack_Queue
def countWays(num):
    if num < 0:
        return 0

    if num == 0:
        return 1

    return countWays(num-1)+ countWays(num-2)+ countWays(num-3)


# time complexity : O(N) and space O(N) for array using DP
def modifiedCountWays(num):
    if num == 1 or num==0:
        return 1

    if num == 2:
        return 2

    if num < 0:
        return -1

    # else logic
    ans = [0]* (num+1)
    ans[0], ans[1], ans[2] = 1, 1, 2

    for i in range(3, num+1):
        ans[i] = ans[i-1]+ans[i-2]+ans[i-3]

    return ans[num]


if __name__ == "__main__":
    n = int(input())
    start_time = time.time()
    print(countWays(n))
    print(time.time()-start_time)
    start_time = time.time()
    ans = modifiedCountWays(n)
    print(time.time() - start_time)
    if ans == -1:
        print("Wrong input")
    else:
        print(ans)