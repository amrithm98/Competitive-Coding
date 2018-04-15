#include<bits/stdc++.h>

using namespace std;

struct node{

    long long val , cur;
    int idx;
}a[100005];

bool operator <(node a , node b){

    if(a.val == b.val)
        return a.idx < b.idx;
    
    return a.val > b.val;
}

long long sTree[400005];
long long sTree1[400005];


void buildTree(int root , int start, int end){

    if(start == end){
        sTree[root] = a[start].val;
        sTree1[root] = a[start].cur;
        return;
    }
    int mid = (start+end)/2;

    buildTree(2*root+1 , start , mid);
    buildTree(2*root+2 , mid+1 , end);

    sTree[root] = max(sTree[2*root+1] , sTree[2*root+2]);
    sTree1[root] = min(sTree1[2*root+1] , sTree1[2*root+2]);
}

void printTree(int n)
{
    cout << "\nTREE: \n";

    for(int i = 0; i < 2*n; i++)
        cout << sTree[i] << " ";

    cout << endl;

    for(int i = 0; i < 2*n; i++)
        cout << sTree1[i] << " ";

}

long long query(int root , int start , int end , int i , int j){

    if(i > end || j < start)
        return 0;
    
    if(i <= start && j >= end)
        return sTree[root];

    int  mid = (start+end)/2;
 
    return max(query(2*root+1,start,mid,i,j) , query(2*root+2,mid+1,end,i,j));
}

long long query1(int root , int start , int end , int i , int j){

    if(i > end || j < start)
        return LLONG_MAX;
    
    if(i <= start && j >= end)
        return sTree1[root];

    int  mid = (start+end)/2;
 
    return min(query1(2*root+1,start,mid,i,j) , query1(2*root+2,mid+1,end,i,j));
}

int minCut(int n){

    buildTree(0,0,n-1);
    sort(a,a+n);

    int c = 0 , i = 0;

    while(i < n){

        if(a[i].val == a[i].cur){

            i++;
            continue;
        }

        int j = i+1;
        int cc = 1;

        while(j < n && a[j].val == a[i].val ){

            long long bg = query(0 , 0, n -1 , a[j-1].idx , a[j].idx);
            long long sm = query1(0 , 0, n -1 , a[j-1].idx , a[j].idx);
            cout << bg << " " << sm << endl;
            if(bg > a[i].val || sm < a[i].val){

                if(cc > 0)
                    c++;
                cc = 0;
            }

            if(a[j].val != a[j].cur)
                cc++;

            j++;
        }

        if(cc > 0)
            c++;

        i = j;
    }

    return c;
}

int main(){

    int t , n;

    cin >> t;

    while(t--){

        cin >> n;

        bool f = false;

        for(int i = 0 ; i < n ; i++)
            cin >> a[i].cur;

        for(int i = 0 ; i < n ; i++){

            cin >> a[i].val;

            if(a[i].cur < a[i].val)
                f = true;

            a[i].idx = i;

        }

        if(f){

            cout << -1 << endl;
            continue;
        }

        cout  << "minCut " << minCut(n) << endl;
    }

    return 0;
}