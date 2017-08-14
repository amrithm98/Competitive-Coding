n, k = map(int, raw_input().split())
x, y = map(int,raw_input().split())
d={'u':n-x,'d':x-1,'l':y-1,'r':n-y,'ur':min(n-x,n-y),'ul':min(n-x,y-1),'dr':min(x-1,n-y),'dl':min(x-1,y-1)}
max_attack = sum(d.values())
temp = {i:0 for i in d.keys()}
for i in range(k):
    a, b = map(int, raw_input().split())
    a, b = a-x, b-y
    if (a==0):
        if (b > 0):
            losing = d['r'] - b + 1
            if (temp['r'] < losing):
                max_attack = max_attack + temp['r'] - losing
                temp['r'] = losing
        if (b < 0):
            b = abs(b)
            losing = d['l'] - b + 1
            if (temp['l'] < losing):
                max_attack = max_attack + temp['l'] - losing
                temp['l'] = losing
    elif (b==0):
        if (a > 0):
            losing = d['u'] - a + 1
            if (temp['u'] < losing):
                max_attack = max_attack + temp['u'] - losing
                temp['u'] = losing
        if (a < 0):
            a = abs(a)
            losing = d['d'] - a + 1
            if (temp['d'] < losing):
                max_attack = max_attack + temp['d'] - losing
                temp['d'] = losing
    elif (abs(a) == abs(b)):
        if (a>0 and b>0):
            losing = d['ur'] - a + 1
            if (temp['ur'] < losing):
                max_attack = max_attack + temp['ur'] - losing
                temp['ur'] = losing
        elif (a>0 and b<0):
            losing = d['ul'] - a + 1
            if (temp['ul'] < losing):
                max_attack = max_attack + temp['ul'] - losing
                temp['ul'] = losing
        elif (a<0 and b>0):
            losing = d['dr'] - b + 1
            if (temp['dr'] < losing):
                max_attack = max_attack + temp['dr'] - losing
                temp['dr'] = losing
        elif (a<0 and b<0):
            a = abs(a)
            losing = d['dl'] - a + 1
            if (temp['dl'] < losing):
                max_attack = max_attack + temp['dl'] - losing
                temp['dl'] = losing
print max_attack