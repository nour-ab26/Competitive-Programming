n=int(input())
for i in range(n):
    x=map(int, input().split())
    d = {y: 0 for y in set(x)}
for i in x:
    if (d[x]<2) :d[x]+=1
print(d)
    