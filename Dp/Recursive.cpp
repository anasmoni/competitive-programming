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
#define N 103

int dp[N][N][3],k1,k2 , mod=1e8;
/// http://codeforces.com/problemset/problem/118/D
int fun(int n1 , int n2 , bool isfoot){

    if(!n1 && !n2)return 1;
    if(!n1 && isfoot)return 0; /// it's time to place footmen ...but their is no footmen
    if(!n2 && !isfoot)return 0; /// it's time to place horsemen ...but their is no horsemen

    if(dp[n1][n2][isfoot]!=-1)return dp[n1][n2][isfoot];

    int ret=0;

    if(isfoot){ /// taking foot
        for(int i=1; i<=k1 && n1-i>=0 ; i++){
            ret = (ret + fun(n1-i,n2,false) )%mod;///take horse in next iteration
        }
    }
    else{
        for(int i=1; i<=k2 && n2-i>=0 ; i++){
            ret = (ret + fun(n1,n2-i,true) )%mod;
        }

    }

    return dp[n1][n2][isfoot] = ret;
}

int main()
{
    int n1,n2;
    scn2(n1,n2);
    scn2(k1,k2);

    Fill(dp,-1);



    printf("%d",(fun(n1,n2,true) + fun(n1,n2,false))%mod );

    return 0;
}
