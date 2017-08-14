#include<stdio.h>
void sort(int a[2][2],int r,int c);
int main()
{
	int i,j;
	int a[2][2];
	a[0][0]=12;
	a[0][1]=1;
	a[1][0]=2;
	a[1][1]=11;
	sort(a,2,2);
	return 0;
	
}
void sort(int a[2][2],int r,int c)
{
	int b[4];
	int i,j,k=0;
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
		{
			b[k]=a[i][j];
			k++;
		}
	for(i=0;i<4;i++)
		for(j=0;j<4-i;j++)
		{
			if(b[j]>b[j+1])
			{
				int t=b[j];	
				b[j]=b[j+1];
				b[j+1]=t;
			}
		}
	printf("Solve:");
	for(i=0;i<4;i++)
		printf("\t%d",b[i]);
}
