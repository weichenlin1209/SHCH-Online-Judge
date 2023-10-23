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

#=============main=============#

n = input()
n = to_infix(n)
a = to_postfix(n)
ans = ""
for i in a:
    ans += (i + " ")

print(ans[:-1])

