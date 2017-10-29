#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int *men,*cost;

int minimum(int a,int b, int c)
{   
    return min(min(a,b),c);
}

int findMinCost(int i,int *battlemen,int n)
{
    if( i == n)
    {
        return 0;
    }
    int smallOutput1 = cost[i]+findMinCost(i+1,battlemen,n);

    battlemen[2] += men[i];
    int smallOutput2 = 2*cost[i] + findMinCost(i+1,battlemen,n);
    battlemen[2] -= men[i];

    int smallOutput3 = max(smallOutput1,smallOutput2);
    // int battles = accumulate(battlemen.begin(),battlemen.end(),0);
    int battles = 0;
    for(int k = 0; k < 3 ; k++)
        battles += battlemen[k];
    
    if(battles > men[i])
    {
        int temp[3];
        temp[0] = battlemen[0];
        temp[1] = battlemen[1];
        temp[2] = battlemen[2];

        int j;
        battles = men[i];
        for( j = 0; j < 3 ; j++)
        {
            if(battles > 0)
            {
                if(battles >= battlemen[j])
                {
                    battles -= battlemen[j];
                    battlemen[j] = 0;
                }
                else if( battles < battlemen[j])
                {
                    battlemen[j] -= battles;
                    battles = 0;
                }
            }
            
        }

        battlemen[0] = battlemen[1];
        battlemen[1] = battlemen[2];
        battlemen[2] = 0;

        smallOutput3 = findMinCost(i+1,battlemen,n);
        
        battlemen[0] = temp[0];
        battlemen[1] = temp[1];
        battlemen[2] = temp[2];
    }

    return minimum(smallOutput1,smallOutput2,smallOutput3);
}

int minCost(int n)
{
    int battleMen[3];
    for(int i = 0; i < 3; i++)
        battleMen[i] = 0;
    
    return findMinCost(0,battleMen,n);
}

int main()
{
    int n;
    cin >> n;
    men = new int[n];
    cost = new int[n];
    for(int i = 0; i < n ; i++)
    {
        cin >> men[i] >> cost[i];        
    }
    cout<<minCost(n)<<endl;
    return 0;
}
