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

#define N 10000001

lli mod = 1e9+7 , dp[5] , temp[5];

///http://codeforces.com/problemset/problem/166/E

int main()
{
    int n;
    scn(n);
    dp[4]=1;

    while(n--){

        temp[4] = dp[1] + dp[2] + dp[3]; /// ways of coming from 1,2,3
        temp[3] = dp[1] + dp[2] + dp[4];
        temp[2] = dp[1] + dp[4] + dp[3];
        temp[1] = dp[4] + dp[2] + dp[3];

        for(int i=1; i<=4; i++)dp[i] = temp[i]%mod;


    }
    printf("%lld",dp[4]);

    return 0;
}
