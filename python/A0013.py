n = input()

a = 0
for i in n:
    a += int(i)**len(n)

if a == int(n):
    print("是")
else:
    print("否")
