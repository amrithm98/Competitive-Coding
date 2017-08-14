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
    int n;
    int k;
    int i,j;
    cin >> n >> k;
    int rQueen;
    int cQueen;
    cin >> rQueen >> cQueen;
    string index[]={"left","right","up","down","topright","bottomright","topleft","bottomleft"};
    map<string,tuple<int,int>> paths;
    for(int a0 = 0; a0 < k; a0++){
        int rObstacle;
        int cObstacle;
        cin >> rObstacle >> cObstacle;
        // your code goes here
    }
    for(i=cQueen+1;i<=n;i++)
    {
        paths["right"].insert(tuple<int,int>(rQueen,i));
    }
    // for(i=cQueen-1;i>=1;i--)
    // {
    //     paths["left"].insert(pair<int,int>(rQueen,i));
    //     cout<<paths["left"][rQueen]<<"\t";
    // }
    // for(i=rQueen+1;i<=n;i++)
    // {
    //     paths["up"].insert(pair<int,int>(i,cQueen));
    // }
    // for(i=rQueen-1;i>=1;i--)
    // {
    //     paths["down"].insert(pair<int,int>(i,cQueen));
    // }
    for(i=0;i<4;i++)
    {
        string val=index[i];
        cout<<"\n"<<val<<"\n";
        tuple<int,int> mymap=paths[val];
        for(auto elem:mymap)
        {
            cout<<elem.first<<","<<elem.second<<"\t";
        }
    }
    return 0;
}
