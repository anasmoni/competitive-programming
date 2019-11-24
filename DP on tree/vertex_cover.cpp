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
#define scn2ll(n,m) scanf("%lld%lld",&n,&m)
#define atoz(v) v.begin(),v.end()
#define fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define N 100005

vector<int>V[N];
int dp[N][2];

/**http://www.spoj.com/problems/PT07X/**/

void dfs(int x,int par){

    dp[x][0]=1; /** node*/
    dp[x][1]=0; /** children*/

    for(auto u : V[x]){

        if(u!=par){

            dfs(u,x);

            dp[x][1] += dp[u][0]; /** taking children**/
            dp[x][0] += min(dp[u][0],dp[u][1]); /** min of child and grand_child**/
        }
    }
}

int main()
{
    int n;
    scn(n);

    for(int i=1; i<n; i++){
        int u,v;
        scn2(u,v);
        V[u].pb(v);
        V[v].pb(u);

    }

    dfs(1,-1);
    printf("%d",min(dp[1][1],dp[1][0]));


    return 0;
}

/**
3
1 2
2 3

5
1 2
2 3
3 4
4 5
*/
