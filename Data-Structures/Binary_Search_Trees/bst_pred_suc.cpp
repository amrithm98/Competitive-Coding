#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *left,*right;
};

node* insert(node *root,int value)
{
    if(root == NULL)
    {
        node *newNode = (node *)malloc(sizeof(node));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else if(value < root->data)
    {
        root->left = insert(root->left,value);
    }
    else if(value > root->data)
    {
        root->right = insert(root->right,value);
    }

    return root;
}

void findPredSuc(node *root,node* &pred,node* &succ,int data)
{
    if(root == NULL)
    {
        return ;
    }

    if(root->data == data)
    {
        //Pred
        if(root->left != NULL)
        {
            node *temp = root->left;
            while(temp->right != NULL)
            {
                temp = temp->right;
            }
            pred = temp;
        }
        
        if(root->right != NULL)
        {
            node *temp = root->right;
            while(temp->left != NULL)
            {
                temp = temp->left;
            }
            succ = temp;
        }        

        return;
    }

    if(data < root->data)
    {
        succ = root;
        findPredSuc(root->left,pred,succ,data);
    }
    else
    {
        pred = root;
        findPredSuc(root->right,pred,succ,data);
    }
}

int main()
{
    int n,data;
    cin >> n;
    node *root = NULL;
    cout<<"Enter n elements: ";
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        root = insert(root,val);
    }
    cout<<"\nEnter Key to find Pred & SUCC: ";
    cin >> data;

    node *pred,*succ;
    findPredSuc(root,pred,succ,data);
    if(pred)
    {
        cout<<"\nPredecessor: "<<pred->data;
    }
    else
    {
        cout<<"\nNo Pred";
    }
    if(succ)
    {
        cout<<"\nSuccecessor: "<<succ->data;
    }
    else
    {
        cout<<"\nNo Succ";
    }
}