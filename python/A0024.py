n = input()
alphbet_1 = input()

a = ord(alphbet_1)
if a > 96:
    a -= 32
else:
    a += 32

alphbet_2 = chr(a)
point = []
ans = ""

for i in range(len(n)):
    if n[i] == alphbet_1 or n[i] == alphbet_2:
        point.append(i)
    
    if len(point) == 2:
        distance = point[1] - point[0]
        ans += str(distance) + " "
        point[0] = point[1]
        point.pop(1)
        
print(ans)