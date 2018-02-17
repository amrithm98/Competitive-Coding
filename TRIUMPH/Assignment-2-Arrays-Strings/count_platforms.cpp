#include <bits/stdc++.h>
using namespace std;


int platformsNeeded(int arrival[], int departure[], int n) {
    /*
     * Don't write main().
     * Don't read input, it is passed as function argument.
     * Don't print anything just return integer value.
     */
    sort(arrival,arrival+n);
    sort(departure,departure+n);

    int i = 0;
    int j = 0;
    int max_count = -1;
    int platformCount = 0;

    while(i < n && j < n)
    {
        if(arrival[i] <= departure[j])
        {
            platformCount++;
            i++;
        }
        else
        {
            platformCount--;
            j++;
        }
        if(platformCount > max_count)
        {
            max_count = platformCount;
        } 
    }
    return max_count;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    int *dept = new int[n];

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        cin >> dept[i];
    }

    cout << platformsNeeded(arr,dept,n) << endl;
    return 0;
}