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
#define ten(n) (int)1e##n
#define tenll(n) (lli)1e##n

///https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1630 ---- Uva - 10689

/// for this problem sequence start with a,b whereas in fibonacci a=0,b=1

/// Pisano period : Where the last 1/2/3/4 digits of a
///fibonacci number repeats with a period of 60/300/1500/15000 respectively

int main()
{
    int t;
    scn(t);
    int mod[5] = {0,10,100,1000,10000};
    int period[5] = {0,60,300,1500,15000};

    while(t--){

        int a,b,n,m;
        scn3(a,b,n);
        scn(m);
        int res[period[m]] = {a%mod[m],b%mod[m]};

        for(int i=2; i<period[m] ; i++){
            res[i] = (res[i-1] + res[i-2])%mod[m];
        }

        cout<<res[n%period[m]]<<endl;
    }
    return 0;
}
