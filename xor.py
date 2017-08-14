q=input()
ans=[]
for a in range(q):
    n=input()
    nos=map(int,raw_input().split(' '))
    nos.sort()
    ans+=[ nos[i]^nos[i+1] for i in range(0,len(nos)-1)]
for i in range(ans):
    print i
