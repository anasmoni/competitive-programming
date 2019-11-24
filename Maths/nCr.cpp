#include<bits/stdc++.h>
using namespace std;

//#define long long ll
#define INF 1000000007
#define N

long long f[300005];


long long pow(long long a, long long b, long long MOD)
{
 long long x=1,y=a;
 while(b > 0)
 	{
 		if(b%2 == 1)
 	{
 		x=(x*y);
 		if(x>MOD) x%=MOD;
 	}
 	y = (y*y);
 	if(y>MOD) y%=MOD;
 	b /= 2;
 	}
 return x;
}

/* Modular Multiplicative Inverse
 Using Euler's Theorem
 a^(phi(m)) = 1 (mod m)
 a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(long long n, long long MOD)
{
 return pow(n,MOD-2,MOD);
}

long long C(long long n, long long r, long long MOD)
{

 return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}

int main(){
	f[0] = 1;
	for(int i = 1 ; i < N ; i++)f[i] = (f[i-1]*i)%INF;
 	int t; cin>>t;
 	while(t--){
        int n,m;cin>>n>>m;
        m--;
        cout << C(m+n,m,INF) << endl;
 	}
}
