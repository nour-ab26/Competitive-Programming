List=input().split("\n")
calib=[]
s=10
for i in List :
    n=len(i)
    for j in range(n):
        if i[j] in [1,2,3,4,5,6,7,8,9,0] :
            s=s*int(i[j])
            break
    for j in range(n,-1,-1):
        if i[j] in [1,2,3,4,5,6,7,8,9,0] :
            s=s+int(i[j])
            break
    calib.append(s)
print(sum(calib))