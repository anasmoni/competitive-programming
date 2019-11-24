#include<bits/stdc++.h>
using namespace std;

int ans,k,n , a[1007] , dp[1007][1007];

/// http://www.spoj.com/problems/RPLB/ */

int fun(int i , int kk){

    if(i>n)return 0;
    if(dp[i][kk]>=0)return dp[i][kk];
    int x=0,y=0;

    if(kk+a[i] <=k)x = a[i] + fun(i+2,kk+a[i]);
    y = fun(i+1,kk);

    return dp[i][kk] = max(x,y);

}

int main()
{
    int t;
    scanf("%d",&t);

    for(int tc=1 ; tc<=t ; ++tc){

        scanf("%d%d",&n,&k);

        for(int i=1 ; i<=n ; scanf("%d",&a[i++]));

        memset(dp,-1,sizeof(dp));
        ans = fun(1,0);

        printf("Scenario #%d: %d\n",tc,ans);
    }

    return 0;
}
