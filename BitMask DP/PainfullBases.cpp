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

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}

///http://lightoj.com/volume_showproblem.php?problem=1021

int base , k;
string inp;
lli dp[(1<<16)+2][22];
lli pbase[20];

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

lli call(lli mask ,int pos, lli mod=0)
{
    if(pos<0) return (mod == 0);

    lli &ret = dp[mask][mod];

    if(ret != -1) return ret;

    ret = 0;

    for(int i=0; i<inp.size(); i++){

        if(check(mask,i)) continue;

        ret += call(mask | (1LL<<i), pos-1 ,(mod + val(inp[i])*pbase[pos])%k); /// not mod*10
    }
    return ret;
}
int main()
{
    int t;
    scn(t);

   // freopen("output.txt","w",stdout);

    for(int cs=1; cs<=t ; cs++)
    {
        Fill(dp,-1);
        scn2(base,k);

        pbase[0] = 1;

        for(int i=1; i<=16; i++) pbase[i] = (base*pbase[i-1])%k;

        cin>>inp;

        printf("Case %d: %lld\n",cs,call(0,inp.size()-1));
    }

    return 0;
}
