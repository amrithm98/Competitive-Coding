#include<bits/stdc++.h>

using namespace std;

bool a[100][100];
int i,j;

void zero()
{

    for(int i = 0 ; i<100 ; i++)
        for(int j = 0 ; j < 100 ; j++)
            a[i][j] = 0;
}

void getNext(int &x , int &y){

    int m = 0 , t;
    int mi,mj;

    for(int p = 6 ; p < 4+i && m < 8; p++)
    {
        for(int q = 6 ; q < 4+j && m < 8; q++)
        {

            t = 9 -( (int)a[p][q] + a[p][q+1] + a[p][q-1] + a[p+1][q] + a[p+1][q+1] + a[p+1][q-1] + a[p-1][q] + a[p-1][q+1] + a[p-1][q-1]);
            if(m < t ){

                m = t;
                mi = p;
                mj = q;
            }
        }
    }

    x = mi;
    y = mj;

}

int main(){

    int t , A , sz , x , y , p , q;
    bool  flag;

    cin >> t;

    while(t--){

        zero();

        cin >> A;

        if(A == 20)
        {
            i = 4; j = 5;
        }
        else
        {
            i = 10 ; j = 20;
        }

        flag = true;

        int m = 0;

        x = 6 ; y = 6;

        while(m < 1000 && flag){

            cout << x << " " << y << endl;

            cin >> p >> q;

            if(p == -1)
                return 0;

            else if( p == 0)
                flag = false;

            else if(a[p][q] == 0){

                    a[p][q] = 1;
                    getNext(x,y);
            }

            m++;
           
        }

        if(m == 1000 && flag)
            return 0;  

    }
    return 0;
}