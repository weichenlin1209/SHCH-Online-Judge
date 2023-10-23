n = list(map(str,input().split()))

a = n[0] + n[1] + n[2]
b = n[0] + n[2] + n[1]
c = n[1] + n[0] + n[2]
d = n[1] + n[2] + n[0]
e = n[2] + n[1] + n[0]
f = n[2] + n[0] + n[1]

print(max(a ,b ,c ,d ,e ,f))