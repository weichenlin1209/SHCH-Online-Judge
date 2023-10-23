n = int(input())

if n % 400 == 0:
    print("閏年")
    
elif n % 4 == 0:
    if n % 100 == 0:
        print("平年")
    else:
        print("潤年")

else:
    print("平年")

