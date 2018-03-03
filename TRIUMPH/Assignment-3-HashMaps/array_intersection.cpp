#include<bits/stdc++.h>
using namespace std;

void intersection(int input1[], int input2[], int size1, int size2) 
{
    unordered_map<int,int> cm1,cm2;

    for(int i = 0; i < size1; i++)
    {
        cm1[input1[i]]++;
    }

    for(int i = 0; i < size2; i++)
    {
        cm2[input2[i]]++;
    }

    for(auto it : cm1)
    {
        if(cm2.find(it.first) != cm2.end())
        {
            int freq = min(cm1[it.first],cm2[it.first]);
            for(int i = 0; i < freq; i++)
                cout << it.first << endl;
        }
    }
}

int main()
{
    int n,m;
    cin >> n;

    int *arr = new int[n];
    int *brr = new int[m];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> m;

    for(int i = 0; i < m; i++)
        cin >> brr[i];

    intersection(arr,brr,n,m);

    return 0;
}
