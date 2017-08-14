#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string getHour(int h)
{
    string hour="";
    switch(h)
    {
        case 1:
            hour="one";
            break;
        case 2:
            hour="two";
            break;
        case 3:
            hour="three";
            break;
        case 4:
            hour="four";
            break;
        case 5:
            hour="five";
            break;
        case 6:
            hour="six";
            break;
        case 7:
            hour="seven";
            break;
        case 8:
            hour="eight";
            break;
        case 9:
            hour="nine";
            break;
        case 10:
            hour="ten";
            break;
        case 11:
            hour="eleven";
            break;
        case 12:
            hour="twelve";
            break;
    }
    return hour;
}
string getMinute(int m)
{
    string min="";
    switch(m)
    {
        case 1:
            min="one minute";
            break;
        case 2:
            min="two minutes";
            break;
        case 3:
            min="three minutes";
            break;
        case 4:
            min="four minutes";
            break;
        case 5:
            min="five minutes";
            break;
        case 6:
            min="six minutes";
            break;
        case 7:
            min="seven minutes";
            break;
        case 8:
            min="eight minutes";
            break;
        case 9:
            min="nine minutes";
            break;
        case 10:
            min="ten minutes";
            break;
        case 11:
            min="eleven minutes";
            break;
        case 12:
            min="twelve minutes";
            break;
        case 13:
            min="thirteen minutes";
            break;
        case 14:
            min="fourteen minutes";
            break;
        case 16:
            min="sixteen minutes";
            break;
        case 17:
            min="seventeen minutes";
            break;
        case 18:
            min="eighteen minutes";
            break;
        case 19:
            min="nineteen minutes";
            break;
        case 20:
            min="twenty minutes";
            break;
        case 21:
            min="twenty one minutes";
            break;
        case 22:
            min="twenty two minutes";
            break;
        case 23:
            min="twenty three minutes";
            break;
        case 24:
            min="twenty four minutes";
            break;
        case 25:
            min="twenty five minutes";
            break;
        case 26:
            min="twenty six minutes";
            break;
        case 27:
            min="twenty seven minutes";
            break;
        case 28:
            min="twenty eight minutes";
            break;
        case 29:
            min="twenty nine minutes";
            break;
    }
    return min;
}

int main(){
    int h;
    cin >> h;
    int m;
    cin >> m;
    string minute,hour;
    if(m==0)
    {
        cout<<getHour(h)<<" o' clock";
    }
    else if((m>0 && m<15) || (m>15 && m<30))
    {
        cout<<getMinute(m)<<" past "<<getHour(h);
    }
    else if(m==15)
    {
        cout<<"quarter past "<<getHour(h);
    }    
    else if(m==30)
    {
         cout<<"half past "<<getHour(h);
    }
    else if((m>30 && m<45) || (m>45 && m<60))
    {
        m=60-m;
        cout<<getMinute(m)<<" to "<<getHour((h+1)%12);
    }
    else if(m==45)
    {
         cout<<"quarter to "<<getHour((h+1)%12);
    }

    return 0;
}
