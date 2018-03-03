#include <bits/stdc++.h>
using namespace std;


int max(int arr[], int n) 
{   
    map<int,int> diffMap;
    
    int count0 = 0;
    int count1 = 0;

    diffMap[0] = -1;

    int res = 0;
    for(int i = 0; i < n; i++)
    {

        if(arr[i] == 0)
            count0++;
        else    
            count1++;

        if( diffMap.find(count1 - count0) != diffMap.end() )
        {
            res = max(res,i - diffMap[count1-count0]);
        }
        else
        {
            diffMap[count1-count0] = i;
        }

    }
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << max(arr,n) << endl;

    return 0;
}
