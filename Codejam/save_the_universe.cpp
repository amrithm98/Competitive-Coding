#include <bits/stdc++.h>
using namespace std;

#define LL long long int


LL currDamage(string &P)
{
    LL damage = 0;
    LL charge = 1;

    for(int i = 0; i < P.size(); i++)
    {
        if(P[i] == 'S')
        {
            damage += charge;
        }
        else
        {
            charge = (charge<<1);
        }
    }

    return damage;
}

LL swapsNeeded(string &P,LL d)
{
    bool swapPos = true;
    LL swapNeed = 0;

    LL damage = currDamage(P);

    while(damage > d && swapPos)
    {
        swapPos = false;

        for(int i = P.size()-1; i > 0; i--)
        {
            if(P[i] == 'S' && P[i-1] == 'C')
            {
                char t= P[i];
                P[i] = P[i-1];
                P[i-1] = t;

                swapPos = true;
                break;
            }
        }

        damage = currDamage(P);
        swapNeed++;
    }

    if(swapPos)
        return swapNeed;
    else
        return -1;
}

int main()
{

        ios_base::sync_with_stdio(false);

        int t;
        cin >> t;

        int cnt = 1;

        while(t--)
        {
            string P;
            LL d;
            cin >> d >> P;

            LL ans = swapsNeeded(P,d);
            cout << "Case #" << cnt << ": ";

            if(ans == -1)
                cout << "IMPOSSIBLE";
            else
                cout << ans;

            cout << "\n";
            cnt++;
        }

        return 0;
}