n=int(input())
files = set()
for i in range(n):
    s=input()
    if (s[0]=="t"):
        files.add(s[6:])
    elif (s[0]=="r" and s[3:] in files):
        files.remove(s[3:])
    elif (s[0]=="a"): 
        print(len(files))