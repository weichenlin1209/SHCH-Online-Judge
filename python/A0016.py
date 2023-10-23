n = input()

check = "是"
for i in n:
    if int(i) % 2 == 0:
        check = "否"
        break

print(check)