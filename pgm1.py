n = int(raw_input().strip())
height = map(int,raw_input().strip().split(' '))
Max=height[0]
for i in range(0,len(height)-1):
    if height[i]>Max:
        Max=height[i]
count=0
for i in range(0,len(height)):
    if height[i]==Max:
        count+=1
print count
