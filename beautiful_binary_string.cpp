#include <bits/stdc++.h>

using namespace std;

int minSteps(int n, string B){
    // Complete this function
    int count=0;
    for(int i=0;i<B.size()-2;i++)
    {
        if(B[i]=='0' && B[i+1]=='1' && B[i+2]=='0')
        {
            count++;
            i=i+2;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    string B;
    cin >> B;
    int result = minSteps(n, B);
    cout << result << endl;
    return 0;
}
