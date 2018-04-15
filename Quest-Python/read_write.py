import pickle

class Stud:
    def __init__(self,n,name,m):
        self.__num = n
        self.__name = name
        self.__marks = m

    def __str__(self):
        return str(self.__num) + " " + self.__name + " " + str(self.__marks)

data = list()

for i in range(2):
    num = int(input("Enter Number: "))
    name = input("Enter Name: ")
    marks = int(input("Enter Marks: "))
    c = Stud(num,name,marks)

    data.append(c)

fh = open("stud.pickle","wb")

for i in data:
    pickle.dump(i,fh)

fh.close()

fg = open("stud.pickle","rb")
data2 = list()

while(True):
    try:
        c = pickle.load(fg)
        data2.append(c)
    except EOFError:
        break

print(data2)