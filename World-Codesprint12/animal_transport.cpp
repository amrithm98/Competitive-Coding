#include <bits/stdc++.h>

using namespace std;

bool isPossible(char a,char b)
{
    if((a == 'D' && b =='E') || (a =='E' && b == 'D'))
    {   
        return false;
    }
    else if((a == 'C' && b =='D') || (a == 'D' && b =='C'))
    {   
        return false;
    }
    else if((a == 'M' && b =='C') || (a == 'C' && b =='M'))
    {   
        return false;
    }
    else if((a == 'E' && b =='M') || (a == 'M' && b =='E'))
    {   
        return false;
    }
    else
    {
        return true;
    }
}


vector <int> minimumZooNumbers(int m, int n, vector <char> t, vector <int> s, vector <int> d) {
    // Return a list of length n consisting of the answers
    vector<int> sol(m);
    int min = INT8_MAX,source_i=-1,dest_i = -1;
    for(int i = 0; i < n; i++)
        if(d[i] < min)
        {
            min = d[i];
            dest_i = i;
        }
    sol[0] = min;
    for(int i = 1; i < m; i++)
    {
        
    }
    

}

int main() {
    int cases;
    cin >> cases;
    for(int a0 = 0; a0 < cases; a0++){
        int m;
        int n;
        cin >> m >> n;
        vector<char> t(n);
        for(int t_i = 0; t_i < n; t_i++){
           cin >> t[t_i];
        }
        vector<int> s(n);
        for(int s_i = 0; s_i < n; s_i++){
           cin >> s[s_i];
        }
        vector<int> d(n);
        for(int d_i = 0; d_i < n; d_i++){
           cin >> d[d_i];
        }
        vector <int> result = minimumZooNumbers(m, n, t, s, d);
        for (ssize_t i = 0; i < result.size(); i++) {
            cout << result[i] << (i != result.size() - 1 ? " " : "");
        }
        cout << endl;


    }
    return 0;
}
