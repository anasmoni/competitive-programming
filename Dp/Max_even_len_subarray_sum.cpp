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

///https://csacademy.com/contest/archive/task/max-even-subarray/statement/

lli dp[ten(5)+7];

int main(){

    int n , last=0;
    scn(n);
    lli a[n+1] , ans = -tenll(18);


    for(int i=1; i<=n; i++)scnll(a[i]);

    for(int i=n-1; i>=1; i--){
        dp[i] = a[i]+a[i+1] + max(0LL,dp[i+2]);
        ans = max(ans,dp[i]);
    }
    cout<<ans;
    return 0;
}
