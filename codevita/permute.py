def fact(n):
    if(n==0):
        return 1
    else:
        fact=1
        for i in range(1,n+1):
            fact*=i
        return fact

def numFromRank(n):
    permNum=""
    perm=[0,1,2,3,4,5,6,7,8,9]
    count=1
    remain=n-1
    for i in range(1,11):
        j=remain//fact(10-i)
        remain=remain%fact(10-i)
        permNum=permNum+str(perm[j])
        del perm[j]
        if(remain==0):
            break
    for i in range(len(perm)):
        permNum+=str(perm[i])
    return int(permNum)

n=int(input())
nums=[0]*n
for i in range(n):
    nums[i]=int(input())
nums=[ int(x) for x in nums]
s=0
for i in range(len(nums)):
    num=numFromRank(nums[i])
    s+=num
print(s)
