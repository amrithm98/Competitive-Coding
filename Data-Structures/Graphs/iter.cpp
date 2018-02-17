#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> graph;
    vector<int> g;

    g.push_back(1);
    g.push_back(2);
    g.push_back(13);

    graph.push_back(g);
    g.clear();

    g.push_back(13);
    graph.push_back(g);


    vector<vector<int>>::iterator it;
    vector<int>::iterator it1;

    for(it = graph.begin(); it != graph.end(); it++)
    {
        for(it1 = (*it).begin(); it1 != (*it).end(); it1++)
        {
            cout << *it1 << " ";
        }
        cout << endl;
    }

    for(auto it2 : graph)
    {
        for(auto it3 : it2)
        {
            cout << it3 << " ";
        }
        cout << endl;
    }



}