#!/bin/python

import sys
from math import sqrt
MAX = 1000001


def prime2(n):
    

def sieve_of_eratosthenes():
    global sieve
    sieve = [1]*MAX
    sieve[0] = 0
    sieve[1] = 0
    lim = int(sqrt(MAX))
    for i in range(2,lim):
        if(sieve[i]):
            for j in range(i*i,MAX,i):
                sieve[j] = 0
    global primes
    primes = [2]
    for i in range(3,MAX):
        if(sieve[i]):
            primes += [i]

def prime(n):
    if(n >= MAX):
        for i in range(len(primes)):
            if(n % primes[i] == 0):
                return False
    else:
        return sieve[n]
    return False


def getDivisions(n):

    if(n == 1):
        return 1

    temp = n 
    if(temp % 2 == 0):
        sumVal = 0

        while(n % 2 == 0):
            sumVal += n
            n /= 2
        
        ans = 0
        sumVal += n 

        while(not prime(n) and n > 1):
            lim = int(sqrt(n))

            for i in range(3,lim+1,2):
                if(n % i == 0):
                    ans = n/i
                    break

            sumVal += ans
            n = ans
        sumVal += 1
        return sumVal
    else:

        sumVal = 0
        n = temp
        sumVal += n
        ans = 0

        while(not prime(n) and n > 1):
            lim = int(sqrt(n))

            for i in range(3,lim+1,2):
                if(n % i == 0):
                    ans = n/i
                    break

            sumVal += ans
            # print "First Odd divisor",ans
            n = ans
        sumVal += 1
        return sumVal

def longestSequence(a):
    #  Return the length of the longest possible sequence of moves.
    sumVal = 0
    for i in a:
        ans = getDivisions(i)
        sumVal += ans
    return sumVal


if __name__ == "__main__":
    n = int(raw_input().strip())
    a = map(long, raw_input().strip().split(' '))
    sieve_of_eratosthenes()
    result = longestSequence(a)
    print result
