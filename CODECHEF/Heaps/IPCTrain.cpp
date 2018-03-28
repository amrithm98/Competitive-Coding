#include<bits/stdc++.h>
using namespace std;

struct Lect
{
    int tr;
    int day;
    int sad;
};

bool compare(Lect l1,Lect l2)
{
    return l1.sad > l2.sad;
}

int main()
{

    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)
    {
        int n,d;
        cin >> n >> d;
        Lect *lec = new Lect[n];
        for(int i = 0; i < n; i++)
        {
            cin >> lec[i].day >> lec[i].tr >> lec[i].sad;
        }
        sort(lec,lec+n,compare);
        
        

    }   

    return 0; 
}