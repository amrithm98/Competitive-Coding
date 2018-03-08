#include<bits/stdc++.h>
using namespace std;

#define LL unsigned long long int 
#define MOD 4294967296
int main()
{
    LL n,m,a,b;

    cin >> n >> m;
    cin >> a >> b;

    int i = 0;

    LL xi,xj;
    xi = 0;
  
    LL best = -1;
    LL maxProfit = 0;

    for(int i = 0; i < n; i++)
    {
      	xj = ( ((xi%m)*a) + b)%MOD;
        LL currCost = xj/(1<<8);
        xi = xj;
      
        if(best >= 0 && best < currCost)
        {
            maxProfit += (currCost - best);
        }
        best = currCost;
    }

    cout << maxProfit << endl;
    return 0;
}