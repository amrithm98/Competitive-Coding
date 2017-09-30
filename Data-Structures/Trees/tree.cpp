#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Tree 
{
    int data;
    struct Tree *left,*right;
};

struct Tree *newNode(int data)
{
    struct Tree *node=(struct Tree*)malloc(sizeof(struct Tree));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

void insert_tree(struct Tree *head,int data)
{

    queue<struct Tree*> nodeQueue;
    nodeQueue.push(head);
    while(!nodeQueue.empty())
    {
        struct Tree *node=nodeQueue.front();
        nodeQueue.pop();
        if(!node->left)
        {
            node->left=newNode(data);
            return;
        }
        else
        {
            nodeQueue.push(node->left);
        }

        if(!node->right)
        {
            node->right=newNode(data);
            return;
        }
        else
        {
            nodeQueue.push(node->right);
        }
    }
}

struct Tree* insert_bst(struct Tree *root,int data)
{
    if(root==NULL)
        return newNode(data);
    else if(data<root->data)
        root->left=insert_bst(root->left,data);
    else if(data>root->data)
        root->right=insert_bst(root->right,data);
    
    return root;
}

void inOrder(struct Tree *root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<"\n"<<root->data;
    inOrder(root->right);
}

int main()
{
    struct Tree *root=NULL;
    int ch,n;
    while(1)
    {
        cout<<"\n1. Insert";
        cout<<"\n2. InOrder";
        cout<<"\nEnter Your Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter Node Value: ";
                cin>>n;
                if(root==NULL)
                    root=newNode(n);
                else
                    insert_bst(root,n);
                break;
            case 2:
                cout<<"\nInorder: \n-----------";
                inOrder(root);
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
