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
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define mod 1000000007
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define bug(x) cerr << __LINE__ << " says: " << #x << " = " << (x) << "\n"

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


inline int addmod(int x ,int y){return (x%mod + y%mod)%mod;}
inline int submod(int x ,int y){return (x%mod - y%mod + mod)%mod;}
inline int mulmod(int x ,int y){return (x%mod *1LL* y%mod)%mod;}
inline int nextSubMask(int i , int mask) {return (i-1)&mask;} /// returns next  submask

template<typename T>
void we_r_done(T mssg){cout<<mssg; exit(0);}

const int N = 100005;

struct Edge{
    int u,v,w;
    Edge(int uu , int vv , int ww){
        u = uu;
        v = vv;
        w = ww;
    }
};

int n,m , dp[N] , sccID[N];
bool vis[N];
vector<Edge>E;
vector<int>adj[N] , radj[N] , DAG[N];
vector<int>topo;

void TopoSort(int x){
    vis[x] = true;
    for(int u : adj[x]){
        if(vis[u] == false) TopoSort(u);
    }
    topo.pb(x);
}

void dfs(int x , int scc){
    sccID[x] = scc;

    for(int u : radj[x]){
        if(sccID[u] == 0) dfs(u,scc);
    }
}

int canGo(int x){
    if(dp[x] != -1) return dp[x];
    int cnt = 0;
    for(int u : DAG[x]){
        cnt = max(cnt , canGo(u));
    }
    return dp[x] = ++cnt;
}

bool OK(int mxW){

    for(int i=1; i<=n; i++){
        vis[i] = false;
        adj[i].clear();
        radj[i].clear();
        DAG[i].clear();
        dp[i] = -1;
        sccID[i] = 0;
    }

    for(Edge e : E){
        if(e.w<=mxW){
            adj[e.u].pb(e.v);
            radj[e.v].pb(e.u);
        }
    }

    topo.clear();

    for(int i=1; i<=n; i++){
        if(vis[i] == false) TopoSort(i);
    }

    int scc = 0;

    while(topo.size()){
        int u = topo.back();
        topo.pop_back();

        if(sccID[u] == 0){
            dfs(u,++scc);
        }
    }

    for(Edge e : E){
        if(sccID[e.u] == sccID[e.v] || e.w>mxW) continue;
        DAG[sccID[e.u]].pb(sccID[e.v]);
    }

    for(int i=1; i<=scc; i++){
        if(canGo(i) == scc) return true;
    }
    return false;

}

int main()
{
    ///freopen("output.txt","w",stdout);
//    freopen("input.txt","r",stdin);

    ///FastIO;

    int t;
    scn(t);

    while(t--){
        scn2(n,m);

        E.clear();
        for(int i=1; i<=m; i++){
            int u,v,w;
            scn3(u,v,w);
            E.pb(Edge(u,v,w));
        }

        int lo=1,hi=mod,ans = -1 , mid;

        while(lo<=hi){
            mid = (lo+hi)/2;

            if(OK(mid)){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid+1;
        }

        if(ans == -1) printf("Impossible\n");
        else printf("%d\n",ans);
    }
    return 0;
}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)
///using bs = bitset<MX>; // how many distinct number can be form?
///sort(atoz(v), [](const data x, const data y){return (x.a==y.a?x.b>y.b : x.a<y.a);});
