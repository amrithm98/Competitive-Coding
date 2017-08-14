#include <bits/stdc++.h>

using namespace std;

bool isPatterinGrid(vector<string> &G,vector<string> &P,int R,int C,int r,int c)
{
    int i=0,j=0,k=0,l=0;
    bool flag;
    for(i=0;i<=R-r;i++)
    {
        for(j=0;j<=C-c;j++)
        {
            flag=false;
            for(k=0;k<r;k++)
            {
                for(l=0;l<c;l++)
                {
                    if(G[i+k][j+l]!=P[k][l])
                    {
                        flag=true;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            if(!flag)
                return true;
        }
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0; G_i < R; G_i++)
        {
           cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0; P_i < r; P_i++)
        {
           cin >> P[P_i];
        }
        if(isPatterinGrid(G,P,R,C,r,c))
        {
            cout<<"YES"<<"\n";
        }
        else
        {
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}
