"""
Problem Statement : https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769
or https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
Time Complexity:
Space Complexity:
"""

def isCelebrity(M, n):
    stack = list(range(n))
    while len(stack) > 1:
        # logic
        b = stack.pop()
        a = stack.pop()

        if M[a][b] == 0:
            stack.append(a)
        else:
            stack.append(b)

    # no potential candidate is celebrity if stack empty
    if not stack:
        return -1

    # check whether potential candidate is really celebrity
    tp = stack.pop()
    for j in range(n):
        # if any j don't know potential candidate or potential candidate knows any j
        # then tp potental cnadidate not a celibrity
        if (M[j][tp] == 0 or M[tp][j]) and j != tp:
            return -1

    return tp




if __name__== "__main__":
    matrix = [
              [0, 1, 0],
              [0, 0, 0],
              [0, 1, 0]
            ]
    """matrix = [
        [0, 1],
        [1, 0]
    ]
    """

    matrix = [
        [0, 0, 1, 1],
        [1, 0, 0, 0],
        [0, 0, 0, 0],
        [1, 0, 1, 0]
    ]


    n = 4
    print(matrix)
    print(isCelebrity(matrix, n))