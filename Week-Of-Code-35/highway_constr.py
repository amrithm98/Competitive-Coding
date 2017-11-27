#!/bin/python

import sys
MOD = 1000000009

stirlingMat = [[0 for x in range(1001)] for y in range(1001)] 

def modPower(a,b):
    if(b == 0):
        return 1
    result = modPower(a,b/2)
    result = (result*result)%MOD
    if(b%2 != 0):
        result = (result * a)%MOD
    return result 

def fallingFactorial(n,k):

    if(k == 0):
        return 1
    if(k == 1):
        return n
    ans = n
    for i in range(1,k):
        ans = ((ans%MOD)*((n-i)%MOD))%MOD
    return ans

def stirlingFunction(n,k):
    for i in range(n+1):
        stirlingMat[i][0] = 0
    for i in range(k+1):
        stirlingMat[0][i] = 0
    for i in range(1,n+1):
        for j in range(1,i+1):
            if( j == 1 or i == j):
                stirlingMat[i][j] = 1
            else:
                 stirlingMat[i][j] = ((j*stirlingMat[i-1][j])%MOD + (stirlingMat[i-1][j-1])%MOD)%MOD

def highwayConstruction(n, k):
    # Complete this function
    if( n <= 1):
        return 0
    SUM = n+1
    res = 0
    for i in range(1,k+1):
        ff = fallingFactorial(n,i)
        sm = stirlingMat[k][i]
        smallDiv = (ff * modPower(i+1,MOD-2))%MOD
        smallProd = (smallDiv * sm)%MOD
        res = ((res%MOD) + (smallProd%MOD))%MOD
    
    SUM = (SUM * res)%MOD
    SUM = (SUM - 1 - modPower(n,k) + MOD)%MOD
    return SUM%MOD

if __name__ == "__main__":
    q = int(raw_input().strip())
    stirlingFunction(1000,1000)
    for a0 in xrange(q):
        n, k = raw_input().strip().split(' ')
        n, k = [long(n), int(k)]
        # print fallingFactorial(10,5)
        # for i in range(10):
        #     for j in range(10):
        #         print stirlingMat[i][j],
        #     print
        result = highwayConstruction(n, k)
        print result

