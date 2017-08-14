#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<algorithm>
#include<unordered_map>
using namespace std;
void mostFreq3(int *a, int n, int b[3]) {
    int i=0;
    unordered_map<int,int> countMap;
    for(i=0;i<n;i++)
    {
        countMap[a[i]]+=1;
    }
    for(auto it:countMap)
    {
        cout<<it.first<<"\t"<<it.second;
    }
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