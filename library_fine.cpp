#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int d1;
    int m1;
    int y1;
    cin >> d1 >> m1 >> y1;
    int d2;
    int m2;
    int y2;
    cin >> d2 >> m2 >> y2;
    int fine=0;
    int diff_d=d1-d2;
    int diff_m=m1-m2;
    int diff_y=y1-y2;
    if(diff_d>0 && diff_m==0 && diff_y==0)
        fine=15*diff_d;
    else if(diff_m>0 && diff_y==0)
        fine=500*diff_m;
    else if(diff_y>0)
        fine=10000;
    cout<<fine<<"\n";
    return 0;
}
