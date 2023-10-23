n = int(input())
k = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
i = 0
a = ""

while True:
    if n % k[i] == 0:
        a += "%d*" %k[i]
        n /= k[i]

    elif n == 1:
        break

    else:
        i += 1

ans = ""
for i in range(len(a)-1):
    ans += a[i]

print(ans)