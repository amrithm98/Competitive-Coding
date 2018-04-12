#include<bits/stdc++.h>

using namespace std;

bool area[101][101];
int i,j;
    
int main()
{


    int t;
    cin >> t;

    while(t--)
    {
        int A;
        cin >> A;

        for(int i = 0; i < 100; i++)
        {
            for(int j = 0; j < 100; j++)
            {
                area[i][j] = 0;
            }
        }

        if(A == 20)
        {
            i = 4; 
            j = 5;
        }
        else
        {
            i = 10; 
            j = 20;
        }

        bool flag = true;
        int m = 0;

        int x = 6,y = 6;

        int r,c;

        while(m < 1000 && flag)
        {
            cout << x << " " << y << endl;

            cin >> r >> c;


            if(r == -1)
                return 0;

            else if(r == 0)
                flag = false;

            else if(area[r][c] == 0)
            {
                area[r][c] = 1;
                int l = 0,k;

                int pi,pj;

                for(int x = 6; x < 4+i && l < 8; x++)
                {
                    for(int y = 6; y < 4+j && l < 8; l++)
                    {
                        k = 9 -( (int)area[x][y] + area[x][y+1] + area[x][y-1] + area[x+1][y] + area[x+1][y+1] + area[x+1][y-1] + area[x-1][y] + area[x-1][y+1] + area[x-1][y-1]);
                        if(l < k)
                        {
                            l = k;
                            pi = x;
                            pj = y;
                        }
                   }
                }

                x = pi;
                y = pj;

            }

            m++;
        }

        if(m == 1000 && flag)
            return 0;
    }
    


}