#include <bits/stdc++.h>
using namespace std;

int arr[30001];
int BIT[30001];
int last[1000001];

struct query
{
    int start,end,index;
}qr[200001];



bool operator < (query A,query B)
{
    return A.end < B.end;
}

void update(int index,int value,int n)
{
    for(; index <= n; index += index&(-index))
    {
        BIT[index] += value;
    }
}

int query(int index)
{
    int ans = 0;
    for(; index > 0; index -= index&(-index))
    {
        ans += BIT[index];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++)
    {
        cin >> qr[i].start >> qr[i].end;
        qr[i].index = i;
    }

    sort(qr,qr+q);

    memset(last,-1,sizeof(last));

    int total = 0;

    int k = 0;
    int ans[q];

    for(int i = 1; i <= n; i++)
    {
        if(last[arr[i]] != -1)
        {
            update(last[arr[i]],-1,n);
        }
        else
        {
            total++;
        }
        update(i,1,n);
        last[arr[i]] = i;

        while(k<q && qr[k].end == i)
        {
            ans[qr[k].index] = total - query(qr[k].start-1);
            k++;
        }
        
    }

    for(int i = 0; i < q; i++)
    {
        cout<< ans[i] <<endl;
    }


    return 0;
}