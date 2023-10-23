def reverse(token):
    token = str(token)
    result = ""
    for i in range(len(token)-1 ,-1 ,-1):
        result += token[i]

    return result

def to_int(token):
    for i in range(len(token)):
        token[i] = int(token[i])


#=============main============#
input_times = int(input())
price = []
reversed_price = []

for i in range(input_times):
    n = input()
    price.append(n)
    reversed_price.append(reverse(n))

to_int(reversed_price)
a = reversed_price.index(max(reversed_price))
b = reversed_price.index(min(reversed_price))

print(price[b] ,price[a])

