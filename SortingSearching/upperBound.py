def binarySearchUpperBound(arr , length, query):
    left = 0 ; right = length - 1;
    ans = - 1

    # logic
    while left <= right:
        mid = (left + right)//2
        if arr[mid] <= query:
            ans = mid
            left = mid + 1

        else:
            right = mid - 1

    return ans



def main():
    arr = [3, 5, 6, 8,8, 10, 12]
    query = 9
    print(binarySearchUpperBound(arr, len(arr), query))


if __name__ == "__main__":
    main()