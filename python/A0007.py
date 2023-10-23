s = list(map(eval ,input().split()))
if s[0] > s[1]:
    s[0] ,s[1] = s[1] ,s[0]

a = s[0]-1
b = s[1]

print(int(b*(b+1)*(2*b+1)/6 - a*(a+1)*(2*a+1)/6))

