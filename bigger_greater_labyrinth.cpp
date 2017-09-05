    #include <cmath>
    #include <cstdio>
    #include <vector>
    #include <iostream>
    #include <algorithm>

    using namespace std;

    string next_permutation_str(string s)
    {
        int index=s.size()-2;
        while(index>=0 && s[index]>=s[index+1])
        {
            index--;
        }
        if(index<0)
            return "no answer";
        int nextIndex=index+1;
        while(nextIndex+1<s.size() && s[nextIndex+1]>s[index])
        {
            nextIndex++;
        }
        swap(s[index],s[nextIndex]);
        reverse(s.begin()+index+1,s.end());
        return s;

    }
    int main() 
    {
        int t;
        cin>>t;
        for(int a=0;a<t;a++)
        {
            string s;
            string res;
            int i=0,j=0;
            cin>>s;
            res=next_permutation_str(s);
            cout<<res<<"\n";
            // bool val = next_permutation(s.begin(), s.end());
            // if (val == false)
            //     cout << "no word" << endl;
            // else
            //     cout<<s<<"\n";
        }
        return 0;
    }
