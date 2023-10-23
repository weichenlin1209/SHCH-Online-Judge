n = int(input())
out = []
a = 1

while True:
    if n >= (a**2):
        out.append(a**2)
        a += 1
    else:
        break
    
print(len(out) ,sum(out))