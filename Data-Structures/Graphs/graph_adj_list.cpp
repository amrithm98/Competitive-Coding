#include <bits/stdc++.h>
using namespace std;

int main()
{
    int V,E;
    cin >> V >> E;
    int matrix[V][V];

    vector<int> *graph = new vector<int>[V];
    for(int i = 0; i < E; i++)
    {
        int a,b;
        cin >> a >> b;

        graph[b].push_back(a);
        graph[a].push_back(b);
    }
    cout << "\nGRaph is : \n";
    for(int i = 0; i < V; i++)
    {
        cout << i << " : ";
        for(int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}