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
#define ten(n) (int)1e##n
#define tenll(n) (lli)1e##n
#define mod 1000000007

///http://lightoj.com/volume_showproblem.php?problem=1205
/// how many palindromic numbers are there in between [L,R] range

const int NX = 20 ;

lli dp[2][NX][NX];
int vis[2][NX][NX];
lli num[20] , now;
int lim, tt ;
vector < int > inp ;

int isOK(){
    lli ret = 0;
    for(int i=0; i<lim; i++ , ret *= 10) ret += num[i];
    ret /= 10;
    return (now>=ret);
}

lli DP( int lo , int hi ,int isStart , int isSmall) /// taking just pos isn't enough...why?
{
    if(lo>hi) return isOK();
/// checking just the final number makes our life easier..no panic while choosing a digit "i"

    lli &ret = dp[isSmall][lo][hi];
    int &v = vis[isSmall][lo][hi];

    if(v == tt ) return ret;
    v = tt ;
    int ses = isSmall ? 9 : inp[lo];
    int i ;
    ret = 0 ;

    if(isStart == 0)
    {
        for ( i = 0 ; i <= ses ; i++ )
        {
            int d = num[lo];
            num[lo] = num[hi] = i;
            ret += DP( lo+1, hi-1,0,isSmall | i < inp[lo]);
            num[lo] = num[hi] = d; /// tricky business
        }
    }
    else
    {
        ///ret += DP(lo+1,hi,1,1); //ok too...why?

        for ( i = 1 ; i <= ses ; i++ )
        {
            int d = num[lo];
            num[lo] = num[hi] = i;
            ret += DP(lo+1, hi-1, 0 , isSmall | i < inp[lo]);
            num[lo] = num[hi] = d;
        }

        ret += DP(lo+1,hi,1,1);
    }
    return ret ;
}

lli Cal( lli x )
{
    if( x < 0 ) return 0 ;
    if( x <= 9 ) return 1+x ;
    inp.clear();
    now = x;
    while( x )
    {
        inp.pb(x%10);
        x/=10;
    }
    reverse(inp.begin(),inp.end());
    lim = inp.size();
    tt++;
    return DP( 0,lim-1,1,0);
}
int main()
{
    int cs, t ;
    scanf("%lld",&t);
    for ( cs = 1 ; cs <= t ; cs++ )
    {

        lli n,m,ans;
        scanf("%lld%lld",&m,&n);
        if(m>n)swap(m,n);
        ans = Cal(n) - Cal(m-1);
        printf("Case %d: %lld\n",cs,ans);
    }
    return 0;
}

