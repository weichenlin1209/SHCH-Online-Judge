n = int(input())
sequence = [n]

def f(a):
    if a % 2 == 0:
        sequence.append(a//2)
        return f(a//2)
    
    elif a == 1:
        return 0
    
    else:
        sequence.append(3*a + 1)
        return f(3*a + 1)

f(n)
ans = ""
for i in sequence:
    ans += str(i) + " "

print(ans[:-1])
print(len(sequence))



    

