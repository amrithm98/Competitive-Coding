#include <bits/stdc++.h>
using namespace std;
struct Task
{
    int order;
    int t;
    int k;
};

bool compare(Task a,Task b)
{
    if(a.order == b.order)
        return a.t < b.t;
    
    return a.order < b.order;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q;
    cin >> n >> q;
    
    int *arr = new int[n+1];
    for(int i = 1; i <= n; i++)
        arr[i] = 0;
    
    Task *query = new Task[q];
    
    for(int i = 0; i < q; i++)
    {
        cin >> query[i].order >> query[i].k >> query[i].t;
    }

    sort(query,query+q,compare);

    long long int currTime, sum, count, dur,prevTime = 0;

    for(int i = 0; i < q; i++)
    {
        sum = 0;
        count = 0;
        currTime = query[i].order;
        dur = currTime - prevTime;

        for(int j = 1; j <= n; j++)
        {
            arr[j] = max(0LL,arr[j] - dur);
            if(arr[j] == 0)
            {
                count++;
            }
        }

        if(count >= query[i].k)
        {
            int needed = query[i].k;

            int j = 1;
            while(needed)
            {
                if(arr[j] == 0)
                {
                    arr[j] += query[i].t;
                    sum += j;
                    needed--;
                }
                j++;
            }
            cout << sum << endl;
        }
        else
        {
            cout << -1 << endl;
        }

        prevTime = currTime;
    }

    return 0;
}
