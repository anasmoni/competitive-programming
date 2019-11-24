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

///http://lightoj.com/volume_showproblem.php?problem=1037

int w[20][20];
int n;
int dp[(1<<15)+2], health[20];

int call(int mask)
{
    if(mask==(1<<n)-1) return 0;

    int &ret = dp[mask];

    if(ret != -1) return ret;

    ret = 1<<30;

    for(int i=0; i<n; i++)
    {
        if(check(mask,i)) continue;

        int damage = 1;

        for(int j=0; j<n; j++)
        {
            if(i != j && check(mask,j))  damage = max(damage , w[j][i]);
        }

        damage = health[i]/damage + (health[i]%damage != 0);

        ret = min(ret, damage + call(Set(mask,i)));
    }
    return ret;
}
int main()
{
    int t;
    scn(t);

    for(int cs=1; cs<=t ; cs++)
    {
        Fill(dp,-1);
        cin>>n;

        for(int i=0; i<n; i++)
        {
            scn(health[i]);
        }

        for(int i=0; i<n; i++)
        {
            string s;
            cin>>s;

            for(int j=0; j<n; j++)  w[i][j] = s[j]-'0';
        }

        int ret=call(0);
        printf("Case %d: %d\n",cs,ret);
    }

    return 0;
}
