n = list(map(eval ,input().split()))
if n[0] > n[1]:
    n[0] ,n[1] = n[1] ,n[0]

def ans(a ,b):  # b > a
    if b % a != 0:
        c = b % a
        return ans(c,a)
    else:
        return a
    
a = ans(n[0] ,n[1])
if a == 1:
    print("True")
else:
    print("False")



