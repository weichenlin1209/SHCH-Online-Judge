before = list(map(int,input().split(":")))
after = list(map(int,input().split(":")))

before = before[0] * 3600 + before[1] * 60 + before[2]
after = after[0] * 3600 + after[1] * 60 + after[2]

if before >= after:
    a = 86400 - (before - after)

else:
    a = after - before
    
result = []
for i in range(3):
    k = a % 60
    if k < 10:
        k = "0" + str(k)
    result.append(str(k) + ":")
    a //= 60

result.reverse()

a = ""
for i in result:
    a += i

print(a[:-1])