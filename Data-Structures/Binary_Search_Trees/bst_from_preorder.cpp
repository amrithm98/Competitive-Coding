#include <bits/stdc++.h>
using namespace std;


struct node{
    int data;
    node *left,*right;
};

void inOrder(node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

node* buildTree(int *arr,int size,int *preIndex,int min,int max,int key)
{
    if(*preIndex >= size)
    {
        return NULL;
    }

    node *root = NULL;

    if(key > min && key < max)
    {
        root = (node *)malloc(sizeof(node));
        root->data = key;
        root->left = root->right = NULL;

        *preIndex = *preIndex + 1;

        if(*preIndex < size)
        {
            root->left = buildTree(arr,size,preIndex,min,key,arr[(*preIndex)]);
            root->right = buildTree(arr,size,preIndex,key,max,arr[(*preIndex)]);
        }

    }
    return root;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int preIndex = 0;

    node *root;
    root = buildTree(arr,n,&preIndex,INT_MIN,INT_MAX,arr[0]);

    cout<<"\nInOrder Traversal: ";
    inOrder(root);

    return 0;
}