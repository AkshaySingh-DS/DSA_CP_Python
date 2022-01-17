"""
Problem Statement : https://practice.geeksforgeeks.org/problems/anagram-1587115620/1
Time Complexity : O(M + N) best case
"""

"""
Using Sorting - > O(N logN + M log M) time.
space Complexity - > O(1)
"""
def isAnagram(a, b):

    #simple edge case
    if len(a) != len(b):
        return 'NO'

    a, b = sorted(a), sorted(b)

    for i in range(len(a)):
        if a[i] != b[i]:
            return "NO"

    return "YES"

"""
using character count -> O(N + M)
space complexity O(1)
"""
def isAnagram2(a, b):
    #since 256 for all types of characters if only english characters are required then it will be 26
    count1 = [0] * 256
    count2 = [0] * 256

    alen, blen = len(a), len(b)

    #edge case
    if alen != blen:
        return "NO"

    for i in range(alen):
        count1[ord(a[i])] += 1
        count2[ord(b[i])] += 1

    for i in range(256):
        if count1[i] != count2[i]:
            return "NO"

    return "YES"

"""
CPP Solution:
 int countArr1 [26] = {0};
    int countArr2 [26] = {0};
    
    if (a.length() != b.length())
        return false;
    
    for(int i = 0; i < a.length(); i++){
        
        countArr1[a[i] - 'a']++;
        countArr2[b[i] - 'a']++;
    }
    
    for (int  i = 0; i < 26; i++){
        
        if (countArr1[i] != countArr2[i])
            return false;
    }
    
    return true;
"""
if __name__ == "__main__":
    string1 = input()
    string2 = input()
    print(isAnagram(string1, string2))
    print(isAnagram2(string1, string2))