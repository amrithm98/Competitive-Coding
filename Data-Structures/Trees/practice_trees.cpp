#include<iostream>
#include<queue>

using namespace std;

struct Tree
{
    int data;
    struct Tree *left,*right;
};

struct Tree *newNode(int data)
{
    struct Tree *node=(struct Tree *)malloc(sizeof(struct Tree));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}
struct Tree *search_node(struct Tree *root,int val)
{
    if(root==NULL || val==root->data)
        return root;
    else if(val<root->data)
        return search_node(root->left,val);
    else if(val>root->data)
        search_node(root->right,val);
}
struct Tree *insert_node(struct Tree *root,int data)
{
    if(root==NULL)
        return newNode(data);
    else if(data<root->data)
        root->left=insert_node(root->left,data);
    else if(data>root->data)
        root->right=insert_node(root->right,data);

    return root;
}

void inOrder(Tree *root)
{
    if(root==NULL)
        return;
    inOrder(root->left);
    cout<<root->data<<"\t";
    inOrder(root->right);
}

int getHeight(struct Tree*root)
{
    if(root==NULL)
        return -1;
    else
    {
        int left_max=1+getHeight(root->left);
        int right_max=1+getHeight(root->right);
        return max(left_max,right_max);
    }
    
}

void printLevelOrder(struct Tree *root)
{
    if(root==NULL)
        return;
    else
    {
        queue<struct Tree*> nodeQ;
        nodeQ.push(root);
        while(1)
        {
            int count=nodeQ.size();
            if(count==0)
                break;

            while(count>0)
            {
                struct Tree *node=nodeQ.front();
                nodeQ.pop();
                cout<<node->data<<"\t";
                if(node->left!=NULL)
                {
                    nodeQ.push(node->left);
                }
                if(node->right!=NULL)
                {
                    nodeQ.push(node->right);
                }
                count--;
            }
            
            cout<<"\n";
        }
        
    }
}

int main()
{
    struct Tree *root=NULL,*temp=NULL;
    cout<<"\nLearn Tree: ";
    int ch;
    int num;
    while(1)
    {
        cout<<"\n1. Insert";
        cout<<"\n2. Search";
        cout<<"\n3. Delete";
        cout<<"\n4. Find Height";
        cout<<"\n5. Balance";
        cout<<"\n6. InOrder";
        cout<<"\n7. PreOrder";
        cout<<"\n8. PostOrder";
        cout<<"\n9. Level-Order";
        cout<<"\nEnter Current Choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"\nEnter Value: ";
                cin>>num;
                if(root==NULL)
                    root=newNode(num);
                else
                    insert_node(root,num);
                break;
            case 2:
                cout<<"\nEnter Search Value: ";
                cin>>num;
                temp=search_node(root,num);
                if(temp==NULL)
                    cout<<"\nElement Not Found";
                else    
                    cout<<"\nElement Found";
                break;
            case 3:
                break;
            case 4:
                cout<<"\nHeight of the BST is: "<<getHeight(root);
                break;
            case 5:
                break;
            case 6:
                inOrder(root);
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                printLevelOrder(root);
                break;
        }
    }

}