#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int n,m;
    cin>>n>>m;
    int i,j;
    vector<string> cells(n);
    for(i=0;i<n;i++)
    {
        cin>>cells[i];
    }
    int p1=0,p2=0,p3=0;
    int count=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(cells[i][j]=='G')
            {

                if(i+1<n && i-1>=0 && j+1<m &&j-1>=0)
                {
                        if(cells[i+1][j]=='G' && cells[i-1][j]=='G'&& cells[i][j-1]=='G' && cells[i][j+1]=='G')
                        {
    
                            if(i+2<n && i-2>=0 && j+2<m &&j-2>=0)
                            {
                                if(cells[i+2][j]=='G' && cells[i-2][j]=='G'&& cells[i][j-2]=='G' && cells[i][j+2]=='G')
                                {
                                    p3++;
                                    cout<<i<<"\t"<<j<<"\n";
                                    
                                }
                                else
                                {
                                    p2++;
                                    cout<<i<<"\t"<<j<<"\n";
                                }   
                            }
                            else
                            {
                                p2++;
                                cout<<i<<"\t"<<j<<"\n";
                            } 
                        }   
                }
            }
        }
    }
    cout<<p1<<"\t"<<p2<<"\t"<<p3;
    // cout<<"\nGood State\n";
    // for(i=0;i<n;i++)
    // {
    //     for(j=0;j<m;j++)
    //     {
    //         if(cells[i][j]=='B')
    //         {
    //             cout<<" ";
    //         }
    //         else   
    //             cout<<".";
    //     }
    //     cout<<"\n";
    // }

    return 0;
}
