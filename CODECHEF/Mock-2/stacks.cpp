#include <bits/stdc++.h>
using namespace std;

#define LL long long int

int binSearch(vector<LL> input,LL num, int start, int end)
{
    int mid;
    int ans = end;
    while(start <= end)
    {
        mid = (start + end)/2;
        if(input[mid] > num)
        {
            ans = mid;
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return ans;
}

int main()
{

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<LL> tops(n);
        vector<LL> input(n);

        for(int i = 0; i < n; i++)
            cin >> input[i];

        int size = 0;

        for(int i = 0; i < n; i++)
        {
            int index = upper_bound(tops.begin(),tops.begin()+size,input[i]) - tops.begin();
            tops[index] = input[i];
            if(index == size)
                size++;
        }

        cout << size << " ";
        for(int i = 0; i < size; i++)
        {
            cout << tops[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
