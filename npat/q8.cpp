#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
void mostFreq3(int *a, int n, int b[3]) {
    int i=0;
    unordered_map<int,int> countMap;
    int countMap[n][2];
    for(i=0;i<n;i++)
    {
        countMap[a[i]]=0;
    }
    for(i=0;i<n;i++)
    {
        countMap[a[i]]+=1;
    }
    int first=a[0];
    for(int i=1;i<n;i++)
    {
        if(countMap[a[i]]>countMap[first])
        {
            first=a[i];
        }
    }
    int second=-1;
    for (int i = 0; i < n ; i++)
        if (countMap[a[i]] > countMap[second] && countMap[a[i]] < countMap[first])
            second = a[i];
 
    int third = -1;
    for (int i = 0; i < n ; i++)
        if (countMap[a[i]] > countMap[third] && countMap[a[i]] < countMap[second])
            third = a[i];
 
    b[0]=first;
    b[1]=second;
    b[2]=third;
}
int main()
{
	int n;
	int a[100];
	int b[3];
	int i=0;

	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}

	mostFreq3(a,n,b);
    for(i=0; i<3; i++)
        cout << b[i] << " ";
	return 0;
}