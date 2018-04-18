#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Treenode
{   
    public:
    T data;
    vector<Treenode*> children;

    Treenode(T data)
    {
        this->data = data;
    }
};

void printTree(Treenode<int> *root)
{
    cout << root->data << ":";
    for(int i = 0; i < root->children.size(); i++)
        cout << root->children[i]->data << " ";
    cout << endl;
    for(int i = 0; i < root->children.size(); i++)
        printTree(root->children[i]);
}

Treenode<int> *takeInput()
{
    int n,rootdata;

    cout << "\nEnter RootData: ";
    cin >> rootdata;

    Treenode<int> *root = new Treenode<int>(rootdata);
    cout << "\nEnter No. of Children: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        Treenode<int> *child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

int main()
{
    Treenode<int> *root = takeInput();
    printTree(root);
    
    return 0;
}