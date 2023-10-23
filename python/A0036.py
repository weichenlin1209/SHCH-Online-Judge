def priority(n):
    if n in "+-":
        return 1
    elif n in "*/":
        return 2
    elif n in "([{":
        return 0

def to_postfix(n):
    result = []
    operator_stack = []
    for i in n:
        if i.isdigit():
            result.append(i)

        elif i in "+-*/":
            if len(operator_stack) == 0:
                operator_stack.append(i)

            elif priority(operator_stack[-1]) >= priority(i):
                while priority(operator_stack[-1]) >= priority(i):
                    result.append(operator_stack.pop())
                    k = 1
                    if len(operator_stack) == 0:
                        operator_stack.append(i)
                        k = 0
                        break
                
                if k == 1:
                    operator_stack.append(i)
                    k = 0

            else:
                operator_stack.append(i)
                    
        elif i in "([{":
            operator_stack.append(i)
        
        elif i in ")]}":
            while operator_stack[-1] not in "([{":
                result.append(operator_stack.pop())
            
            operator_stack.pop()

    while len(operator_stack) != 0:
        result.append(operator_stack.pop())

    return result

def to_infix(n):
    result = []
    s = ""
    for i in n:
        if i in "+-*/()" :
            if s != "":
                result.append(s)
                s = ""
            result.append(i)
            
        elif i  == " ":
            continue

        else:
            s += i

    if s != "":
        result.append(s)
    return result

def calculate(postorder):
    k = -1
    while k + 1 < len(postorder):
        k += 1
        if postorder[k] == "+":
            postorder[k-2] = postorder[k-2] + postorder[k-1]

        elif postorder[k] == "-":
            postorder[k-2] = postorder[k-2] - postorder[k-1]

        elif postorder[k] == "*":
            postorder[k-2] = postorder[k-2] * postorder[k-1]

        elif postorder[k] == "/":
            postorder[k-2] = postorder[k-2] / postorder[k-1]
        else:
            continue
        postorder.pop(k)
        postorder.pop(k-1)
        k -= 2
    
    return postorder[0]

def stoi(token):
    for i in range(len(token)):
        if token[i] in "{([])}+-*/":
            continue
        else:
            token[i] = int(token[i])
    return token

#=============main=============#

n = int(input())

for i in range(n):
    formula = input()
    formula = to_infix(formula)
    formula = to_postfix(formula)
    formula = stoi(formula)
    ans = calculate(formula)
    if ans % 1 == 0 :
        ans = int(ans)
    

    print(ans)

