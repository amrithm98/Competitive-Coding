#include <bits/stdc++.h>
using namespace std;

struct qy{
  char q;
  int x;
};

vector<int> BIT(200001);
vector< qy  > queries;
map<int , int > pos;

void update(int i , int value , int n){
	for(;i<=n;i += i&(-i))
    	BIT[i] += value;
}

int query(int i){
	int sum = 0;
    for(;i>0;i -= i&(-i))
    	sum += BIT[i];
    return sum;
}

int main()
{
  	int n , x , len;
  	char q;
  	cin >> n;
  	queries = vector<qy> (n);
    vector<int> a;
  	for(int i = 0 ; i < n ; i++){
      cin >> q >> x;
      if(q == 'I')
        a.push_back(x);
      queries[i].q = q;
      queries[i].x = x;
    }
    sort(a.begin(),a.end());
  	pos[a[0]] = 1;
    len = 1;
    for(int i = 1 ; i < a.size() ; i++){
      if(a[i] != a[i-1])
        pos[a[i]] = ++len;        
    }
  	vector<int> b(pos.size()+1);
  	for(auto it : pos)
      b[it.second] = it.first;
  	vector<int>::iterator it;
    int mid , ans , t , start , end;
  	for(int i = 0 ; i < n ; i++)
      switch(queries[i].q){
		case 'I'	:	if( query(pos[queries[i].x]) == query(pos[queries[i].x] - 1)){
          					update(pos[queries[i].x] , 1 , len);
        				}
          				break;
        case 'D'	:	if( query(pos[queries[i].x]) != query(pos[queries[i].x] - 1)){
          					update(pos[queries[i].x] , -1 , len);
        				}
          				break;
        case 'C'	:	it = lower_bound(a.begin(),a.end(),queries[i].x);
                        it--;
          				if(*it == queries[i].x)
                          cout << query(pos[*it] - 1) << endl;
          				else
                          cout << query(pos[*it]) << endl;
          				break;      
        case 'K'	:	if(query(len) < queries[i].x)
          					cout << "invalid\n";
          		        else{
          					start = 1; end = len;
          					while(start <= end){
                          		mid = (start + end) / 2;
                              	t = query(mid);
                          		if(t < queries[i].x)
                                  start = mid+1;
                                else{
                                  if(t == queries[i].x)
                                    ans = mid;
                                  end = mid - 1;
                                  
                                }
                                
                        	}
                          
                            cout <<b[ans]  << endl;
                        }
          				break;
          
      }
    return 0;
}