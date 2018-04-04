#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x,y,dist;
    string reach;
};

bool isValid(int r,int c,int n)
{
    return (r >=0 && r < n) && (c >= 0 && c < n);
}

void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    //  Print the distance along with the sequence of moves.
    int visited[201][201];
    //Possible Moves
    int row[] = {-2,-2,0,2,2,0};
    int col[] = {-1,1,2,1,-1,-2};
    string id[] = {"UL","UR","R","LR","LL","L"};
    map<string,int> moveMap;
    moveMap["UL"] = 1;
    moveMap["UR"] = 2;
    moveMap["R"] = 3;
    moveMap["LR"] = 4;
    moveMap["LL"] = 5;
    moveMap["L"] = 6;


    Node src;
    src.x = i_start;
    src.y = j_start;

    Node dest;
    dest.x = i_end;
    dest.y = j_end;

    queue<Node> que;
    que.push(src);

    int act_dist = -1;

    Node node;
    while(!que.empty())
    {
        node = que.front();
        que.pop();
        int x = node.x;
        int y = node.y;
        int dist = node.dist;

        if(x == dest.x && y == dest.y)
        {
            act_dist = dist;
            dest.dist = dist;
            dest.reach = node.reach;
            visited[x][y] = moveMap[node.reach];
            break;
        }
        if(!visited[x][y])
        {
            visited[x][y] = moveMap[node.reach];
            for(int i = 0; i < 6; i++)
            {
                int x1 = x + row[i];
                int y1 = y + col[i];
                if(isValid(x1,y1,n))
                {
                    que.push({x1,y1,dist+1,id[i]});
                }
            }
        }
    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //         cout<<visited[i][j]<<" ";
    //     cout<<endl;
    // }
    
    if(act_dist != -1)
    {
        cout<<act_dist<<endl;
        vector<string> path;
        path.push_back(node.reach);

        for(int i = dest.dist ; i > 1; i--)
        {
            int curr_x = i_end;
            int curr_y = j_end;
            int prevMove = visited[curr_x][curr_y];
            int next_x = curr_x - row[prevMove - 1];
            int next_y = curr_y - col[prevMove - 1];
            i_end = next_x;
            j_end = next_y;
            path.push_back(id[visited[next_x][next_y]-1]);
        }
        for(int i = path.size() - 1; i >= 0; i--)
            cout<<path[i]<<" ";
    }
    else
        cout<<"Impossible";
    
}

int main() {
    int n;
    cin >> n;
    int i_start;
    int j_start;
    int i_end;
    int j_end;
    cin >> i_start >> j_start >> i_end >> j_end;
    printShortestPath(n, i_start, j_start, i_end, j_end);
    return 0;
}