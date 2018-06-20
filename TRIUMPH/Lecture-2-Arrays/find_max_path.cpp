#include <iostream>
using namespace std;

long maxPathSum(int ar1[], int ar2[], int m, int n)
{
    /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
     */
    long maxSum = 0;
    long s1 = 0,s2 = 0;
    int i=0,j=0;

    while(i < m && j < n)
    {
        if(ar1[i] == ar2[j])
        {
            s1 += ar1[i];
            s2 += ar2[j];
            maxSum += max(s1,s2);
            s1 = 0;
            s2 = 0;
            i++;
            j++;
        }
        else if(ar1[i] < ar2[j])
        {
            s1 += ar1[i];
            i++;
        }
        else if(ar2[j] < ar1[i])
        {
            s2 += ar2[j];
            j++;
        }
    }

    while(i < m)
    {
        s1 += ar1[i++];
    }

    while(j < n)
    {
        s2 += ar2[j++];
    }

    maxSum += max(s1,s2);

    return maxSum;
    
}

int main()
{
    int m,n;
    cin >> m;

    int ar1[m];
    for(int i = 0; i < m; i++)
        cin >> ar1[i];

    cin >> n;
    int ar2[n];
    for(int i = 0; i < n; i++)
        cin >> ar2[i];

    cout << maxPathSum(ar1,ar2,m,n) << endl;
}
