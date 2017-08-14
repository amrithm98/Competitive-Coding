import sys

def getMoneySpent(keyboards, drives, s):
    mix=[(x,y,x+y) for x in keyboards for y in drives]
    maxCost=-1
    for t in mix:
        if(t[2]>maxCost and t[2]<=s):
            maxCost=t[2]
    return maxCost
s,n,m = raw_input().strip().split(' ')
s,n,m = [int(s),int(n),int(m)]
keyboards = map(int, raw_input().strip().split(' '))
drives = map(int, raw_input().strip().split(' '))
#  The maximum amount of money she can spend on a keyboard and USB drive, or -1 if she can't purchase both items
moneySpent = getMoneySpent(keyboards, drives, s)
print(moneySpent)