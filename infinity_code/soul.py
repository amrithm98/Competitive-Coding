n = input()
fin = {}
tf = {}

def get(di , value ):    
    for di, val in di.iteritems(): 
        if val == value:
            return di
    return -1

def findSol(key,times):
    new_key = get(tf,key)
    if(new_key == -1):
        return times
    return findSol(new_key,times+1)


def solve():
    key = get(fin,n)
    if(key == -1):
        return "-1"
    else: 
        return findSol(key,1)

for i in range(1,n+1):
    val = raw_input().split(" ")
    if(val[-1] == "alien"):
        fin[i] = int(val[0])
    else:
        tf[i] = int(val[0])
max_len = input()
if( solve() <= max_len ):
    print "RUN!"
else:
    print "Stay!"