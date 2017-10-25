#include <iostream>
#include<bits/stdc++.h>
#include<set>
using namespace std;
#define MAX 2000001

int gcd(int a,int b)
{
	//Write your code here
    if(a < b)
        return gcd(b,a);

    if(b == 0)
        return a;
        
    else
        return gcd(b,a%b);
}

vector<bool> sieve_of_eratosthenes()
{
    vector<int> sieve(MAX);
    vector<set<int>> factors(MAX);

    sieve[0] = false;
    sieve[1] = false;

    for(int i =2 ;i <= MAX;i++)   
        sieve[i] = true;
    
    for(int i = 2; i <= sqrt(MAX);i++)
    {
        if(sieve[i])
            for(int j = i*i; j <=MAX ;j += i)
                sieve[j] = false;
    }

    // vector<int> primes;
    // primes.push_back(2);
    // for(int i = 3; i<= MAX; i++)
    //     if(sieve[i])
    //         primes.push_back(i);

    return sieve;

}

int main()
{
    int n;
    cin >> n;

    vector<bool> sieve = sieve_of_eratosthenes();
    vector<int> strangeOrder;
    set<int> removed;

    int temp = n;
    while( n!= 0)
    {
        if(removed.find(n) == removed.end())
        {
            if(sieve[n])
            {
                strangeOrder.push_back(n);
                removed.insert(n);
            }
            else
            {
                strangeOrder.push_back(n);
                for(int i = n-1; i >1 ; i--)
                {
                    if(gcd(n,i)!=1)
                    {
                        if(removed.find(i) == removed.end() )
                        {
                            strangeOrder.push_back(i);
                            removed.insert(i);
                        }
                        
                    }
                }
            }
        }
        
        n--;
    }
    for(int i = 0; i<strangeOrder.size();i++)
        cout<<strangeOrder[i]<<" ";
}