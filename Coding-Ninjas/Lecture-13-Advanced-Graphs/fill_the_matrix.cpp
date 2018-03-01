#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100001];

int main()
{
	//code
    int t;
    cin >> t;
    while(t--)
    {
        int n,q;
        cin >> n >> q;

        bool init_flag = false;

        for(int i = 0; i < n; i++)
        {
            cout << graph[i].clear();
        }

        for(int i = 0; i < q; i++)
        {
            int a,b,c;
            cin >> a >> b >> c;

            if(a == b && (c == 1))
            {
                init_flag = true;
            }

            
        }

        if(init_flag)
        {
            cout << "no" << endl;
        }


    }
	return 0;
}
