n = input()
odd_n = []
even_n = []

for i in range(0 ,len(n) ,2):
    odd_n.append(int(n[i]))
for i in range(1 ,len(n) ,2):
    even_n.append(int(n[i]))

print(abs(sum(odd_n) - sum(even_n)))