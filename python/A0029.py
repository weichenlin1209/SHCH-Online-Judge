words = input()
num = []

check = True
for i in words:
    if ord(i) >= 65 and ord(i) <= 90:
        num.append(ord(i) - 64)

    elif ord(i) >= 97 and ord(i) <= 122:
        num.append(ord(i) - 96)
    
    else:
        check = False

if check == True:
    print(sum(num))
else:
    print("Fail")