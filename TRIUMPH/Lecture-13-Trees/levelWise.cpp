#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
    public:
        T data;
        vector<TreeNode*> children;

        TreeNode(T data)
        {
            this->data = data;
        }
};

TreeNode<int>* inputLevelWise()
{
    TreeNode<int> *root = NULL;
    cout << "\nEnter Root Data: ";
    int n;
    cin >> n;
    root = new TreeNode<int>(n);

    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode<int> *front = q.front();
        q.pop();

        int c;
        cout << "\nEnter Number of Nodes of " << front->data << " : ";
        cin >> c;

        for(int i = 0; i < c; i++)
        {
            int x;
            cin >> x;

            TreeNode<int> *child = new TreeNode<int>(x);
            front->children.push_back(child);

            q.push(child);
        }
    }

    return root;
}

void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        TreeNode<int> *front = q.front();
        q.pop();

        cout << front->data << " : ";

        for(int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << " ";
            q.push(front->children[i]);
        }

        cout << endl;
    }
}

int main()
{
    TreeNode<int> *root = inputLevelWise();

    printLevelWise(root);

    return 0;
}