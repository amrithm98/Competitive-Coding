#include <bits/stdc++.h>
using namespace std;

long solve(long n) {
    // Complete this function
    int zeros=0;
    long temp=n;
    while(temp!=0)
    {
        if(temp%2==0)
            zeros++;
        temp/=2;
    }

    return pow(2,zeros);
}

int main() {
    long n;
    cin >> n;
    long result = solve(n);
    cout << result << endl;
    return 0;
}
