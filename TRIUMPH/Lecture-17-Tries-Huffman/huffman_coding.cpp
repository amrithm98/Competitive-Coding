/**
 * 
 * 
 * Author : Amrith M
 * 
 * 
 **/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
    public:
    char data;
    int freq;
    TrieNode *left,*right;

    TrieNode(char ch,int f)
    {
        data = ch;
        freq = f;
        left = right = NULL;
    }
};

struct Comp
{
    bool operator () (const TrieNode *A, const TrieNode *B) const
    {
        return A->freq > B->freq;
    }
};

void dfs(TrieNode* root, string s, map<char,string> &huffman)
{
    if(root == NULL)
        return ;

    if(root->left == NULL && root->right == NULL)
    {
        huffman[root->data] = s;
        return;
    }

    dfs(root->left,s + "0",huffman);
    dfs(root->right,s + "1",huffman);
}

string decodeHuffman(string s, TrieNode* root)
{
    TrieNode* temp = root;
    int n = s.size();
    int i = 0;

    string res = "";

    while(i < n)
    {
        if(s[i] == '0')
        {
            temp = temp->left;
        }
        else if(s[i] == '1')
        {
            temp = temp->right;
        }

        if(temp->left == NULL && temp->right == NULL)
        {
            res += temp->data;
            temp = root;
        }

        i++;
    }

    return res;
}

int main()
{
    map<char,int> freq;
    priority_queue<TrieNode* , vector<TrieNode*> , Comp > pq;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        char x;
        int c;
        cin >> x >> c;
        freq[x] = c;

        TrieNode* node = new TrieNode(x,c);
        pq.push(node);
    }

    TrieNode *root;

    while(pq.size() > 1)
    {
        TrieNode* n1 = pq.top();
        pq.pop();
        TrieNode* n2 = pq.top();
        pq.pop();

        TrieNode* internal = new TrieNode('\0',n1->freq + n2->freq);
        internal->left = n1;
        internal->right = n2;

        pq.push(internal);
    }

    root = pq.top();
    pq.pop();

    map<char,string> huffmanCodes;
    dfs(root,"",huffmanCodes);

    cout << "\nHUFFMAN CODES \n============\n";
    for(auto it : huffmanCodes)
    {
        cout << it.first << " " << it.second << endl;
    }

    string str;
    cout << "\nEnter A String to Decode : ";
    cin >> str;

    cout << "\nThe decoding is : " << decodeHuffman(str,root) << endl;

    return 0;
}

/*****
6
a 5
b 9
c 12
d 13
e 16
f 45

HUFFMAN CODES
============
a 1100
b 1101
c 100
d 101
e 111
f 0

Enter A String to Decode : 11001001000111

The decoding is : accfe

****/