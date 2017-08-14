flag=False
w = raw_input().strip()
vowels=['a','e','i','o','u','y']
for i in range(0,len(w)-1):
        if(w[i]==w[i+1]):
#	    print w[i]
            flag=True
            break
        elif (w[i] in vowels):
            if(w[i+1] in vowels):
                flag=True
                break
if(flag==True):
    print "No"
else:
    print "Yes"
