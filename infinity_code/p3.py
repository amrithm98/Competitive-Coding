# Enter your code here. Read input from STDIN. Print output to STDOUT
num = input()
aliens = {}
dependant = {i : [] for i in range(1,num+1)}


def solve():

    for i in range(1,num+1):
        s = raw_input().split()
        if(s[1][0] == 'i'):
            aliens[i] = int(s[0][0])
        else:
            key = int(s[0][0])
            dependant[key] += [i]
    findTruth()

def findTruth():

    alien_keys = aliens.keys()
    new_alien_keys = [1]

    while(len(new_alien_keys) != 0):
        new_alien_keys = []
        for j in alien_keys:
            for m in dependant[j]:
                if (m not in alien_keys):
                    aliens[m] = aliens[j]
                    new_alien_keys += [m]
        alien_keys = new_alien_keys

    r = 0
    
    for m in aliens.keys():
        if(aliens[m] == num):
            r += 1
    truth_tellers = input()

    if(r > num - truth_tellers):
        print ("RUN!")
    else:
        print("Stay!")

solve()