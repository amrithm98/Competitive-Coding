#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

struct DisjSet
{
    int parent;
    int rank;
};

int find(DisjSet *ds, int x)
{
    if(ds[x].parent != x)
        return find(ds,ds[x].parent);
    else
        return x;
}

void Union(DisjSet *ds, int x, int y)
{
    int rootX = find(ds,x);
    int rootY = find(ds,y);

    if(ds[rootX].rank < ds[rootY].rank)
    {
        ds[rootX].parent = rootY;
    }
    else if(ds[rootX].rank > ds[rootY].rank)
    {
        ds[rootY].parent = rootX;
    }
    else
    {
        ds[rootX].parent = rootY;
        ds[rootY].rank++;
    }
}

bool isUnion(DisjSet *ds, int x, int y)
{
    return find(ds,x) == find(ds,y);
}

long long zFunction(int n,int k)
{
    DisjSet *djset = new DisjSet[n+2];
    for(int i = 0; i <= n; i++)
    {
        djset[i].parent = 0;
        djset[i].rank = 0;
    }

    long long ans = 0;

    for(int i = 1; i < n; i++)
    {
        long long s;
        for(int j = 1; j < (1 << (n-i)); j++)
        {
            s = -1;

            for(int l = 0; l < n; l++)
            {
                djset[l].parent = l;
                djset[l].rank = 0;
            }

            for(int k = 1; k <= n-i; k++)
            {
                if(j & ( 1 << k-1))
                {
                    s*=-1;
                    for(int l = 0; l < i; l++)
                    {
                        if(!isUnion(djset,l,k+l))
                            Union(djset,l,k+l);
                    }

                }
            }
            if (s < 0)
                s += 1000000007;
            for(int m = 0; m < n; m++)
            {
                if(find(djset,m) == m)
                    s = 1LL*(s*k)%MOD;
            }
            ans  = (ans + s)%MOD;
        }
    }
    return ans;
}

int main()
{
    int n,m;
    cin >> n >> m;

    cout << zFunction(n,m) << endl;
    return 0;
}