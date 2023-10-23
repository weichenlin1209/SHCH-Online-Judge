n = list(map(eval,input().split()))
a = 1
for i in range(n[1]):
    a *= n[0]
    a = str(a)

    if len(a) > 5:
        b = ""
        c = ""
        for j in range(len(a)-1, len(a)-6 ,-1):
            b += a[j]
        for k in range(len(b)-1 ,-1 ,-1):
            c += b[k]
        a = c
    
    a = int(a)

print(a)


