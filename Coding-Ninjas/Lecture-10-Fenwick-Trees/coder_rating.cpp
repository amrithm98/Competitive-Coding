#include <bits/stdc++.h>
using namespace std;

int BIT[100001];

struct coder
{
    int x,y,index;
};

bool operator < (coder A,coder B)
{
    if(A.x == B.x)
    {
        return A.y < B.y;
    }
    return A.x < B.x;
}

void update(int y)
{
    for(; y <= 10000; y += y&(-y))
    {
        BIT[y]++;
    }
}

int query(int y)
{
    int val = 0;
    for(; y >0; y -= y&(-y))
    {
        val += BIT[y];
    }
    return val;
}

int main()
{
    int n;
    cin >> n;

    coder *arr = new coder[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
        arr[i].index = i;
    }

    sort(arr,arr+n);

    // for(int i = 0; i < n; i++)
    // {
    //     cout<<arr[i].x<<" "<<arr[i].y<<endl;
    // }

    int *ans = new int[n];
    
    for(int i = 0; i < n; )
    {
        //Handle cases where x & y of 2 or more coders r same
        //Pending i update...Update same at once ..otherwise changing one would affect answer of second
        /**
         * Instead of Just writing this ...we're modifying
         * 
         * ans[arr[i].index] = query(arr[i].y);
         * update(arr[i].y);
         * 
         * 
         * 
         * */

        int endIndex = i;

        while(endIndex < n && arr[i].x == arr[endIndex].x && arr[i].y == arr[endIndex].y)
        {
            endIndex++;
        }

        for(int j = i; j < endIndex; j++)
        {
            //Getting same ans for all the same x & y pairs
            ans[arr[j].index] = query(arr[j].y);
        }

        for(int j = i; j < endIndex; j++)
        {
            //Updating at once
            update(arr[j].y);
        }

        i = endIndex;
    }

    for(int i = 0; i < n; i++)
    {
        cout<<ans[i]<<endl;
    }

    return 0;
}