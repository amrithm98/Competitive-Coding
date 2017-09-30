n=int(input())

max_size=1000005
mod=1e9 + 7

powers_2=[0]*max_size
powers_2[0]=1

for i in range(1,n+1):
    powers_2[i]=(powers_2[i-1]*2)%mod

strength=list(map(int,input().split()))

ta=[0]*max_size

for i in strength:
    ta[i]+=1

count=[0]*max_size  #Array With count of elements having i as divisor
ans=[0]*max_size

for i in range(2,max_size):
    for j in range(i,max_size,i):
        count[i]+=ta[j]


for i in range(max_size-1,0,-1):
    if(count[i]==0):
        continue
    else:
        ans[i]=(count[i]*powers_2[count[i]-1])%mod
        for j in range(2*i,max_size,i):
            ans[i]=(ans[i]+mod-ans[j])%mod


result=0

for v in range(2,max_size):
    result=(result+v*ans[v])%mod

print(int(result))



