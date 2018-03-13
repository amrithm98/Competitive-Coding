#include <bits/stdc++.h>
using namespace std;

#define uint unsigned int

int main()
{
    uint maxSe;;
    uint choose;
    cin >> maxSet >> choose;

    vector<vector<bool>> pos (choose + 1);
    vector<vector<bool>> dup(choose + 1);

    vector<uint> values;

    for (uint i = 1; i <= maxSet; i++)
    {
        int t;
        cin >> t;
        values.push_back(t);
    }

    for (size_t i = 0; i < pos.size(); i++)
    {
        size_t maxSize = maxSet*maxSet * i + 1;
        if (maxSize > 300000) 
            maxSize = 300000;
        pos[i].resize(maxSize, false);
        dup[i].resize(maxSize, false);
    }


    pos[0][0] = true;

    for (auto add : values)
    {
        for (uint numElements = choose; numElements > 0; numElements--)
        {
            for (size_t sum = 0; sum < pos[numElements - 1].size(); sum++)
            {
                    if (!pos[numElements - 1][sum])
                    continue;
                    auto current = add + sum;
                    if (dup[numElements - 1][sum] || pos[numElements][current])
                    {
                        pos [numElements][current] = true;
                        dup[numElements][current] = true;
                    }
                    else
                    {
                        pos[numElements][current] = true;
                    }
            }
        }
    }


    uint result = 0;
    for (size_t sum = 0; sum < pos[choose].size(); sum++)
        if (pos[choose][sum] && !dup[choose][sum])
        result += sum;

    cout << result << endl;
    return 0;
}