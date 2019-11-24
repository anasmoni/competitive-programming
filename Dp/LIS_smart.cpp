#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vec;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define scn(n) scanf("%d",&n)
#define scn2(n,m) scanf("%d%d",&n,&m)
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


int main()
{
    int t;
    scn(t);

    while(t--){

        int n;
        scn(n);
        int a[n],dp[n+1];

        for(int i=0; i<n; i++){
            scn(a[i]);
            dp[i]=inf;
        }

        dp[0]=-inf;
        dp[n]=inf;
        int lis=-1;

        for(int i=0; i<n; i++){
            int idx = lower_bound(dp,dp+n+1,a[i])-dp;
            dp[idx]=a[i];
            lis = max(lis,idx);
        }

        printf("%d\n",lis);
    }


    return 0;
}
/*
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
*/
