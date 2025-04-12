t=int(input())
for _ in range(t):
    n=int(input())
    inj = {"A": 0, "B": 0, "AB": 0, "O": 0}
    don = {"A": 0, "B": 0, "AB": 0, "O": 0}
    s=input().split()
    for c in s: inj[c]+=1
    s=input().split()
    for c in s: don[c]+=1
    miss=0
    miss1=0
    ab=don["AB"]-inj["AB"]
    b=don["B"]-inj["B"]
    if (b>0): miss+=b
    else: miss1+=abs(b)
    a=don["A"]-inj["A"]
    if (a>0): miss+=a
    else: miss1 += abs(a)
    o=don["O"]-inj["O"]
    if (miss1>0): o-=miss1
    if (ab<0 and o>0): o-=miss
    if ((miss1==0 and miss=0 and o==0)): print("YES")
    else: print("NO")
    