#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n;
    vector<int> scores(n);
    vector<int> ranks(n);
    ranks[0]=1;
    for(int i=0;i<n;i++)
        cin>>scores[i];
    for(size_t i=1;i<n;i++)    
    {
        if(scores[i]==scores[i-1])
        {
            ranks[i]=ranks[i-1];
            continue;
        }
        ranks[i]=ranks[i-1]+1;
    }
    ranks.push_back(ranks[n-1]+1);

    cin>>m;
    vector<int> alice(m);

    int currentRank=ranks[n];
    int currentIndex=n-1;
    for(int i=0;i<m;i++)
        cin>>alice[i];
    for(int i=0;i<m;i++)
    {
        int item=alice[i];
        while(currentIndex>=0 && item>scores[currentIndex])
        {
            --currentIndex;
        }
        if(scores[currentIndex]==item){
            cout<<ranks[currentIndex];
        }
        else if(scores[currentIndex]>item)
        {
            cout<<ranks[currentIndex]+1;
        }
        else
            cout<<1;
        cout<<"\n";
    }    
    return 0;
}