def binarySearchLowerBound(arr, query):
    left = 0 ; right = len(arr) - 1;
    ans = -1

    while left <= right:
        mid = (left + right)//2
        if arr[mid] >= query:
            ans = mid
            right = mid - 1
        else:
            left = mid + 1

    return ans

def main():
   arr = [2, 3, 5, 6, 8, 10, 12]
   query = 2

   print(binarySearchLowerBound(arr, query))


if __name__ == "__main__":
    main()
