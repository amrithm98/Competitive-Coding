#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

vector<vector<pair<int,int>>> components;
vector<long long int> fact(1000001);

void factModM()
{
    fact[0] = 1;
    for(int i = 1; i <= 1000001; i++)
    {
        fact[i] = (fact[i-1]*i)%MOD;
    }
}

bool isValid(int x,int y,int n,int m)
{
    if( x >= 0 && x < n && y >= 0 && y < m)
        return true;
    else
        return false;
}

void BFS(int **graph,int x,int y,vector<pair<int,int>> &comp,bool **visited,int n,int m)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y] = true;

    int x_move[] = {2,2,-2,-2,1,1,-1,-1};
    int y_move[] = {-1,1,1,-1,2,-2,2,-2};

    while(!q.empty())
    {
        pair<int,int> node = q.front();
        // cout << endl;
        // cout << node.first << " " << node.second << endl;
        comp.push_back(node);
        q.pop();
        for(int i = 0; i < 8; i++)
        {
            int next_x = node.first + x_move[i];
            int next_y = node.second + y_move[i];

            if(isValid(next_x,next_y,n,m) && !visited[next_x][next_y] && graph[next_x][next_y])
            {
                visited[next_x][next_y] = true;
                q.push(make_pair(next_x,next_y));
            }
        }

    }
}

long long int possiblePlacements(int **graph,int n,int m)
{
    bool **visited = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for(int j = 0;j < m; j++)
            visited[i][j] = false;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[i][j] && graph[i][j])
            {
                // cout << "\nCALLED " << i << " " << j <<endl;
                vector<pair<int,int>> comp;
                BFS(graph,i,j,comp,visited,n,m);
                components.push_back(comp);
            }
        }
    }

    long long int ans = 1;
    // cout << "\nComponents: " << components.size() << endl;
    for(int i = 0; i < components.size(); i++)
    {
        int size = components[i].size();
        // cout << size << " ";
        ans = ( (ans%MOD) * (fact[size]) % MOD)%MOD;
    }
    return ans;
}

int main()
{
	//code
    int t;
    cin >> t;
    factModM();

    while(t--)
    {
        int n,m,q;
        cin >> n >> m >> q;

        int **graph = new int*[n];
        components.clear();

        for(int i = 0; i < n; i++)
        {
            graph[i] = new int[m];
            for(int j = 0; j < m; j++)
                graph[i][j] = 0;
        }

        for(int i = 0; i < q; i++)
        {
            int a,b;
            cin >> a >> b;
            graph[a-1][b-1] = 1;
        }

        cout << possiblePlacements(graph,n,m) << endl;
    }
	return 0;
}
