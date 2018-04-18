import random

n,m,k = map(int,raw_input().split())
arr = map(int,raw_input().split())
primes = map(int,raw_input().split())

max_val = 0
best_arr = []
for q in range(60):
    brr = [0]*n
    prods = [1]*m
    for i in range(n):
        brr[i] = arr[i] + random.randint(1,k)
        for j in range(m):
            prods[j] = (prods[j]*brr[i])%primes[j]
    
    maxSum = 0

    for i in range(m):
        maxSum += prods[j]
    
    if(maxSum > max_val):
        max_val = maxSum
        best_arr = brr

for i in best_arr:
    print i,