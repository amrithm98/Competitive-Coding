#include <bits/stdc++.h>
using namespace std;


class TrieNode
{
    public:    
    TrieNode *left,*right;
};

void insert(int n,TrieNode *root)
{
    TrieNode *curr = root;

    for(int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if(!bit)
        {
            if(curr->left == NULL)
            {
                curr->left = new TrieNode();
            }
            curr = curr->left;
        }
        else
        {
            if(curr->right == NULL)
            {
                curr->right = new TrieNode();
            }
            curr = curr->right;
        }
    }
}

int findMaxXorPair(int *arr,int n,TrieNode *root)
{
    int maxXor = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        int value = arr[i];
        int currMax = 0;
        TrieNode *curr = root;
        
        for(int j = 31; j >= 0; j--)
        {
            int bit = (value>>j)&1;
            if(!bit)
            {
                if(curr->right == NULL)
                {
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                    currMax += (1 << j);
                }
            }
            else
            {
                if(curr->left == NULL)
                {
                    curr = curr->right;
                }
                else
                {
                    curr = curr->left;
                    currMax += (1 << j);
                }
            }

            maxXor = max(maxXor,currMax);
        }
    }

    return maxXor;
}

int main()
{
    int arr[] = {8,1,2,5,10,15};

    TrieNode *root = new TrieNode();
    for(int i = 0; i < 6; i++)
    {
        insert(arr[i],root);
    }

    cout << findMaxXorPair(arr,6,root) << endl;

    return 0;
}