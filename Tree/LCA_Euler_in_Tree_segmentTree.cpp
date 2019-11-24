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
#define N 30003

vector<int>G[N];
int val[N], anc[N][17], a[N*2], pIndex[N], nIndex[N], len, level[N];
int tree[N*8];

///see problem soln book of shanto sir page 93

void dfs(int x, int par = -1)
{
    for(int u : G[x])
    {

        if(par == u) continue;

        anc[u][0] = x;
        level[u] = level[x] + 1;

        len++;
        pIndex[u] = len;
        a[len] = val[u];

        dfs(u,x);

        len++;
        nIndex[u] = len;
        a[len] = -val[u];
    }
}


void build(int idx, int lo, int hi)
{

    if(lo==hi)
    {
        tree[idx] = a[lo];
        return;
    }

    int mid = (lo+hi)/2;

    build(idx*2,lo,mid);
    build(idx*2+1,1+mid,hi);

    tree[idx] = tree[idx*2] + tree[2*idx + 1];
}

void update(int idx, int lo, int hi, int pos)
{
    if(pos<lo || hi<pos)return;

    if(lo == hi && lo==pos)
    {
        tree[idx] = a[lo];
        return;
    }

    int mid = (lo+hi)/2;

    update(idx*2,lo,mid,pos);
    update(idx*2+1,1+mid,hi,pos);

    tree[idx] = tree[idx*2] + tree[2*idx + 1];
}

int query(int idx, int lo, int hi, int l, int r)
{
    if(hi<l || lo>r)return 0;

    if(l<=lo && hi<=r)return tree[idx];

    int mid = (lo+hi)/2;

    int x = query(idx*2,lo,mid,l,r);
    int y = query(idx*2+1,1+mid,hi,l,r);

    return (x+y);
}

int LCA(int p, int q)
{
    int tmp, log, i;

    if (level[p] < level[q]) swap(p,q);

    for (log = 1; (1 << log) <= level[p]; log++);
    log--;

    for (i = log; i >= 0; i--)
    {

        if (level[p] - (1 << i) >= level[q]) p = anc[p][i];
    }

    if (p == q) return p;

    for (i = log; i >= 0; i--)
    {

        if (anc[p][i] != 0 && anc[p][i] != anc[q][i])
        {
            p = anc[p][i];
            q = anc[q][i];
        }
    }

    return anc[p][0];
}

void init_LCA(int n)
{

    int lgn = (int)(log(n)/log(2))+1;

    for(int j = 1; j<=lgn; j++)
    {
        for(int i = 1; i <= n; i++)
        {
            anc[i][j] = anc[anc[i][j-1]][j-1];
        }
    }
}

void init()
{

    for(int i=1; i<N; i++) G[i].clear();

    len = 0;
    Fill(anc,0);
    Fill(level,0);
    Fill(nIndex,-1);
    Fill(pIndex,-1);
}

int main()
{

    freopen("output.txt","w",stdout);

    int t;
    scn(t);

    for(int cs=1; cs<=t ; cs++)
    {

        int n;
        scn(n);

        init();

        for(int i=1; i<=n; i++) scn(val[i]);

        for(int i=1; i<n; i++)
        {
            int u,v;
            scn2(u,v);
            u++;
            v++;
            G[u].pb(v);
            G[v].pb(u);
        }


        pIndex[1] = ++len;
        a[len] = val[1];

        dfs(1);

        len++;
        a[len] = -val[1];
        nIndex[1] = len;

        init_LCA(n);
        build(1,1,len);
        //cout<<len<<" len\\n";

       // for(int i=1; i<=len; i++) cout<<a[i]<<" _________  ";
       // cout<<endl;

        int q;
        scn(q);

        printf("Case %d:\n",cs);
        while(q--)
        {
            int qt, u, v;
            scn3(qt,u,v);
            u++;

            if(qt)
            {
                a[pIndex[u]] = v;
                a[nIndex[u]] = -v;

                update(1,1,len,pIndex[u]);
                update(1,1,len,nIndex[u]);
            }
            else
            {
                v++;
                int ans = query(1,1,len,1,pIndex[u]) + query(1,1,len,1,pIndex[v]);

                int lca = LCA(u,v);

                ans -= 2*query(1,1,len,1,pIndex[lca]);
                ans +=  a[pIndex[lca]];

                printf("%d\n", ans);
            }
        }

    }
    return 0;
}
