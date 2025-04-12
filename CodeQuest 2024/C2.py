from math import ceil, log10


t=int(input())
for _ in range(t):
    n=int(input())
    for x in range(11):
        op=log10((n-x)/11)
        if (ceil(op)) == int(op):
            print("Yes")
            break
    else:
        print("No")