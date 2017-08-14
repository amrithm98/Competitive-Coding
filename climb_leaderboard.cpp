#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    long n,i;
    cin >> n;
    vector<long> scores(n);
    for(long scores_i = 0;scores_i < n;scores_i++){
       cin >> scores[scores_i];
    }
    long m;
    cin >> m;
    vector<long> alice(m);
    for(long alice_i = 0;alice_i < m;alice_i++){
       cin >> alice[alice_i];
    }
    vector<long> score_with_alice(n+1);
    vector<long> alice_ranks_m(m);
    for(long j=0;j<m;j++)
    {   
        copy(scores.begin(),scores.end(),score_with_alice.begin());
        score_with_alice[n]=alice[j];
        sort(score_with_alice.begin(),score_with_alice.end(),greater<long>());
        vector<long> ranks(n+1);
        long scorePos=0;
        for(long k=0;k<n+1;k++)
        {
            if(score_with_alice[k]==alice[j])
            {
                scorePos=k;
            }
        }
        long start=score_with_alice[0];
        long rank=1;
        ranks[0]=rank;
        for(i=0;i<n+1;i++)
        {   
            if(score_with_alice[i]>score_with_alice[i+1])
            {
                rank++;
                ranks[i+1]=rank;
            }
            else if(score_with_alice[i]==score_with_alice[i+1])
            {
                ranks[i+1]=rank;
            }
        }
        cout<<ranks[scorePos]<<"\n";
        alice_ranks_m[i]=ranks[scorePos];
    }
    return 0;
}
