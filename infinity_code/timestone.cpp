#include <bits/stdc++.h>
using namespace std;


struct jump
{
    int s;
    int e;
};

bool compare(jump a, jump b)
{
    return a.s < b.s;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    int m,l;
    cin >> m;
    cin >> l;
    
    if(m == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    jump *arr = new jump[l];

    for(int i = 0; i < l; i++)
    {
        cin >> arr[i].s >> arr[i].e;
    }

    sort(arr,arr+l,compare);

    int count = 0;

    set<int> ans;

    vector<pair<int,int>> forward,backward;

    for(int i = 0; i < l; i++)
    {
        if(arr[i].s >= n && arr[i].e <= arr[i].s)
        {
            count++;
            ans.insert(arr[i].s);
            for(int j = 0; j < l; j++)
            {
                if(arr[j].s <= arr[i].s && arr[j].e >= arr[i].s)
                {
                    count--;
                }
            }
        }
    }

    if(count <= m)
    {
        for(auto it : ans)
        {
            cout << it << " ";
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
