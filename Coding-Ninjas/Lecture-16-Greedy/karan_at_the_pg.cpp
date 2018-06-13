#include<bits/stdc++.h>
using namespace std;

struct WearTime
{
  	int start;
 	int end;
  	int index;
};

int main()
{
    //Write your code here
  	int t;
  	cin >> t;
  
  	int k = 1;
  
  	while(k <= t)
    {
      	int n;
      	int inTime,wakeTime,storeOpen,travelTime,selTime;
      
      	string s;
      	cin >> n;
      
      	cin >> s;
      	inTime = 60*stoi(s.substr(0,2)) + stoi(s.substr(3,2));
      	
      	cin >> s;
      	wakeTime = 60*stoi(s.substr(0,2)) + stoi(s.substr(3,2));
      	
      	cin >> s;
      	storeOpen = 60*stoi(s.substr(0,2)) + stoi(s.substr(3,2));
      
      	cin >> travelTime;
      	cin >> selTime;
      	
      	//cout << inTime << " " << wakeTime << " " << storeOpen << endl; 
      
      	vector<WearTime> friends(n);
      	
      	int minTime = 10000;
      	int minIndex = -1;
      
      	for(int i = 0; i < n; i++)
        {
         	string s1,s2;
          	cin >> s1 >> s2;
          	
          	friends[i].start = 60*stoi(s1.substr(0,2)) + stoi(s1.substr(3,2));
          	friends[i].end = 60*stoi(s2.substr(0,2)) + stoi(s2.substr(3,2));
          	friends[i].index = i+1;
          	
          	//Case 1 : If I can go n come back before ith friend needs it
          	int back_pos_1 = max(storeOpen,wakeTime+travelTime) + selTime + travelTime;
          	
          	//cout << "\nBACK1 : " << back_pos_1 << endl;
          
          	if(back_pos_1 < friends[i].start && back_pos_1 < inTime)
            {
              	//cout << "\nTRUE1";
              
              	if(back_pos_1 < minTime)
                {
                  	minTime = back_pos_1;
                  	minIndex = i+1;
                }
            }
          	//Case 2 : If I can go n come back after ith friend needs it and inTime
          	int back_pos_2 = max(storeOpen,max(friends[i].end,wakeTime)+travelTime) + selTime+travelTime;
          	if(back_pos_2 < inTime)
            {
              	//cout << "\nTRUE2";
              
              	if(back_pos_2 < minTime)
                {
                  	minTime = back_pos_2;
                  	minIndex = i+1;
                }
            }
          	
          
        } 
      
      	cout << "Case " << k << ": " << minIndex << endl;
      	k++;
      	
    }
    return 0;
}
