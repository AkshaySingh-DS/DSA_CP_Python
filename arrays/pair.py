#method -1 (Not correct way have some issues)
def pair(arr, s):
    hashMap = {i: True for i in arr}
    # this might not work for some cases like if we have duplicate element (2,2) or just
    # one 2, and sum = 4, then it'll return [2, 2] which is incorrect

    # logic
    for i in range(len(arr)):
        if hashMap.get(s - arr[i]):
            return [arr[i], s-arr[i]]

    else:
        return [-1, -1]

#method -2 correct way 
# Time O(N) and space O(N)
def pair2(arr , sum): 
    hashMap = {}

    # logic
    for i in range(len(arr)):
        if hashMap.get(sum-arr[i]):

            return [arr[i],sum-arr[i]]
        else:

            hashMap[arr[i]] = True
    else:

        return [-1, -1]


# NOTE - Other solution brute force search O(N^2) and one optimization after sorting with binary search will takes O(N log N)
if __name__ =="__main__":
    #data = [10, 5, 2, 3, 6, 9, 11]
    data = [10, 5, 2, 3, -6, 9, 11]
    sum = 4
    print(pair2(data, sum))