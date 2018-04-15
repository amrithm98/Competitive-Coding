#include <bits/stdc++.h>
using namespace std;

vector<double> v(10),p(10),c(10);
vector<int> d(10);

double minTime(int n,int s,int y)
{
    double depTime,crossTime,minTime = 0;
    crossTime = ((double)y/s);

    double s1,e1,s2,e2,s3,e3;

    for(int i = 0; i < n; i++)
    {
        depTime = -( ( p[i]-( (double)c[i]*d[i] ) )/v[i]);

        s1 = p[i];
        e1 = p[i] -(c[i]*d[i]);

        s2 = s1 + v[i]*minTime;
        e2 = e1 + v[i]*minTime;
        
        s3 = s1 + v[i]*(minTime + crossTime);
        e3 = e1 + v[i]*(minTime + crossTime);

        if(s2 < 0 && e2 < 0 && s3 < 0 && e3 < 0 && abs(max(max(max(s3,e3),s2),e2)) > 0.000001)
            minTime += crossTime;

        else if(s2 > 0 && e2 > 0 && s3 > 0 && e3 > 0 && abs(min(min(min(s3,e3),e2),s2)) > 0.000001)
            minTime += crossTime;
        
        else
            minTime = (depTime+crossTime);
    }

    return minTime;
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,s,y;
        cin >> n >> s >> y;

        v.clear();
        d.clear();
        p.clear();
        c.clear();

        for(int i = 0; i < n; i++)
            cin >> v[i];

        for(int i = 0; i < n; i++)
        {
            cin >> d[i];
            if(d[i] == 0)
            {
                d[i] = -1;
                v[i] *= -1;
            }
        }

        for(int i = 0; i < n; i++)
            cin >> p[i];
        
        for(int i = 0; i < n; i++)
            cin >> c[i];

        cout << fixed << setprecision(6) << minTime(n,s,y) << endl;

    }

    return 0;
}