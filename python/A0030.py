words = input()
alphabet = [[chr(x)] for x in range(97 ,123 ,1)]

for i in words:
    if (ord(i) >= 65 and ord(i) <= 90) or (ord(i) >= 97 and ord(i) <= 122) :
        if ord(i) >= 65 and ord(i) <= 90:
            k = ord(i) + 32
        else:
            k = ord(i)
        
        k = k - 97
        if len(alphabet[k]) == 1:
            alphabet[k].append(1)
        else:
            alphabet[k][1] += 1

k = 0
for i in range(26):
    if len(alphabet[i]) == 2:
        print("%s = %d"%(alphabet[i][0] ,alphabet[i][1]))
        k += 1

print(k)

    
