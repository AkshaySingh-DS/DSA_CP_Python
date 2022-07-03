def createBalancedBrackets(n, open, close, output,  ans):
    if open == close and open == n:
        print(output)
        ans.append(output)
        return

    # including the open bracket
    if open < n:
        #output += "(" doesn't work
        createBalancedBrackets(n, open+1, close, output+"(", ans)

    # including closing bracket
    if close < open:
        createBalancedBrackets(n, open, close+1, output+")", ans)



if __name__== "__main__":
    num = int(input())
    output = ""
    open, close = 0, 0
    ans=[]
    createBalancedBrackets(num, open, close, output, ans)
    print(len(ans))