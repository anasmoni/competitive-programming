#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef unsigned long long int ulli;
typedef pair<int,int> pii;

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

///priority_queue< int, vector< int >, greater< int > > minHeap;

void mor(){cout<<"NO"; exit(0);}

const int MAX = 10004;

using bs = bitset<MAX>;

vector<int>tree[4*MAX];

///https://codeforces.com/contest/981/problem/E

bs made;

void update(int idx, int lo, int hi , int l , int r , int val){

    if(hi<l || r<lo)return;

    if(l<=lo &&  hi<=r){
        tree[idx].pb(val);
        return;
    }
    int mid = (lo+hi)/2;
    update(idx*2 , lo,mid,l,r,val);
    update(idx*2+1 , mid+1,hi,l,r,val);
}

void solve(int idx, int lo, int hi , bs make){

    for(int val : tree[idx]) make |= (make<<val); /// number of unique sums can be from

    if(lo == hi){
        made |= make;
        return;
    }
    int mid = (lo+hi)/2;
    solve(idx*2 ,lo,mid,make);
    solve(idx*2+1 ,mid+1,hi,make);
}

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);

    ///FastIO;
    int n,q;
    scn2(n,q);

    for(int i=0; i<q; i++){
        int l,r,val;
        scn3(l,r,val);
        update(1,1,n,l,r,val);
    }
    bs now;
    now[0] = 1;
    solve(1,1,n,now);

    int cnt = 0;
    for(int i=1; i<=n; i++) cnt += made[i];
    cout<<cnt<<endl;
    for(int i=1; i<=n; i++){
        if(made[i])printf("%d ",i);
    }


    return 0;
    ///return main();
}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)
