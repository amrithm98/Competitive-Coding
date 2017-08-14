n=input()
for i in range(n):
    sweet,wrap = raw_input().strip().split()
    sweet,wrap=[int(sweet),int(wrap)]
    last=1+sweet+wrap/7;
    print(last)
