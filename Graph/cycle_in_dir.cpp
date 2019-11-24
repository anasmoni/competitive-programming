#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vec;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scnll(n) scanf("%lld",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
#define scn3(n,m,w) scanf("%d%d%d",&n,&m,&w)
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define Fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))


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

vector<int>g[40005];
bool yup;
int vis[40040];
///http://www.lightoj.com/volume_showproblem.php?problem=1003
void dfs(int x)
{
    vis[x]=1;

    for(int i=0; i<g[x].size(); i++)
    {
        int v = g[x][i];
        if(vis[v]==0)dfs(v);
        else if(vis[v]==1){
            yup=true;
            return;
        }

    }
    vis[x]=2;
}

int main()
{
    int t;
    scn(t);

    for(int tc=1; tc<=t; tc++)
    {
        int n;
        scn(n);
        map<string,int>mip;
        int k=0;
        while(n--)
        {
            string a,b;
            cin>>a>>b;

            if(mip[a]==0)mip[a]=++k;
            if(mip[b]==0)mip[b]=++k;
            g[mip[a]].pb(mip[b]);
        }
        yup=false;

        for(int i=0; i<=k; i++)vis[i]=0;

        for(int ki=1; ki<=k; ki++){
            if(vis[ki]==0)dfs(ki);
            if(yup)break;
        }

        if(yup)printf("Case %d: No\n",tc);
        else printf("Case %d: Yes\n",tc);

        for(int i=1; i<=k; i++)g[i].clear();
    }

    return 0;
}
