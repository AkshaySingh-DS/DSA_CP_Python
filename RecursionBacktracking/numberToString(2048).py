def numberToString(dic_map,num):

    for i in str(num):
        print(dic_map[i], end=" ")

# using Recursion
def stringPrint(dic, num):
    if num == 0:
        return None
    else:
        stringPrint(dic, num//10)
        print(dic[str(num%10)], end= " ")

# NOTE:
# Time complexity for both are same i.e. O(#digits)
# But space complexity get's increased in recursion by O(#digits)

if __name__ == "__main__":
    dic = {'1': 'one', '2': 'two', '0': 'zero', '3': 'three',
           '4': 'four', '5': 'five', '6': 'six', '7': 'seven',
           '8': 'eight', '9': 'nine'}
    numberToString(dic, 2048)
    print()
    stringPrint(dic, 20487526730)