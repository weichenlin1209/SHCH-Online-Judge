n = int(input())
orginal = input()
secret = ""

for i in orginal:
    a = ord(i)
    a += n
    if a > 126 :
        a = a - 126 + 31
    a = chr(a)
    secret += a

print(secret)   