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

///https://codeforces.com/contest/877/problem/E

#define N 200005

int n;
vector<int>G[N];

int light[N] , pos[N] , sub[N] , nodes[N];
int now = 1;

void dfs(int x=1 , int p = -1){

    sub[x] = 1;
    nodes[now] = x;
    pos[x] = now;
    now++;

    for(int u : G[x]){

        if(p == u) continue;

        dfs(u,x);

        sub[x] += sub[u];
    }
}

int tree[N*3];
int prop[N*3];

void build(int idx, int lo, int hi)
{
    if(lo == hi)
    {
        tree[idx] = light[nodes[lo]];
        //cout<<tree[idx]<<" ppp "<<nodes[lo]<<endl;
        return;
    }

    int mid = (lo+hi)/2;
    int L = idx*2;
    int R = L+1;

    build(L,lo,mid);
    build(R,mid+1,hi);

    tree[idx] = tree[L] + tree[R];
}

void propaGate(int idx , int lo , int hi){

    if(prop[idx]==0) return;

    int L = idx*2;
    int R = L+1;

    tree[idx] = (hi-lo+1) - tree[idx];

    if(lo<hi){

        prop[L] ^= prop[idx];
        prop[R] ^= prop[idx];
    }

    prop[idx] = 0;
}

int query(int idx, int lo, int hi,int l,int r)
{
    propaGate(idx,lo,hi);

    if(hi<l || r<lo) return 0;

    if(l<=lo && hi<=r) return tree[idx];

    int mid = (lo+hi)/2;
    int L = idx*2;
    int R = L+1;

    int X = query(L,lo,mid,l,r); /// tree[L] = query(L,lo,mid,l,r);
                                    ///suck...why?..line 119 we returning 0 , but tree[L] may not b 0
    int Y = query(R,mid+1,hi,l,r); /// tree[R] = query(R,mid+1,hi,l,r);

    tree[idx] = tree[L] + tree[R];

    return X+Y;
}

void update(int idx, int lo, int hi,int l,int r)
{
    propaGate(idx,lo,hi);

    if(hi<l || r<lo) return;

    if(l<=lo && hi<=r)
    {
        prop[idx] ^= 1;

        propaGate(idx,lo,hi);

        return;
    }

    int mid = (lo+hi)/2;
    int L = idx*2;
    int R = L+1;

    update(L,lo,mid,l,r);
    update(R,mid+1,hi,l,r);

    tree[idx] = tree[L] + tree[R];

}

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);

    ///FastIO;

    scn(n);

    for(int i=2; i<=n; i++){
        int x;
        scn(x);
        G[x].pb(i);
    }

    for(int i=1; i<=n; i++) scn(light[i]);

    dfs();
    build(1,1,n);

    int q;
    scn(q);
    char op[4];
    int node;

    while(q--){
        scanf("%s %d",op,&node);

        if(op[0] == 'p'){
            update(1,1,n,pos[node],pos[node]+sub[node]-1);
        }
        else{
            printf("%d\n",query(1,1,n,pos[node],pos[node]+sub[node]-1));
        }
    }



    return 0;
    ///return main();
}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)
