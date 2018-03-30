#include <bits/stdc++.h>
using namespace std;

int partition(int input[],int start,int end)
{
  	int x = input[start];
  	int n_e = 0;
  
  	for(int i = start+1; i <= end; i++)
    {
      	if(input[i] < x)
          n_e++;
    }
  	//cout << start << " " << end << " " << n_e << endl;
  	swap(input[start],input[start+n_e]);
  	int i = start,j = end;
  	while(i < start+n_e && j > start + n_e)
    {
      	if(input[i] < x)
        {
          	i++;
        }
      	else if(input[j] >= x)
        {
          	j--;
        }
      	else
        {
          	swap(input[i],input[j]);
          	i++;
          	j--;
        }
    }
  	return start+n_e;
}

void qs(int input[],int start,int end)
{
  	if(start < end)
    {
      	int p = partition(input,start,end);
      	qs(input,start,p-1);
      	qs(input,p+1,end);
    }
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
  	qs(input,0,size-1);

}

int main()
{
    int n;
    cin >> n;
    int input[n];
    for(int i = 0; i < n; i++)
        cin >> input[i];

    return 0;
}
