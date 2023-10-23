n = eval(input())
prize = []
for i in range(n):
    s = input()
    target = ""
    for i in range(len(s)-1 , -1,-1):
            target = target + s[i]
    target = int(target)
    prize.append(target)

sum = 0
for i in prize:
      sum += i

print(sum)
      
    