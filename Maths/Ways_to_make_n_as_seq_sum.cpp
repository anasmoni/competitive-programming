#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> pii;

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
#define mod 1000000007

#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N = N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

///priority_queue< int, vector< int >, greater< int > > minHeap;


template <typename T>
T Bmod(T a, T b, T c)
{
    if(b==0) return 1;

    if(b%2==0)
    {
        T x = Bmod(a,b/2,c);
        return (x%c * x%c)%c; /// to avoid overflow as may x >= 10^10
    }
    else return (a%c * Bmod(a,b-1,c))%c;
}



map<lli,lli>dp;
vector<lli>divs;

lli fun(lli n)
{
    if(dp.find(n)!=dp.end()) return dp[n];

    lli ans = Bmod(2LL,n-1,(lli)mod);

    for(auto x : divs){

            if(n%x == 0 && x<n) ans = (ans-fun(x)+mod)%mod;
    }

    return dp[n]=ans;
}

/// cf : D. Unusual Sequences
/// Learn the method of finding "How many sequences exist such that sum of sequence elements == n "
///see Editorial and Comments

/// problem statement : Given x,y 1<=x,y<=1e9 ; How many sequences are there such that sequence sum == y
/// and gcd(sequence) == x

/** Number of sequences such that sequence_sum == n is = 2^(n-1)
    why?
    n = 5;

    11111

    1|11|11
    1|1|111
    .......
    .......
    total 2^(n-1)

    but they are with any gcd , we need sequence with gcd = 1 , say function f(n) = ans

    so ,f(n) =  2^(n-1) - sum(f(n/d_i)) ; where for all d_i : n%d_i == 0

    look , sum(f(n/d_i)) == Number of sequences such that sequence_sum == n and gcd(seq)>1
*/

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);

    ///FastIO;

    int x,y;

    cin>>x>>y;

    if(y%x!=0){
        cout<<0;
        return 0;
    }

    for(lli i=1; (i*i)<=y; i++){

        if(y%i==0){
            divs.pb(i);
            if(i != y/i) divs.pb(y/i);
        }
    }
    cout<<fun(y/x);

    return 0;
}
