#include <bits/stdc++.h>
using namespace std;

void Leaders(int* arr,int len)
{
	/* Don't write main().
	 * Don't read input, it is passed as function argument.
	 * Print your output exactly in the same format as shown. 
	 * Don't print any extra line.
	*/
    vector<int> st;

    int max = arr[len-1];

    st.push_back(max);

    for(int i = len-2; i >= 0; i--)
    {
        if(arr[i] >= max)
        {
            max = arr[i];
            st.push_back(max);
        }
    }
    for(int i = st.size()-1; i >= 0; i--)
        cout << st[i] << " ";
    
}


int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Leaders(arr,n);

    return 0;
}