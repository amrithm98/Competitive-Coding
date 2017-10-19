#include <iostream>
#include <vector>
using namespace std;

#define mod 1000000007

int balancedBTs_naive(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */
	if (h == 0 || h == 1)
        return 1;
    return balancedBTs_naive(h-1) * (2 *balancedBTs_naive(h-2) +
                              balancedBTs_naive(h-1));
}

int getTrees(vector<long> &tree,int h)
{
    if(tree[h-1] == 0)
        tree[h-1] = getTrees(tree,h-1);
    if(tree[h-2] == 0)
        tree[h-2] = getTrees(tree,h-2);
    
    tree[h] = ((((tree[h-1]%mod)*(tree[h-1]%mod))%mod) + (2*((tree[h-1]%mod)*(tree[h-2]%mod))%mod))%mod;
    return tree[h];
}

int balancedBTs(int h)
{
    vector<long> tree(h+1);
    tree[0] = 1;
    tree[1] = 1;

    int n = getTrees(tree,h);
    return n;
}

int main()
{
    int n;
    cin >> n;

    cout<<balancedBTs(n)<<endl;

}