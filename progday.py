#!/bin/python

import sys

def solve(year):
    # Complete this function
    leap=0
    year_list_cum=12*[0]
    if(year<1918):
        if (year%4==0):
            leap=1
    elif year>1918:
        if (year%400==0) or (year%4==0 and year%100!=0):
            leap=1
    else:
        return "26.09.1918" 
    if leap:
        year_list=[31,29,31,30,31,30,31,31,30,31,30,31]
        for i in range(12):
            year_list_cum[i]=sum(year_list[:i+1])
        days_left=256-year_list_cum[7]
        String=str(days_left)+".09."+str(year)
        return String
    else:
        year_list=[31,28,31,30,31,30,31,31,30,31,30,31]
        for i in range(12):
            year_list_cum[i]=sum(year_list[:i+1])
        days_left=256-year_list_cum[7]
        String=str(days_left)+".09."+str(year)
        return String

year = int(raw_input().strip())
result = solve(year)
print(result)
