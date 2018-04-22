#include <bits/stdc++.h>
using namespace std;

struct Node
{
    double x,v;
};

bool compare(Node a,Node b)
{
    if(a.x == b.x)
        return a.v < b.v;
    else
        return a.x < b.x;
};

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        vector<Node> stud(n);

        for(int i = 0; i < n; i++)
        {
            double a,b;
            cin >> a >> b;
            stud[i] = {a,b};
        }

        sort(stud.begin(),stud.end(),compare);


        if(n < 3)
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            double maxTime = -1;
            for(int i = 0; i < n; i++)
            {
                for(int j = i+1; j < n; j++)
                {
                    if(stud[i].v != stud[j].v)
                    {
                        double currTime = abs((stud[i].x-stud[j].x)/(stud[i].v-stud[j].v));
                        maxTime = max(maxTime,currTime);
                    }
                }
            }
            cout << fixed << setprecision(6) << maxTime << endl;
        }
    }

    return 0;
}