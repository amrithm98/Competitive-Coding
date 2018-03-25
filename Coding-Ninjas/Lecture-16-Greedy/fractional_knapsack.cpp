#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int weight;
    int value;
};

bool compare(Item a,Item b)
{
    double value1 = (double)(a.value/a.weight);
    double value2 = (double)(b.value/b.weight);

    return value1 > value2;
}

int main()
{
    int n,W;
    cin >> n >> W;

    Item *items = new Item[n];
    for(int i = 0; i < n; i++)
    {
        cin >> items[i].weight >> items[i].value;
    }

    sort(items,items+n,compare);

    double maxVal = 0;
    int currWeight = 0;

    for(int i = 0; i < n; i++)
    {
        if(currWeight + items[i].weight <= W)
        {
            maxVal += items[i].value;
            currWeight += items[i].weight;
        }
        else
        {
            int balWeight = W-currWeight;
            maxVal += (double)(balWeight*(double)(items[i].value/items[i].weight));
            break;
        }
    }

    cout << maxVal << endl;
    return 0;
}