n = int(input())
up = n
down = n

check = False
while (check == False):
    check = True
    for i in str(up):
        if int(i) % 2 == 0:
            check = False
            break
    up += 1

check = False
while (check == False):
    check = True
    for i in str(down):
        if int(i) % 2 == 0:
            check = False
            break
    down -= 1
    
    
print(down+1 ,up-1 ,abs(down - up)-2)