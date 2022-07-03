def countsubsetSum(arr, target):
    # base
    if len(arr)==0 and target != 0:
        return 0
    if target == 0:
        return 1

    # logic
    return countsubsetSum(arr[1:], target-arr[0]) \
           + countsubsetSum(arr[1:], target)

# time complexity same as to explore all subsequnces

#idea is pick not pick
if __name__ == "__main__":
    ls = [1, 2, 3, 4, 5]
    target = 6
    print(countsubsetSum(ls, target))