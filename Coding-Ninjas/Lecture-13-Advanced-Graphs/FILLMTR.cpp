#include<bits/stdc++.h>
using namespace std;

struct Disj
{
  	int parent;
  	int rank;
};

vector<int> graph[100009];

int find(int child,Disj *dj)
{
  	if(dj[child].parent != child)
    {
      	dj[child].parent = find(dj[child].parent,dj);
    }
  	return dj[child].parent;
}

void Union(int x,int y,Disj *ds)
{
  	int rootX = find(x,ds);
    int rootY = find(y,ds);

  	if(rootX == rootY)
      	return;
  	
    if(ds[rootX].rank < ds[rootY].rank)
    {
        ds[rootX].parent = rootY;
    }
    else if(ds[rootX].rank > ds[rootY].rank)
    {
        ds[rootY].parent = rootX;
    }
    else
    {
        ds[rootX].parent = rootY;
        ds[rootY].rank++;
    }
}

bool isUnion(int x,int y, Disj *dj)
{
  	return find(x,dj) == find(y,dj);
}

void DFS(int sv,vector<bool> &visited,vector<int> &color,int currColor,bool &bip)
{
  	visited[sv] = true;
	color[sv] = currColor;
  	//cout << "\nVisited " << sv << " Color : " << currColor << endl;
  	for(auto it : graph[sv])
    {
      	if(visited[it])
        {
          	if(color[it] == currColor)
              	bip = false;   
          	continue;
        }
      	DFS(it,visited,color,1-currColor,bip);
    }
}

bool isBipartite(int n)
{
  	vector<bool> visited(n,false);
  	vector<int> color(n,-1);
  	
  	for(int i = 0; i < n; i++)
    {
      	if(!visited[i])
        {		
          	bool res = true;
          	DFS(i,visited,color,0,res);
          	//cout << i << " " << res << endl;
          	if(!res)
            {
              	return false;
            }
        }
    }
  
  	return true;
}

int main()
{
	//code
  	int t;
  	cin >> t;
  
  	while(t--)
    {
      	int n,q;
      	cin >> n >> q;
      
      	for(int i = 0; i < n; i++)
          	graph[i].clear();
      	
      	vector<pair<int,int>> oneDiff;
      	
     	Disj *dj = new Disj[n];
      	for(int i = 0; i < n; i++)
        {
          	dj[i].parent = i;
          	dj[i].rank = 0;
        }
      
        bool sanity_check = true;
      
      	for(int i = 0; i < q; i++)
        {
          	int a,b,c;
          	cin >> a >> b >> c;
          	a--;
          	b--;
          	
          	if(a == b && c != 0)
              	sanity_check = false;
          	
          	if(c == 0)
            {
              	Union(a,b,dj);
            }
          	else
            {
              	oneDiff.push_back(make_pair(a,b));
            }
        }
      
      	/*set<int> comps;
      	for(int i = 0; i < n; i++)
        {
          	comps.insert(find(i,dj));
        }
      	for(auto it : comps)
        {
          	cout << it << " ";
        }*/
      
      	for(auto it : oneDiff)
        {
          	int p_a = find(it.first,dj);
          	int p_b = find(it.second,dj);
          
          	if(p_a == p_b)
            {
              	sanity_check = false;
              	break;
            }
          	graph[p_a].push_back(p_b);
          	graph[p_b].push_back(p_a);
        }
      
      	/*for(int i = 0; i < n; i++)
        {
          	cout << i <<":";
          	for(int j = 0; j < graph[i].size(); j++)
              	cout << graph[i][j] << " ";
          	cout << endl;
        }*/
      
      	if(!sanity_check)
        {
          	cout << "no" << endl;
          	continue;
        }
      
      	bool ans = isBipartite(n);
      	if(ans)
        {
          	cout << "yes" << endl;
        }
      	else
        {
          	cout << "no" << endl;
        }
    }
	return 0;
}

