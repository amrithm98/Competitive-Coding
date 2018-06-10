#include <bits/stdc++.h>

using namespace std;

vector<int> parent(45);
vector<int> t(45,0);

int c1 = 0 , c2 = 0;

struct Team{   
    long long f;
    set<int> s;
};

vector<Team> teams;


long long getPossible(int m){
    
    long long res = 0;
    
    for(int i = 0 ; i < m ; i++){
        
        bool t1 = false , t2 = false;
        
        for(auto it : teams[i].s)
            if(t[it] == 1)
                t1 = true;
            else if(t[it] == 2)
                t2 = true;
        
        if(t1 && t2)
            continue;
        else
            res += teams[i].f;
    }
    
    return res;
}

void maxEf(int i , long long &curMax , int m ,int n){
    
    if(i == n){
        
        if(c1 > 0 && c2 > 0)
            curMax = max(curMax , getPossible(m));
        return;
    }
    
    if(getPossible(m) <= curMax)
        return;
    
    t[i] = 1;
    c1++;
    maxEf(i+1 , curMax , m , n);
    
    c1--;
    c2++;
    t[i] = 2;
    maxEf(i+1 , curMax , m , n);
    
}

long long maximumEfficiency(int n, int m) {
    
    
    vector<long long> impact(45,0);
    int sz , x, y , z;
    long long f , tot = 0;
    
    for(int i = 0 ; i < m ; i++){
        
        cin >> sz >> f >> x >> y;
        
            impact[x] += f;
            impact[y] += f;
                
        if(sz == 3){
            cin >> z;
            impact[z] += f;
            teams.push_back({f,{x,y,z}});
        }
        
        else
            teams.push_back({f,{x,y}});
        
        tot += f;
        
    }
    
    long long minimp = LLONG_MAX;
    
    for(int i = 1 ; i <= n ; i++)
        minimp = min (impact[i] , minimp);
    
    
    long long curMax = tot-minimp;

    maxEf(1,curMax,m,n);

    return curMax;
}

int main()
{
    int n,m;
    cin >> n >> m;
    
    cout << maximumEfficiency(n,m) << endl;
    
    return 0;
}
