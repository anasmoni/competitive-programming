#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> pii;
typedef priority_queue< int, vector< int >, greater< int > >  minHeap;

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

template<typename T>
void we_r_done(T mssg)
{
    cout<<mssg;
    exit(0);
}

namespace Scc_Tarjan
{
const int maxN = 200002;
int n,m,id,scc;
stack<int> s;
vector<int> adj[maxN+5];
int low[maxN+5],ind[maxN+5],belong[maxN+5];
int in[maxN+5],out[maxN+5];
bool onStack[maxN+5],vis[maxN+5];

void Tarjan(int u)
{
    low[u] = ind[u] = id++;
    s.push(u);
    onStack[u] = true;

    int v;
    for(int i = 0 ; i < adj[u].size() ; i++)
    {
        v = adj[u][i];
        if(ind[v] == inf)
        {
            Tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(onStack[v])
            low[u] = min(low[u],ind[v]);
    }

    if(low[u] == ind[u])
    {
        //printf("SCC:");
        do
        {
            v = s.top();
            //printf(" %d",v);
            s.pop();
            belong[v] = scc;
            onStack[v] = false;
        }
        while(u != v);
        scc++;
        //printf("\n");
    }
}

void reset()
{
    id = scc = 0;
    while(!s.empty())
        s.pop();
    for(int i = 1 ; i <= n ; i++)
    {
        adj[i].clear();
        low[i] = ind[i] = inf;
        onStack[i] = vis[i] = false;
        in[i] = out[i] = 0;
    }
}

void DFS(int u)
{
    vis[u] = true;
    for(int i = 0 ; i < adj[u].size() ; i++)
    {
        int v = adj[u][i];
        if(belong[u] != belong[v])
        {
            in[belong[v]]++;
            out[belong[u]]++;
        }
        if(!vis[v])
            DFS(v);
    }
}
}
using namespace Scc_Tarjan;
int main()
{
    int tcs;
    scanf("%d",&tcs);
    for(int t = 1 ; t <= tcs ; t++)
    {

        scanf("%d %d",&n,&m);

        reset();

        for(int i = 0 ; i < m ; i++)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            adj[u].pb(v);
        }

        for(int i = 1 ; i <= n ; i++)
            if(ind[i] == inf)
               Tarjan(i);

        for(int i = 1 ; i <= n ; i++)
            if(!vis[i])
                DFS(i);

        int mIn,mOut;
        mIn = mOut = 0;

        for(int i = 0 ; i < scc && scc > 1; i++)
        {
            if(!out[i])
                mOut++;
            if(!in[i])
                mIn++;
        }

        printf("Case %d: %d\n",t,max(mOut,mIn));
    }

    return 0;
}
