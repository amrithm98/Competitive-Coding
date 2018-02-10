#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<map>

using namespace std;
/*
void print_subsets(int * arr, int n, string s = string(""))
{
    if(n == 0)
    {
        cout<<s<<endl;
        return;
    }
    print_subsets(arr+1, n-1, s+to_string(arr[0])+string(" "));
    print_subsets(arr+1, n-1, s);
    return;
}
*/

int main ()
{
    string a, b;
    cin>>a;
    cin>>b;
    map<char, int> ma, mb;
    string::iterator it;
    map<char, int>::iterator mit;
    for(it = a.begin(); it != a.end(); it++)
    {
        ma[(*it)]++;
    }
    for(it = b.begin(); it != b.end(); it++)
    {
        mb[(*it)]++;
    }
    int u = 1;
 //   cout<<"String a is "<<a<<" and string b is "<<b<<endl;
    if(ma.size() == mb.size())
    {
        u = 0;
        for(mit = ma.begin(); mit != ma.end(); mit++)
        {
            if(mb[mit->first] != ma[mit->first])
            {
  //              cout<<"For character "<<(mit->first)<<" both are not equal"<<endl;
                u = 1;
                break;
            }
        }
    }
    if(u != 0)
    cout<<"False"<<endl;
    else
    cout<<"True";
}