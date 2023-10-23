n = input()

check = True
times = 0
for i in n:
    if i != "1" and i != "0":
        check = False
        break

    elif i == "1":
        times += 1

if check == True:
    print(times)

else:
    print("非二進位數")