#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 100001

using namespace std;

node tree[4*MAX];

struct node
{
    long long int ans;
    int len;
    int arr[26];
};

void initialize(string s) 
{
    // This function is called once before all queries.
    long long int dp[MAX];
    for(int i = 0; i < s.size(); i++)
    {

    }
}

void buildTree(int start,int end,int treeNode,string s)
{
    if(start == end)
    {
        tree[treeNode].len = 1;
        tree[treeNode].ans = 1;
        arr[s[start]-'a']++;
        return ; 
    }

    int mid = (start + end)/2;
    buildTree(start,mid,2*treeNode,s);
    buildTree(mid+1,end,2*treeNode+1,s);

    tree[treeNode].len = tree[2*treeNode].len + tree[2*treeNode+1].len;

    for(int i = 0; i < 26; i++)
    {
        tree[treeNode].arr[i] = tree[2*treeNode].arr[i] + tree[2*treeNode+1].arr[i];
    }

    tree[treeNode].ans = 0;
    int odd = 0,even = 0;
    int unique = 0;

    for(int i = 0; i < n; i++)
    {
        if(tree[treeNode].arr[i] != 0)
        {
            if(tree[treeNode].arr[i] % 2 == 0)
            {
                odd++;
            }
            else
            {
                even++;
            }
            unique++;
        }
    }

    tree[treeNode].ans = min(unique,even);
}

long long int answerQuery(int l, int r) {
    // Return the answer for this query modulo 1000000007.  

    for(int i = l; i <= r; i++)
    {

    }
}

int main() {
    string s;
    cin >> s;
    initialize(s);
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int l;
        int r;
        cin >> l >> r;
        long long int result = answerQuery(l, r);
        cout << result << endl;
    }
    return 0;
}
