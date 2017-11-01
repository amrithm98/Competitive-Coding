#include <bits/stdc++.h>

#define MAX 100010
#define INF 1LL*10000000000000

using namespace std;

long long capacity[MAX],weight[MAX],count_cake[MAX];
int n,m;

bool eatable(long long mid)
{
    long long int newVect[2*MAX];
    int i;
    for(i = 2*MAX -1 ; i >= 0; i--)
        newVect[i] = 0;

    for(i = 1; i <= m ; i++)
    {
        newVect[capacity[i]] -= mid;
    }

    for(i = 1; i <= n ; i++)
    {
        newVect[weight[i]] += count_cake[i];
    }
    long long sum = 0;
    for( i = 2*MAX-1; i >=0; i--)
    {
        sum += newVect[i];
        if(sum > 0 )
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int i,j;
        cin >> n >> m;
        map<long long,long long> commonMap;
        for(i = 1; i <= m ; i++)
        {
            cin >> capacity[i];
            commonMap[capacity[i]];
        }
        
        for(i = 1; i <= n ; i++)
        {
            cin >> weight[i];
            commonMap[weight[i]];
        }
        
        for(i = 1; i <= n ; i++)
        {
            cin >> count_cake[i];
        }

        int cnt = 1;

        for(auto it : commonMap)
        {
            commonMap[it.first] = cnt++;
        }

        for(i = 1; i <= m ; i++)
            capacity[i] = commonMap[capacity[i]];
        
        for(i = 1; i <= n ; i++)
            weight[i] = commonMap[weight[i]];
        
        long long beg = 1,end = INF;
        long long ans = -1;
        while(beg <= end)
        {
            long long mid = (beg + end)/2;
            if(eatable(mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                beg = mid + 1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
