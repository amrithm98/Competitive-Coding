#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
        int n;
		float p,q;
		cin >> p >> q >> n;

		int coin_hrs = abs(ceil((12*q)/(float)(p-q)));
        // cout << "\nCH: " << coin_hrs << endl;
        if(coin_hrs % 12 == 0)
        {
            cout << ((n-1)*coin_hrs)/24 +1 << endl;
        }
        else
        {
            cout << ceil((n*coin_hrs)/24) << endl;
        }
	}
	return 0;
}