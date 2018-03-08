#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    ofstream file;
    file.open("input.txt",ios::app);

    set<pair<int,int>> edges;

    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            edges.insert(make_pair(i,j));
        }
    }

    set<pair<int,int>> edgeSet;
    edgeSet.insert(*(edges.begin()));

    m = min(m,n*(n-1)/2);

    while(edgeSet.size() < m)
    {
        int random = rand()%(edges.size());
        pair<int,int> val = *next(edges.begin(),random);
        edgeSet.insert(val);
    }
    file << n << " " << m << endl;
    for(auto it : edgeSet)
    {
        cout << it.first << " " << it.second << endl;
        file << it.first << " " << it.second << endl;
    }

    return 0;
}