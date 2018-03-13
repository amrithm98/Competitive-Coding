#include<bits/stdc++.h>
using namespace std;

#define LL long long int

struct Worker
{
    int time;
    int cost;
    int speed;
};

bool compare(Worker A,Worker B)
{
    if(A.time == B.time)
    {
        return (double)(A.speed/A.cost) > (double)(B.speed/B.cost);
    }
    return A.time < B.time;
}

int main()
{
    int n;
    LL D;
    scanf("%d",&n);
    cin >> D;

    Worker *workers = new Worker[n];

    for(int i = 0; i < n; i++)
    {
        cin >> workers[i].time >> workers[i].cost >> workers[i].speed;
    }

    sort(workers,workers+n,compare);

    LL currUnits = 0;
    LL cost = 0;
    int lastTime = workers[0].time;
    LL bestSpeed = 0;

    for(int i = 0; i < n; i++)
    {
        currUnits += (bestSpeed *1LL * (workers[i].time - lastTime));

        if(currUnits >= D)
        {
            break;
        }

        if(workers[i].speed > bestSpeed)
        {
            bestSpeed = workers[i].speed;
            cost += workers[i].cost;
        }

        lastTime = workers[i].time;
    }

    cout << cost << endl;
    return 0;
}