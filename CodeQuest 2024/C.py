from math import ceil

t=int(input())
for _ in range(t):
    n = int(input())
    if ((n%11 and (n%(n-(n//11)*11))==0) or (n%11==0)): print("YES")
    else: print("NO")