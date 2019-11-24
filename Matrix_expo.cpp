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

#define M 103

int m;

struct Matrix{
    int a[M][M];

    Matrix(){
        Fill(a,0);
    }

    Matrix operator*(const Matrix &b){
        Matrix ret;

        for(int i=1; i<=m; i++){

            for(int j=1; j<=m; j++){

                lli sum = 0;

                for(int k=1; k<=m; k++){

                    sum = (sum + (a[i][k]*1LL*b.a[k][j])) % mod;
                }

                ret.a[i][j] = sum;
            }
        }
        return ret;
    }
}mul;

Matrix Mpow(lli n){

    Matrix ret = mul; /// identity matrix

    while(n){

        if(n%2) ret = ret*mul;

        n >>= 1;
        mul = mul*mul;
    }

    return ret;
}

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);

    ///FastIO;
    lli n;
    cin>>n>>m;

    if(n<m){
        cout<<1;
        return 0;
    }

    mul.a[1][1] = mul.a[1][m] = 1;

    for(int i=2; i<=m; i++) mul.a[i][i-1] = 1;

    Matrix ans;

    mul = Mpow(n-m);

    lli res =  0;

    for(int i=1; i<=m; i++) res = (res + mul.a[1][i])%mod;

    cout<<res;

    return 0;
    ///return main();
}

///sin and cos expect input in radians not degrees. so use , sin(degrees * pi / 180)
