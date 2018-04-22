#include <bits/stdc++.h>
using namespace std;

string winner(string s)
{
    stack<int> whites,temp,blacks;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'W')
            whites.push(i);
        else if(s[i] == 'B')
            temp.push(i);
    }

    bool turn = true;

    while(!temp.empty())
    {
        blacks.push(temp.top());
        temp.pop();
    }

    while(whites.size() != 0 && blacks.size() != 0)
    {

        // cout << "\n" << ((turn == 1)?"White":"Black") << "'s Turn";
        int white_top = whites.top();
        int black_top = blacks.top();

        if(turn && (black_top-white_top+1)%2 == 0)
        {
            //White's turn and even position to black
            blacks.pop();
            whites.pop();

            int gap = (black_top-white_top-1);
            whites.push(white_top + (gap/2) + 1);

            // cout << "\nWhite Beats Black at " << black_top << endl;
            turn = !turn;
        }
        else if(turn && (black_top-white_top+1)%2 == 1)
        {
            //White's turn and odd position to black
            blacks.pop();
            whites.pop();
            int gap = (black_top-white_top-1);
            blacks.push(black_top-(gap/2)-1);
            // cout << "\nBlack Beats White at " << white_top << endl;
        }
        else if(!turn && (black_top-white_top+1)%2 == 0)
        {
            blacks.pop();
            whites.pop();
            int gap = (black_top-white_top-1);
            blacks.push(black_top-(gap/2)-1);
            // cout << "\nBlack Beats White at " << white_top << endl;
            turn = !turn;
        }
        else if(!turn && (black_top-white_top+1)%2 == 1)
        {
            blacks.pop();
            whites.pop();

            int gap = (black_top-white_top-1);
            whites.push(white_top + (gap/2) + 1);

            // cout << "\nWhite Beats Black at " << black_top << endl;
        }
    }
    if(blacks.size() != 0)
        return "B";
    else
        return "W";

}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;
        cout << winner(s) << endl;
    }

    return 0;
}