n = list(map(int, input().split()))


def f(a):
    if a % 2 == 0:
        sequence.append(a//2)
        return f(a//2)
    
    elif a == 1:
        return 0
    
    else:
        sequence.append(3*a + 1)
        return f(3*a + 1)

sigma = []
num = []
for i in range(n[0] ,n[1]+1 ,1):
    sequence = [i]
    f(i)
    sigma.append(sum(sequence))
    num.append(sequence[0])

a = sigma.index(max(sigma))

print(max(sigma))
print(num[a])