import copy
q = int(raw_input().strip())
for k in xrange(q):
    n = int(raw_input().strip())
    a = map(int, raw_input().strip().split(' '))
    org=copy.copy(a)
    length=len(a)-1
    a=sorted(a)
    # for i in range(0,length):
    #     for j in range(0,length-i):
    #         if(a[j]>a[j+1]):
    #             temp=a[j]
    #             a[j]=a[j+1]
    #             a[j+1]=temp
    for i in range(0,length):
        for j in range(0,length-i):
            if(abs(org[j]-org[j+1])==1):
                if(org[j]>org[j+1]):
                    temp=org[j]
                    org[j]=org[j+1]
                    org[j+1]=temp
    if(a==org):
        print "Yes"
    else:
        print "No"