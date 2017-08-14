#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    int arr[t];
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        int sweet=n/c;
        int wrappers=sweet;
        while(wrappers>=m)
        {
            int temp=wrappers/m;
            wrappers=temp+(wrappers%m);
            sweet+=temp;
        }
        arr[a0]=sweet;
    }
    for(int i=0;i<t;i++)
        cout<<arr[i]<<"\n";
    return 0;
}
