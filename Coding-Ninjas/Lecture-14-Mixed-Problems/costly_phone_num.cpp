#include<bits/stdc++.h>
using namespace std;

void findMinCost(int *arr)
{
	bool change = true;
  	while(change)
    {
      	change = false;
      	for(int i = 0; i < 10; i++)
        {
          	for(int j = 0; j < 10; j++)
            {
              	int c = (i+j)%10;
              	if(arr[c] > arr[i]+arr[j])
                {
                  	arr[c] = arr[i]+arr[j];
                  	change = true;
				}
            }
		}
    }
 
}

int main()
{
    //Write your code here
  	int t;
  	cin >> t;
  	while(t--)
    {
      	int *arr = new int[10];
		for(int i = 0; i < 10; i++)
          	cin >> arr[i];
      
      	int numC;
      	cin >> numC;
      	
     	string num;
      	cin >> num;
      
      	findMinCost(arr);
      	int cnt = 0;
      	for(int i = 0; i < numC; i++)
        {
          	cnt += arr[num[i]-'0'];
        }
      	cout << cnt << endl;
	}
    return 0;
}