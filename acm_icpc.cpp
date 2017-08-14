#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<bitset<500>> topic(n);
    for(int topic_i = 0;topic_i < n;topic_i++){
       cin >> topic[topic_i];
    }
    vector<vector<int>> matrix(n,vector<int>(n));
    int max=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
               matrix[i][j]=0;
               continue;
            }
            matrix[i][j]=(topic[i] | topic[j]).count();
            if(matrix[i][j]>max)
            {
                max=matrix[i][j];
            }
        }
    }
    int max_count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[i][j]==max)
                max_count++;
        }
    }
    cout<<max;
    cout<<"\n"<<max_count/2;
    return 0;
}
