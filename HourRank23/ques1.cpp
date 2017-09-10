#include <bits/stdc++.h>

using namespace std;

int howManyGames(int p, int d, int m, int s) {
    // Return the number of games you can buy
    int answer=0;
     if(s>=p) 
     {
           while(s >=0 && p >=m) 
           {
               s -= p;
               p -= d;
               answer++;
           }
           while(s >= m) 
           {
               s -= m;
               answer++;
           }
        return answer;
       }
       else return 0;
}

int main() {
    int p;
    int d;
    int m;
    int s;
    cin >> p >> d >> m >> s;
    int answer = howManyGames(p, d, m, s);
    cout << answer << endl;
    return 0;
}
