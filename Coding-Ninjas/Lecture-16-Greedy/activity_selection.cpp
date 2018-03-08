#include<bits/stdc++.h>
using namespace std;
#define LL unsigned long long int

struct Activity
{
    LL start;
    LL end;
};

bool operator <(Activity a,Activity b)
{
    if(a.end == b.end)
    {
        return a.start < b.start;
    }
    return a.end < b.end;
}

int main()
{
    //Write your code here
    int n;
    cin >> n;

    Activity *act = new Activity[n];
    for(int i = 0; i < n; i++)
        cin >> act[i].start >> act[i].end;

    sort(act,act+n);

    int cnt = 1;
    Activity prev = act[0];

    for(int i = 1; i < n; i++)
    {
        if(prev.end <= act[i].start)
        {
            cnt++;
            prev = act[i];
        }
    }

    cout << cnt << endl;
    
    return 0;
}