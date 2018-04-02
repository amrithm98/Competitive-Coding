#include <bits/stdc++.h>
#define LL long long int
using namespace std;

//FInding overlaps using train logic

LL gridlandMetro(LL n, LL m, int k, vector < vector<LL> > track) {
    // Complete this function
    LL ans = n*m;
    unordered_map<LL, vector< pair< LL,LL > > > rangeMap;
    
    for(int i = 0; i < k; i++)
    {
        rangeMap[track[i][0]].push_back(make_pair(track[i][1],track[i][2]));
    }
    
    LL used = 0;
    for(auto it : rangeMap)
    {
        vector<pair<LL,LL>> rn = it.second;
        vector<pair<LL,bool>> overlap;
        for(int i = 0; i < rn.size(); i++)
        {
            overlap.push_back(make_pair(rn[i].first,0));
            overlap.push_back(make_pair(rn[i].second,1));
        }
        sort(overlap.begin(),overlap.end());
        LL interval = 0;
        LL start = overlap[0].first,end;
        for(int i = 0; i < overlap.size(); i++)
        {
            if(overlap[i].second == 1)
            {
                interval--;
            }
            else
            {
                interval++;
            }
            if(interval == 0)
            {
                end = overlap[i].first;
                //cout << start << " " << end << endl;
                used += end-start+1;
                start = overlap[i+1].first;
            }
        }
    }
    return ans-used;
}

int main() {
    LL n;
    LL m;
    int k;
    cin >> n >> m >> k;
    vector< vector<LL> > track(k,vector<LL>(3));
    for(int track_i = 0;track_i < k;track_i++){
       for(int track_j = 0;track_j < 3;track_j++){
          cin >> track[track_i][track_j];
       }
    }
    LL result = gridlandMetro(n, m, k, track);
    cout << result << endl;
    return 0;
}
