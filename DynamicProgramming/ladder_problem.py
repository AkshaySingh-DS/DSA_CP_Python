"""
Three ways to solve dp:

i) using memoization(recursion)-> top down approach
ii) using Bottom Approach (iterative Approach)
iii) using recurrence optimization

"""


# method-2
# time complexity O(ladderSize * steps)
def stepsInLadder(ladderSize, steps):
    dp = [0] * (ladderSize+1)
    dp[0] = 1

    for i in range(1, ladderSize+1):
        for jump in range(1, steps+1):
            if i-jump >= 0:
                dp[i] += dp[i-jump]

    return dp[-1]


# method - 3
# time complexity is O(ladderSize)
def stepsInLadder2(n, k):
    dp = [0] * (n+1)
    dp[0], dp[1], dp[2] = 1, 1, 2

    for i in range(3, n+1):
        dp[i] = 2 * dp[i-1] - dp[i-k-1]

    return dp[-1]

# just recursion
def countSteps(n, k):

    # base case
    if n == 0:
        return 1

    if n < 0:
        return 0

    # recursive case
    ans = 0
    for jump in range(1, k+1):
         ans += countSteps(n-jump, k)

    return ans

# topDown -> recursion + memoization O(nk)
def countStepsTD(n, k , dp):
    # base cases
    if n == 0:
        return 1
    if n < 0:
        return 0

    # memoization DP
    if dp[n] != 0:
        return dp[n]

    ans = 0
    for jumps in range(1, k+1):
      ans += countStepsTD(n-jumps, k, dp)

    dp[n] = ans
    return dp[n]


if __name__ == "__main__":
    ladderSize, steps = 4, 3
    ans = 0
    if ladderSize >= steps:
        print(f'Number of steps to reach at ladder : {stepsInLadder2(ladderSize, steps)}')
    else:
        print('wrong steps given')
    print("recursion : ", countSteps(ladderSize, steps))
    dp =[0] * (ladderSize+1)
    print('top down:', countStepsTD(ladderSize, steps, dp))