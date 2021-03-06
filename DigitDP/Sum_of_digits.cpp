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

///given a,b (a<=b) , find sum of digits of all number in between [a,b]
/// 1 10 -> 46

const int NX = 90 ;

lli dp[2][NX][NX];
int vis[2][NX][NX];
int lim, tt ;
vector < int > inp ;

lli DP( int pos, int isSmall,int value)
{
    if( pos == lim ) return value ;
    lli &ret = dp[isSmall][pos][value];
    int &v = vis[isSmall][pos][value];
    if(v == tt ) return ret ;
    v = tt ;
    int ses = isSmall ? 9 : inp[pos];
    int i ;
    ret = 0 ;

    for ( i = 0 ; i <= ses ; i++ )
    {
        ret += DP( pos + 1, isSmall | i < inp[pos], value + i);
    }

    return ret ;
}

lli Cal( lli x )
{
    if( x <= 0 ) return 0 ;

    inp.clear();
    while( x )
    {
        inp.pb(x%10);
        x/=10;
    }
    reverse(inp.begin(),inp.end());
    lim = inp.size();
    tt++;
    return DP( 0, 0, 0 );
}
int main()
{
    int cs;

    for ( cs = 1 ;  ; cs++ )
    {

        lli n,m,ans;
        scanf("%lld%lld",&m,&n);
        if(m<0)break;
        ans = Cal(n) - Cal(m-1);
        printf("%lld\n",ans);
    }
    return 0;
}
