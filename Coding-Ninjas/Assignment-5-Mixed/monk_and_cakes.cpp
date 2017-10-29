#include <bits/stdc++.h>
using namespace std;

int countMinumumTime(vector<int> capacity,vector<int> weight,vector<int> count,int n,int m)
{
    
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,m,i,j;
        cin >> n >> m;

        vector<int> capacity(m),weight(n),count(n);
        for(i = 0; i < m ; i++)
            cin >> capacity[i];
        for(i = 0; i < n ; i++)
            cin >> weight[i];
        for(i = 0; i < n ; i++)
            cin >> count[i];

        cout<<countMinumumTime(capacity,weight,count,n,m)<<endl;
        
        
    }
    return 0;
}
