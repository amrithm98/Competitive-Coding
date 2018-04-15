#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int a,b,c,id
};

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    unordered_map<string,int> idMap;


    int id = 0;
    for(int i = 0; i < k; i++)
    {
        string s;
        int a,b,c;
        cin >> a >> b >> c >> s;

        if(idMap[s] == idMap.end())
            idMap[s] = id++;

        
    }
}