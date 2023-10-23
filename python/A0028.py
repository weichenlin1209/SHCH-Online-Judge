n = input()
number = ""
money = []

for i in n:
    if i.isdigit():
        number += i
    else:
        if number == "":
            continue
        else:
            money.append(int(number))
            number = ""

if number != "":
    money.append(int(number))

if len(money) == 0:
    print("0")
else:
    print(sum(money))

