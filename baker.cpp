#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
using namespace std;
 
int n,m,i,j,k,a,b,c,dd,c0,d0;
int d[1005];
 
int main()
{
    cin>>n>>m>>c0>>d0;
    for(i=c0;i<=n;i++)
        d[i]=i/c0*d0;
    for(i=1;i<=m;i++)
    {
    	cin>>a>>b>>c>>dd;
    	for(j=1;j<=a/b;j++)
    	    for(k=n;k>=c;k--)
    	        d[k]=max(d[k],d[k-c]+dd);
	}
	cout<<d[n];
	return 0;
}