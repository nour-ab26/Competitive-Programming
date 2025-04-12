n=int(input())
w=0
a=input()
b=input()
for i in range(n):
    if (a[i]<b[i]): w+=1
    elif (a[i]==b[i]): break
if (w%2): print("Zoro")
else: print("Luffy")