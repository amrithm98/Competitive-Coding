#include<bits/stdc++.h>

#define N 1000001

using namespace std;

vector<int> primes;
void makeSieve(int n){
  vector<bool> sieve(n+1,true);
  for(int i = 2; i <= n;i++ ){
    if(sieve[i]){
      primes.push_back(i);
      for(int j = 2*i ;j<=n; j+=i)
        sieve[j] = false;
    }
  }
}

vector< pair<long long,long long> > segmentedTSieve(long long L, long long R){
  	vector< pair<long long,long long> > segTSieve;
  	int size = R-L+1;
    for(int i = 0; i< size ; i++)
      segTSieve.push_back(make_pair(i+L,i+L));
     
  long long base;
	for(int it = 0; it < primes.size();it++){
      //cout<<primes[it] << " ";
      base = (L/primes[it] ) * (long long)primes[it];
      if(base < L)
        base += primes[it];
      for(long long j = base; j <= R; j+=primes[it])
      {
        segTSieve[j-L].first -= segTSieve[j-L].first/primes[it];
        while (segTSieve[j-L].second % primes[it] == 0)
                segTSieve[j-L].second /= primes[it];
      }
      
    }
  //cout << endl;
  return segTSieve;
  
}

long double getProbability(long long L,long long R, int K){
  vector< pair<long long,long long> > segTSieve = segmentedTSieve(L,R);
  long double p = 0;
  int i;
  for(i = 0;i<segTSieve.size();i++){
   //cout << segTSieve[i].first << " "<<segTSieve[i].second <<endl;
    if(segTSieve[i].first == i+L && i+L != 1)
      segTSieve[i].first -- ;
    else if (segTSieve[i].second > 1)
      segTSieve[i].first -= segTSieve[i].first/segTSieve[i].second;
    if(segTSieve[i].first % K == 0)
    	p++;
  }
   //cout << endl;
  //cout << p<<endl;
  //cout << segTSieve.size()<<endl;
  p /= segTSieve.size();
  return p;
}

int main() {

	int t;
  cin >> t;
  makeSieve(N);
  long long L,R;
  int K;
  while(t--){
    cin >> L >> R >> K;
    cout << setprecision(6) << fixed <<getProbability(L,R,K) << endl;
  }
  return 0;
}