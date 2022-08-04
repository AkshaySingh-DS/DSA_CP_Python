# method-1 Bottom Up Approach
# time complexity : O(target * coins)
def minNumbersOfCoinChange(coins, target):
    dp = [10000] * (target+1)
    dp[0] = 0

    # logic
    for i in range(1, target+1):
        for c in coins:
            if i-c >= 0 and dp[i-c] != 10000:
                dp[i] = min(dp[i], dp[i-c]+1)

    return dp[-1] if dp[-1] != 10000 else -1

# method-2 Top down Approach- Memoization
def minNumberOfCoinChangeTD(coins, target, dp):
    # base case
    if target == 0:
        return 0

    # memoized step
    if dp[target] != 10000:
        return dp[target]

    # recursive case
    for c in coins:
      if target - c >= 0:
          dp[target] = min(dp[target], minNumberOfCoinChangeTD(coins, target-c, dp) + 1)

    return dp[target]

# let max coin size is restricted to 1000.
if __name__ == "__main__":
    coins = [3, 5]
    target = 7
    dp = [10000] * (target+1)
    dp[0] = 0
    print(minNumbersOfCoinChange(coins, target))
    ans = minNumberOfCoinChangeTD(coins, target, dp)
    if ans == 10000:
        print(-1)
    else:
        print(ans)

