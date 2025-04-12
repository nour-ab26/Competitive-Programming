from math import ceil
t=int(input())
for _ in range(t):
    x,y,k=map(int, input().split())
    print(int(ceil((y+k)/x)))