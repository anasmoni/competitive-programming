#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> pii;

#define ones(x) __builtin_popcount(x)
#define onesl(x) __builtin_popcountl(x)
#define onesll(x) __builtin_popcountll(x)

#define pb push_back
#define eb emplace_back
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
inline int nextSubMask(int i, int mask)
{
    return (i-1)&mask;   /// returns next smallest submask
}

void we_r_done()
{
    cout<<"NO";
    exit(0);
}

void debug(string mssg)
{
    cout<<mssg;
    exit(0);
}

using minHeap = priority_queue< int, vector< int >, greater< int > >;

#define N 4200000

bool dp[N];

/// memory optimized sos dp
/** problem : given array a[] of size n
                for each i , (1<=i<=n) print any a[j] such that (1<=j<=n) && (a[i] & a[j] == 0)
*/

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);

    ///FastIO;

    int m = 1<<22;
    m--;

    int n;
    scn(n);
    int a[n];

    for(int i=0; i<n; i++)scn(a[i]);

    Fill(dp,0);

    vector<bool>cnt(N,0);

    for(int i=0; i<n; i++)
        cnt[a[i]] = true;

    for(int i = 0; i<=m; ++i)
        dp[i] = cnt[i];

    for(int i = 0; i <= 22; ++i)
    {
        for(int mask = 0; mask <=m; ++mask)
        {
            if(check(mask,i)) dp[mask] |= dp[mask^(1<<i)];
        }
    }

    for(int i=0; i<n; i++)
    {
        int msk = a[i]^m;

        if(dp[msk])
        {
            for(int j=0; j<=22 && cnt[msk]==false; j++){
                if(check(msk,j)){
                    int nxt = msk^(1<<j);
                    if(dp[nxt])msk = nxt;
                }
            }
            printf("%d ",msk);
        }
        else
            printf("-1 ");
    }


    return 0;

}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)
///using bs = bitset<MX>; // how many distinct number can be form?
