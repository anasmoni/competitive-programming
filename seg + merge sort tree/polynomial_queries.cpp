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

struct Node{
    lli inc,sum,prop;
};

Node tree[N*3];
lli a[N] ,n;

void build(int idx, int lo, int hi)
{
    if(lo == hi)
    {
        tree[idx].sum = a[lo];
        tree[idx].inc = tree[idx].prop = 0;
        return;
    }

    int mid = (lo+hi)/2;
    int L = idx*2;
    int R = L+1;

    build(L,lo,mid);
    build(R,mid+1,hi);

    tree[idx].sum = tree[L].sum + tree[R].sum;
    tree[idx].inc = tree[idx].prop = 0;
}

lli SUM(lli x){
    x *= (x+1);
    x /= 2;
    return x;
}

void propaGate(int idx , int lo , int hi){

    if(tree[idx].inc == 0) return;

    lli L = idx*2;
    lli R = L+1;

    tree[idx].sum += tree[idx].prop * (hi-lo+1) + SUM(hi-lo)*tree[idx].inc;

    if(lo<hi){
        lli mid = (lo+hi)/2;
        tree[L].inc += tree[idx].inc;
        tree[L].prop += tree[idx].prop;
        tree[R].inc += tree[idx].inc;
        tree[R].prop += tree[idx].prop  + tree[idx].inc * (mid-lo+1);
    }
    tree[idx].inc = tree[idx].prop = 0;
}

lli query(int idx, int lo, int hi,int l,int r)
{
    propaGate(idx,lo,hi);

    if(hi<l || r<lo) return 0;

    if(l<=lo && hi<=r) return tree[idx].sum;

    int mid = (lo+hi)/2;
    int L = idx*2;
    int R = L+1;

    lli X = query(L,lo,mid,l,r); /// tree[L] = query(L,lo,mid,l,r);
                                    ///suck...why?..line 119 we returning 0 , but tree[L] may not b 0
    lli Y = query(R,mid+1,hi,l,r); /// tree[R] = query(R,mid+1,hi,l,r);

   // tree[idx].sum = tree[L].sum + tree[R].sum;
    //assert(tree[idx].inc == tree[idx].prop && tree[idx].inc == 0);
    return X+Y;
}

void update(int idx, int lo, int hi,int l,int r)
{


    if(hi<l || r<lo){
        propaGate(idx,lo,hi);
        return;
    }

    if(l<=lo && hi<=r)
    {
        tree[idx].inc++;
        tree[idx].prop += (lo-l+1);
        propaGate(idx,lo,hi);

        return;
    }
    propaGate(idx,lo,hi);
    int mid = (lo+hi)/2;
    int L = idx*2;
    int R = L+1;

    update(L,lo,mid,l,r);
    update(R,mid+1,hi,l,r);

    tree[idx].sum = tree[L].sum + tree[R].sum;
    assert(tree[idx].inc == tree[idx].prop && tree[idx].inc == 0);

}

int main()
{
    ///freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);

    FastIO;
    int q;
    cin>>n>>q;

    for(int i=1; i<=n; i++) cin>>a[i];

    build(1,1,n);

    while(q--){
        int t,l,r;
        cin>>t>>l>>r;
        if(t==1) update(1,1,n,l,r);
        else cout<<query(1,1,n,l,r)<<endl;
    }
    //cout<<(tree[1].sum)<<" "<<tree[1].inc<<" "<<tree[1].prop;


    return 0;
    ///return main();
}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)
