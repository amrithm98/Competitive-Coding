#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node* left, * right;
};

void topView(node * root) 
{
    if(root==NULL)
        return;
    
    unordered_map<int,int> m;
    queue<pair<node *,int>> que;
    
    que.push(make_pair(root,0));
    
    while(!que.empty())
    {
        pair<node*,int> p=que.front();
        node* n=p.first;
        int val=p.second;
        que.pop();
        
        if(m.find(val)==m.end())
        {
            m[val]=n->data;
            cout<<n->data<<" ";
        }
        if(n->left!=NULL)
            que.push(make_pair(n->left,val-1));
        if(n->right!=NULL)
            que.push(make_pair(n->right,val+1));
    }
  
}

int main()
{
    return 0;
}
