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
#define qube(x) x*x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

void fun(int a[], int n, int wide)
{

    int dp[n+1][n+1];

    for(int i=1; i<=n; i++)
    {

        for(int j=i; j<=n ; j++)
        {

            if(i==j) dp[i][j] = wide - a[j];

            else if((a[j]+1) <= dp[i][j-1]) dp[i][j] = dp[i][j-1] - a[j] - 1 ;

            else dp[i][j] = -1;
        }
    }


    /*for(int i=1; i<=n; i++){

        for(int j=i ; j<=n; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    } */

    int ans[n+1];
    ans[0]=0;

    for(int j=1; j<=n; j++)
    {

        ans[j] = inf;

        for(int i=j; i>=1 ; i--)
        {

            if(dp[i][j]>=0 )ans[j] = min(ans[i-1] + sqr(dp[i][j]), ans[j] );
            else break;
        }
    }

    // for(int i=1 ; i<=n; i++)cout<<ans[i]<<" ";

    stack<int>stk;


    for(int i=n,j=n; i>=1 ; i--)
    {

        if(dp[i][j]>=0 && (ans[j] == ans[i-1] + sqr(dp[i][j])) )
        {
            stk.push(j);
            stk.push(i);
            j=i-1;
        }

    }


    while(stk.empty() == false)
    {
        cout<<stk.top()<<" ";
        stk.pop();
    }

    cout<<endl;


}

int main()
{
    int t;
    scn(t);

    while(t--)
    {

        int n,wide;
        scn(n);

        int a[n+1];

        for(int i=1 ; i<=n ; i++) scn(a[i]);

        scn(wide);

        fun(a,n,wide);

    }



    return 0;
}
