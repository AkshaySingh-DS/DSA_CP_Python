def tripletSum(arr, target):
    ans = []
    arr = sorted(arr)
    # O(N) time
    for i in range(len(arr)-2):
        s, e = i+1, len(arr)-1

        # 2 pointer approach O(N) time since data is already sorted
        while(s < e):
            if arr[s]+arr[e] == target - arr[i]:
                triplet = [arr[i], arr[s], arr[e]]
                ans.append(triplet)
                s += 1
                e -= 1

            elif arr[s] + arr[e] > target - arr[i]:
                e -= 1
            else:
                s += 1

    return ans
# NOTE : time complexity O(N^2)--> O(N log N) + O(N^2) , space O(1) even if the data is not sorted.
# Brute force approach will take O(N^3) time


if __name__ == "__main__":
    data = [1, 3, 4, 2, 7, 6, 5, 15, 8, 9]
    target = 18
    print(tripletSum(data, target))