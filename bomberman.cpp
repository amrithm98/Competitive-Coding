#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> after_3_seconds(vector<string> temp,int r,int c)
{
    int i,j;
    vector<string> grid(r);
    string val="O";
    for(i=0;i<c-1;i++)
    {
        val+="O";
    }
    for(i=0;i<r;i++)
        grid[i]=val;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(int(temp[i][j])==79)
            {
                grid[i][j]='.';

                if(i+1<r)
                {
                        grid[i+1][j]='.';
                }
                if(i-1>=0)
                {
                      grid[i-1][j]='.';
                }
                if(j+1<c)
                {
                    
                        grid[i][j+1]='.';
            
                }
                if(j-1>=0)
                {
                        grid[i][j-1]='.';
                }
            }
        }
    }
    return grid;
}

void display_grid(vector<string> vec,int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<vec[i][j];
        }
        cout<<"\n";
    }
}

void after_n_seconds(vector<string> grid,int n,int r,int c)
{
    vector<string> all_o_grid(r);
    string val="O";
    int i,j;
    for(i=0;i<c-1;i++)
    {
        val+="O";
    }
    for(i=0;i<r;i++)
        all_o_grid[i]=val;
    
    if(n==0 || n==1)
    {
        display_grid(grid,r,c);
    }
    else if(n==2 || n==4 || n==6)
    {
        display_grid(all_o_grid,r,c);
    }
    else if(n==3 || n==5)
    {   
        vector<string> detonate=after_3_seconds(grid,r,c);
        if(n==3)
        {
            display_grid(detonate,r,c);
        }
        else
        {
            display_grid(after_3_seconds(detonate,r,c),r,c);
        }
    }
    else
    {
        int curr=(n-3)%4+3;
        after_n_seconds(grid,curr,r,c);
    }
}

int main()
{
    int r,c,n,i,j,k;
    cin>>r>>c>>k;
    vector<string> grid(r);
    for(i=0;i<r;i++)
        cin>>grid[i];
  //  cout<<"\nANSWER:::\n";
    after_n_seconds(grid,k,r,c);
    return 0;
}
