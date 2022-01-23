"""
Problem Statement: Count the number of patterns in text
Time Complexity : O(N)
Space Complexity : O(N)
"""

from Strings.longest_suffix_prefix import computeLPS

def countPattern(text, pattern):
    len_pattern = len(pattern)
    len_text = len(text)
    lps = computeLPS(pattern)

    # count pattern logic
    i = 0
    j = 0
    cnt = 0
    while i < len_text:

        if text[i] == pattern[j]:
            i += 1
            j += 1

        #change of code for counting the pattern
        if j == len_pattern:
            cnt += 1
            j = lps[j-1]

        elif i < len_text and text[i] != pattern[j]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1


    return cnt

if __name__ == "__main__":
    text = input()
    pattern = input()

    print(countPattern(text, pattern))