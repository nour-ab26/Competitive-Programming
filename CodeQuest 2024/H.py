n=int(input())
m=int(input())
arr = []
for i in range(m):
    arr.append(input())
if (n<=m): print(arr[n-1])
else:
    i=0
    while(1):
        n-=(2**i*m)
        i+=1
        if (n<0):
            i-=1
            n+=(2**i*m)
            break
    print(arr[(n-1)//(2**i)])