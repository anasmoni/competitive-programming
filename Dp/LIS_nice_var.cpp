#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<int,int> pii;
typedef long long ll;
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

/**http://lightoj.com/volume_showproblem.php?problem=1277*/

const int NX = 2e5 + 10 ;
const ll INF = 2e18 + 10 ;
ll inp[NX] , dp[NX] , L[NX] ;
int n , q ;

bool solve( int lim )
{
    bool ok = 0 ;
    ll prv ;

    for(int i=0; i<n; i++)
    {
        if( L[i] >= lim )//L[i]= max incresing sub seq using inp[i] as the first element
        {
            if( ok && inp[i] <= prv ) continue ;
            if( ok ) printf(" ");

            printf("%lld",inp[i]);
            prv = inp[i] ;
            ok = 1 ;
            lim--;
        }

        if(lim == 0 ) break ;// we r done with printing LIS of size:lim...so break
    }
    return ok;
}


int main()
{
   int cs , t;
   scn(t);

    for ( cs =  1 ; cs <= t ; cs++ )
    {
        scn2(n,q);

        for(int i=0; i<n; i++)
        {
            scanf("%lld",&inp[i]);
            dp[i] = INF ;
        }


        int low , i , j ;
        dp[0] = -INF ;
        dp[n] = INF ;

        for ( i = n - 1 ; i >= 0 ; i-- )
        {
            low = lower_bound( dp , dp + n + 1 , -inp[i] ) - dp ;
            dp[low] = -inp[i];
            L[i] = low ;
        }

        printf("Case %d:\n",cs);

        while(q--)
        {
            int x;
            scn(x);

            if( solve(x) == 0 ) printf("Impossible\n");
            else cout<<endl;
        }
    }

    return 0;
}

/**
2     3    4    1    2    3
-inf  inf  inf  inf  inf   inf  inf
       -3
            -2
                -1

        -4
            -3
                -2

L[] = 3,2,1,3,2,1
*/
