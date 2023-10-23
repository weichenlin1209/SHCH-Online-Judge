n = int(input())

i = 2
ans = "質數"
while (n > i):
    if n % i == 0:
        ans = "合數"
        break
    i += 1

print(ans)