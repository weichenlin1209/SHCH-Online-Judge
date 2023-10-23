n = int(input())
orginal = input()
secret = ""

for i in orginal:
    a = ord(i)
    a -= n
    if a < 32 :
        a = a + 95
    a = chr(a)
    secret += a

print(secret)   