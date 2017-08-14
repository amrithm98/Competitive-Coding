n,k=map(int,raw_input().split())
x,y=map(int,raw_input().split())
path_counts={'t':n-x,'b':x-1,'l':y-1,'r':n-y,'tr':min(n-x,n-y),'tl':min(n-x,y-1),'br':min(x-1,n-y),'bl':min(x-1,y-1)}
temp = {i:0 for i in path_counts.keys()}
max_attack=sum(path_counts.values())
# paths["t"]=[(a,y) for a in range(x+1,n+1)]
# paths["b"]=[(a,y) for a in range(x-1,0,-1)]
# paths["l"]=[(x,b) for b in range(y-1,0,-1)]
# paths["r"]=[(x,b) for b in range(x+1,n+1)]
# paths["tr"]=[]
# paths["tl"]=[]'
# paths["br"]=[]
# paths["bl"]=[]
# a=x
# b=y
# for i in range(min(n-x,n-y)):
#     a+=1
#     b+=1
#     paths["tr"]+=[(a,b)]
# a=x
# b=y
# for i in range(min(n-x,y-1)):
#     a+=1
#     b-=1
#     paths["tl"]+=[(a,b)]
# a=x
# b=y
# for i in range(min(x-1,y-1)):
#     a-=1
#     b-=1
#     paths["bl"]+=[(a,b)]
# a=x
# b=y
# for i in range(min(x-1,n-y)):
#     a-=1
#     b+=1
#     paths["br"]+=[(a,b)]
for m in range(k):
    p,q=map(int,raw_input().split())
    (diff_x,diff_y)=(p-x,q-y)
    if(diff_x==0):
        if(diff_y>0):
            losing = path_counts['r'] - diff_y + 1
            if (temp['r'] < losing):
                max_attack = max_attack + temp['r'] - losing
                temp['r'] = losing
        elif(diff_y<0):
            diff_y = abs(diff_y)
            losing = path_counts['l'] - diff_y + 1
            if (temp['l'] < losing):
                max_attack = max_attack + temp['l'] - losing
                temp['l'] = losing
    elif(diff_y==0):
        if (diff_x > 0):
            losing = path_counts['t'] - diff_x + 1
            if (temp['t'] < losing):
                max_attack = max_attack + temp['t'] - losing
                temp['t'] = losing
        if (diff_x < 0):
            diff_x = abs(diff_x)
            losing = path_counts['b'] - diff_x + 1
            if (temp['b'] < losing):
                max_attack = max_attack + temp['b'] - losing
                temp['b'] = losing
    elif(abs(diff_x)==abs(diff_y)):
        if (diff_x>0 and diff_y>0):
            losing = path_counts['tr'] - diff_x + 1
            if (temp['tr'] < losing):
                max_attack = max_attack + temp['tr'] - losing
                temp['tr'] = losing
        elif (diff_x>0 and diff_y<0):
            losing = path_counts['tl'] - diff_x + 1
            if (temp['tl'] < losing):
                max_attack = max_attack + temp['tl'] - losing
                temp['tl'] = losing
        elif (diff_x<0 and diff_y>0):
            losing = path_counts['br'] - diff_x + 1
            if (temp['br'] < losing):
                max_attack = max_attack + temp['br'] - losing
                temp['br'] = losing
        elif (diff_x<0 and diff_y<0):
            diff_x = abs(diff_x)
            losing = path_counts['bl'] - diff_x + 1
            if (temp['bl'] < losing):
                max_attack = max_attack + temp['bl'] - losing
                temp['bl'] = losing
    # if(diff_x==0 and diff_y!=0):
    #     if(diff_y>0):
    #         for (a,b) in paths["l"]:
    #             if(b<=q):
    #                 path_counts["l"]-=1
    #     else:
    #         for (a,b) in paths["r"]:
    #             if(b>=q):
    #                 path_counts["r"]-=1
    # if(diff_x!=0 and diff_y==0):
    #     if(diff_x>0):
    #         for (a,b) in paths["b"]:
    #             if(a<=p):
    #                 path_counts["b"]-=1
    #     else:
    #         for (a,b) in paths["t"]:
    #             if(a>=p):
    #                 path_counts["t"]-=1
    # else:
    #     if(diff_x>0 and diff_y>0):
    #         for (a,b) in paths["bl"]:
    #             if(a<=p and b<=q):
    #                 path_counts["bl"]-=1
    #     elif(diff_x>0 and diff_y<0):
    #         for (a,b) in paths["br"]:
    #             if(a<=p and b>=q):
    #                 path_counts["br"]-=1
            
    #     elif(diff_x<0 and diff_y>0):
    #         for (a,b) in paths["tl"]:
    #             if(a>=p and b<=q):
    #                 path_counts["tl"]-=1
    #     elif(diff_x<0 and diff_y<0):
    #         for (a,b) in paths["tr"]:
    #             if(a>=p and b>=q):
    #                 path_counts["tr"]-=1
print(max_attack)

