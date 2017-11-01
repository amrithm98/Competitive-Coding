#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int>* sieve(long long l)
{
    cout<<"Inside the sieve"<<endl;
    vector<bool> a(l+1);
    long long j;
    for(int i = 2; i <= l; i++)
        a[i] = true;
    
    vector<int>* primes = new vector<int>();
    for(int i = 2; i <= sqrt(l); i++)
    {
        cout<<"Checking for factor "<<i<<endl;
        if(a[i])
        {
            for(j = i*i; j<=l; j += i)
                a[j] = false;
        }
    }
    for(int i = 2; i <= l; i++)
        if(a[i])
            primes->push_back(i);
    return primes;
}

vector<int>* return_per(int a, bool marked[], vector<int>* & primes)
{
    int t = a;
    vector<int>* factors = new vector<int>();
    for(int i = 0; i < primes->size(); i++)
    {
        if(t == 1)
            break;
        if(primes->at(i) == a)
            break;
        if(t%primes->at(i) == 0)
        {
            factors->push_back(primes->at(i));
            while(t%primes->at(i) == 0)
                t /= primes->at(i);
        }
    }
//    cout<<"Displaying the factors of a = "<<a<<endl;
//    display_vector(factors);
    vector<int>* temp = new vector<int>();
    temp->push_back(a);
    for(int i = 0; i < factors->size(); i++)
    {
        int j = a - factors->at(i);
        while(j > 0)
        {
            if(!marked[j])
            {
                marked[j] = true;
                temp->push_back(j);
            }
            j -= factors->at(i);
        }
    }
    sort(temp->begin(), temp->end(), greater<int>());
//    cout<<"Displaying the generated vector "<<endl;
//    display_vector(temp);
    return temp;
}

int main ()
{
    int n;
    cin>>n;
    bool marked[(n+1)];
      marked[0] = false;
    for(int i = 1; i <= n; i++)
        marked[i] = false;
//    cout<<"Displaying the vector of primes"<<endl;
//    display_vector(sieve(n/2));
    vector<int>* primes = sieve(n/2);
    cout<<"Done with the sieve"<<endl;
//  vector<int>* primes = new vector<int>();
//  primes->push_back(2);
//  primes->push_back(3);
    vector<int>* result = new vector<int>();
    for(int i = n; i >= 1; i--)
    {
//        cout<<"Checking for n = "<<i<<endl;
        if(!marked[i])
        {
            marked[i] = true;
            vector<int>* temp = return_per(i, marked, primes);
            result->insert(result->end(), temp->begin(), temp->end());
        }
    }
    for(int i = 0; i < result->size(); i++)
    {
        cout<<result->at(i)<<" ";
    }
    return 0;
}