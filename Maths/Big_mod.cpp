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

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

/// for upto 10^18

template <typename T>
T mmul(T a, T b, T m) {
    a %= m;
    T result = 0;
    while (b) {
        if (b % 2) result = (result + a) % m;
        a = (a + a) % m;
        b /= 2;
    }
    return result;
}

template <typename T>
T mpow(T a, T b, T m) {
    a %= m;
    T result = 1;
    while (b) {
        if (b % 2) result = mmul(result, a, m);
        a = mmul(a, a, m);
        b /= 2;
    }
    return result;
}

/// for int

template <typename T>
T mod(T a, T b, T c)
{
    if(b==0) return 1;

    if(b%2==0)
    {
        T x=mod(a,b/2,c);
        return (x%c*x%c)%c; /// to avoid overflow as may x >= 10^10
    }
    else return (a%c * mod(a,b-1,c))%c;
}

int main()
{
    ///freopen("output.txt","w",stdout);
    ///freopen("input.txt","r",stdin);
    /*
     ios_base::sync_with_stdio(false);
    cin.tie(0);
    */




    return 0;
}
