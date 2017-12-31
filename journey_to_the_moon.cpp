#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#include <bits/stdc++.h>

using namespace std; // }}}

vector<long long> components;
long long ind;

void DFS(int **input,int n,int sv,bool *visited)
{
    ind++;
    visited[sv] = true;

    for(int i = 0; i < n; i++)
    {
        if(i == sv)
        {
            continue;
        }
        if(input[sv][i] == 1)
        {
            if(visited[i])
                continue;
            else
                DFS(input,n,i,visited);
        }
    }
}

void dfs_disc(int **input,int n)
{
    bool *visited = new bool[n];
    memset(visited,0,sizeof(visited));

    for(int i = 0; i < n ; i++)
    {
        ind = 0;
        if(!visited[i])
        {
            DFS(input,n,i,visited);

            if(ind != 0)
                components.push_back(ind);
        }
    }
}

int main()
{ 
    int N, I;
    cin >> N >> I;

    int **graph = new int*[N];
    for(int i = 0; i < N; i++)
        graph[i] = new int[N];
    
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
 
    dfs_disc(graph,N);
    
    long long res = 0;
    long long sum = 0;

    for(long long size : components)
    {
        res += sum*size;
        sum += size;
    }
    
    cout << res << endl;
    return 0;
}
