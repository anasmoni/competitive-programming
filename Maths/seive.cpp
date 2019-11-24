#include<bits/stdc++.h>
using namespace std;

/**

#define N 10000001
#define s 664592

bitset<N>vis;
int prime[s];
int primeCnt=0;

void seive(){

    for(int i=3; (lli)(i*i)<N; i += 2){

        if(vis[i])continue;

        for(int j = i*i ; j<N; j += 2*i) vis[j] = true;
    }

    prime[primeCnt++]=2;

    for(int i=3; i<N; i += 2){
        if(!vis[i])prime[primeCnt++]=i;
    }

}


**/

/**
vector<int>prime;
bool vis[N+7];

void Sieve()
{
    for (int p=2; p*p<=N; p++)
    {
        if (vis[p])continue;

        for (int i=p*p; i<=N; i += p) vis[i] = true;

    }

    prime.pb(2);
    for (int p=3; p <= N; p += 2)
       if (vis[p] == false) prime.pb(p);
}
**/

    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
void Sieve(int n)
{
    // Create a boolean array "prime[0..n]" and initialize

    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p=2; p*p<=n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }

    // Print all prime numbers
    for (int p=2; p<=n; p++)
       if (prime[p])cout << p << " ";
}

// Driver Program to test above function
int main()
{
    int n = 30;
    cout << "Following are the prime numbers smaller than or equal to " << n << endl;
    Sieve(n);

    return 0;
}
