def evaluate(var1, var2, op):
    if op == "+":
        return int(var1) + int(var2)
    if op == "-":
        return int(var1) - int(var2)
    if op == "/":
        return int(var1) // int(var2)
    if op == "*":
        return int(var1) * int(var2)

def evaluationPostfixExpression(expr):
    stack = []
    operatoersSet = {"+", "/", "-", "*", "%"}
    for ch in expr:
        if ch not in operatoersSet:
            stack.append(ch)
        else:
            right = stack.pop()
            left = stack.pop()
            stack.append(evaluate(left, right, ch))

    print(stack[-1])



if __name__ == "__main__":
    expr = "231*+9-"
    evaluationPostfixExpression(expr)
