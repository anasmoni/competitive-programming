#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;

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


int main(){

    int t;
    scn(t);

    while(t--){

        int n;
        scn(n);

        int a[n];

        for(int i=0 ; i<n; scn(a[i++]));

        int dp[n][n];

        for(int i=0 ; i<n; i++) dp[i][i] = a[i];

        for(int i=n-2 ; i>=0 ; i--){

            for(int j=i+1; j<n; j++){

                if(a[i] < a[j]) dp[i][j] = max(dp[i][j-1], a[i]+dp[j][n-1]);
                else dp[i][j] = dp[i][j-1];

            }
        }

        int mx=-1;

        for(int i=0 ; i<n; i++){
            mx = max(mx, dp[i][n-1]);
        }

        printf("%d\n",mx);
    }

    return 0;
}

