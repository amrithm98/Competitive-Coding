#coding=utf8
with open("test.txt",'w',encoding='utf-8') as f:
    f.write("my first line\n")
    f.write("This file\n\n")
    f.write("contains three lines\n")
    f.write("Cooperate")

with open("test.txt",'r',encoding='utf-8') as f:
    for line in f:
        print(line)