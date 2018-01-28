#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left,*right;
};

Node *newNode(int val)
{
    Node *n = new Node;
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

void insert(Node *root,int val)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node *n = q.front();
        q.pop();

        if(n->left != NULL)
        {
            q.push(n->left);
        }
        else
        {
            n->left = newNode(val);
            break;
        }

        if(n->right != NULL)
        {
            q.push(n->right);
        }
        else
        {
            n->right = newNode(val);
            break;
        }
    }
}

void inOrderStack(Node *head)
{
    stack<Node *> st;
    Node *curr = head;
    bool comp = false;
    while(!comp)
    {
        if(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if(!st.empty())
            {
                Node *p = st.top();
                st.pop();
                cout << p->data << " ";
                curr = p->right;
            }
            else
            {
                comp = true;
            }
        }
    }
}

void inOrder(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    Node *root = NULL;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if(root == NULL)
        {
            root = newNode(val);
        }
        else
        {
             insert(root,val);
        }
    }    
    inOrder(root);
    cout << endl;
    inOrderStack(root);
    return 0;
}