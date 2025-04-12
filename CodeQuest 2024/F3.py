t=int(input())
for _ in range(t):
    n=int(input())
    inj = {"A": 0, "B": 0, "AB": 0, "O": 0}
    don = {"A": 0, "B": 0, "AB": 0, "O": 0}
    s=input().split()
    for c in s: inj[c]+=1
    s=input().split()
    for c in s: don[c]+=1
    if don["O"]<inj["O"]:print("NO")
    else:
        if don["O"]==inj["O"]:
            if (don["A"]==inj["A"] and don["B"]==inj["B"] and don["AB"]==inj["AB"]): print("YES")
            else:
                print("NO")
        else:
            