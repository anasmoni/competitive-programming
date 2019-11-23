#include<bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vec;

#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define ratoz(v) v.rbegin(),v.rend()
#define Fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define ten(n) (int)1e##n
#define tenll(n) (lli)1e##n
#define mod 1000000007

#define NN 3583
#define N 501

inline int addmod(int x,int y)
{
    return (x%mod + y%mod)%mod;
}
inline int submod(int x,int y)
{
    return (x%mod - y%mod + mod)%mod;
}
inline int mulmod(int x,int y)
{
    return (x%mod *1LL* y%mod)%mod;
}


vector<int>primes;
bool vis[NN];
int dp[N][N] , PBmod[NN][N];

template <typename T>
T Bmod(T a, T b, T c)
{
    if(b==0) return 1;
    if(b%2==0)
    {
        T x=Bmod(a,b/2,c);
        return (x%c *1LL* x%c)%c; /// to avoid overflow as may x >= 10^10
    }
    else return (a%c *1LL* Bmod(a,b-1,c))%c;
}


void seive()
{
    for(int i=3; (lli)(i*i)<NN; i += 2)
    {
        if(vis[i])continue;
        for(int j = i*i ; j<NN; j += 2*i) vis[j] = true;
    }

    primes.pb(2);

    for(int i=3; i<NN; i += 2)
    {
        if(!vis[i])primes.pb(i);
    }
}


int main()
{
    ///freopen("output.txt","w",stdout);
    freopen("input.txt","r",stdin);

    seive();
    dp[0][0] = 1;
    //cout<<primes.size()<<endl;
    primes.pop_back();
    vector<int>psum(NN,0);

    for(int i=1; i<N; i++){
        psum[i] = addmod(psum[i-1] , primes[i-1]);
        dp[1][i] = Bmod(2,i-1,mod);

        dp[i][i] = (dp[i-1][i-1] * 1LL * (primes[i-1]-1))%mod;
    }

    for(int p : primes){
        PBmod[p][0] = 1;
        for(int i=1; i<N; i++) PBmod[p][i] = Bmod(p,i,mod);
    }

    for(int k=3; k<N; k++){
        for(int p=2; p<k; p++){

            //dp[p][k] = mulmod(dp[p][k-1], psum[p]);

            for(int j=1; (k-j)>=(p-1); j++){

                int now = submod(PBmod[primes[p-1]][j] , PBmod[primes[p-1]][j-1]);

                dp[p][k] = addmod(dp[p][k] , mulmod(now,dp[p-1][k-j]));
            }
        }
    }

    int t;
    cin>>t;

    for(int cs=1; cs<=t; cs++)
    {

        int k,p;
        cin>>k>>p;
        printf("Case %d: %d\n",cs,dp[p][k]);
    }

    return 0;

}
