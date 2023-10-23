n = input()
stack = []
ans = "正確"

for i in range(len(n)):
    
    if n[i] in "([{":
        stack.append(n[i])
    
    elif not stack:
        ans = "錯誤"

    else:
        if n[i] == ")" and stack[-1] == "(":
            stack.pop()

        elif n[i] == "]" and stack[-1] == "[":
            stack.pop()

        elif n[i] == "}" and stack[-1] == "{":
            stack.pop()

print(ans)

