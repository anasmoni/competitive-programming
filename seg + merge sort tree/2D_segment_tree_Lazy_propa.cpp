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

int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int NN,int pos)
{
    return (bool)(NN & (1<<pos));
}

///https://codeforces.com/contest/242/problem/E
/** given an array (1<=a[i]<=1e6 , n<=1e5)
query q<=5*1e4

query type 1 -> given l,r -> print sum of [l,r] segment
      type 2 -> given l,r,x -> for all i (l<=i<=r) do a[i] = a[i]^x

*/

#define N 100005

int tree[21][4*N], prop[21][4*N], a[N];

void build(int idx, int lo, int hi, int i)
{
    if(lo == hi)
    {
        tree[i][idx] = check(a[lo],i);

        return;
    }

    int mid = (lo+hi)/2;
    int L = idx*2;
    int R = L+1;

    build(L,lo,mid,i);
    build(R,mid+1,hi,i);

    tree[i][idx] = tree[i][L] + tree[i][R];
    /// tree[i][idx] = no of set bits in ith position of integers lying between [lo,hi] range

}

void propaGate(int i , int idx , int lo , int hi){

    int L = idx*2;
    int R = L+1;

    tree[i][idx] = (hi-lo+1) - tree[i][idx];

    if(lo<hi){

        prop[i][L] ^= prop[i][idx];
        prop[i][R] ^= prop[i][idx];
    }

    prop[i][idx] = 0;
}

int query(int idx, int lo, int hi,int l,int r, int i)
{
    if(prop[i][idx]) propaGate(i,idx,lo,hi);

    if(hi<l || r<lo) return 0;

    if(l<=lo && hi<=r) return tree[i][idx];

    int mid = (lo+hi)/2;
    int L = idx*2;
    int R = L+1;

    int X = query(L,lo,mid,l,r,i);
    int Y = query(R,mid+1,hi,l,r,i);

    tree[i][idx] = tree[i][L] + tree[i][R];

    return (X+Y);
}

void update(int idx, int lo, int hi,int l,int r, int i)
{
    if(prop[i][idx]) propaGate(i,idx,lo,hi);

    if(hi<l || r<lo) return;

    if(l<=lo && hi<=r)
    {
        prop[i][idx] ^= 1;

        propaGate(i,idx,lo,hi);

        return;
    }

    int mid = (lo+hi)/2;
    int L = idx*2;
    int R = L+1;

    update(L,lo,mid,l,r,i);
    update(R,mid+1,hi,l,r,i);

    tree[i][idx] = tree[i][L] + tree[i][R];

}

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    /*
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    */

    int n;
    scn(n);

    for(int i=1; i<=n; i++) scn(a[i]);

    for(int i=0; i<=20; i++)
    {

        build(1,1,n,i);
    }

    int m;
    scn(m);

    for(int type,l,r,x ; m ; m--)
    {

        scn(type);

        if(type == 1)
        {
            scn2(l,r);

            lli ans=0;

            for(int pos=0; pos<=20; pos++)
            {
                ans += (1LL<<pos)*1LL*query(1,1,n,l,r,pos);
            }
            printf("%lld\n",ans);
        }
        else
        {
            scn3(l,r,x);

            for(int pos=0; x ; x = x>>1)
            {

                if(x&1){

                    update(1,1,n,l,r,pos);
                    //cout<<tree[pos][1]<<" --------tree-----------pos  "<<pos<<endl;
                }
                pos++;
            }
        }
    }

    return 0;
}
