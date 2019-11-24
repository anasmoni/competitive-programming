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
#define fill(a,v) memset(a,v,sizeof(a))
#define sz(v) v.size()
#define fi first
#define se second
#define inf 1e9
#define pi acos(-1.0)
#define sqr(x) x*x
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))

int coins[107], have[107];
int mx=-1,m,V;

/***
min number of coins with constrains that u have only have[i] of ith coin
***/

void fun()
{
    int table[V+1];
    int dp[V+1][mx+1]; /// dp[i][c] = how many coins needed of type c to make i
    fill(dp,0);
    table[0] = 0;

    for (int i=1; i<=V; i++)table[i] = INT_MAX;


    for (int i=1; i<=V; i++)
    {
        int taken=-1,d;

        for (int j=0; j<m; j++){

            if (coins[j] <= i)
            {
                int diff = i-coins[j];
                int x = table[diff];

                if(dp[diff][coins[j]]+1 > have[j])continue; /// number of coins of type j been used to make diff

                if (x != INT_MAX && x + 1 < table[i]){
                    table[i] = x + 1;
                    taken = coins[j];
                    d=diff;
                }
            }

        }

        if(taken!=-1){

            for(int ii,k=0; k<m; k++){
                ii = coins[k];
                if(ii==taken)dp[i][ii] = dp[d][ii]+1;
                else dp[i][ii] = dp[d][ii];
            }
        }
    }

    if(table[V]==INT_MAX){
        cout<<"IMpossible\n";
        return ;
    }

    cout<<table[V]<<endl;

    for(int x = 0; x<m; x++){
        int xx = coins[x];
        if(dp[V][xx])cout<<xx<<"*"<<dp[V][xx]<<endl;
    }
}

int main()
{
    cin>>V>>m;

    for (int i = 0; i < m; i++){
        cin>>coins[i];
        mx = max(coins[i],mx);
    }

    for (int i = 0; i < m; i++)cin>>have[i];

    fun();
}

/***
80 9
1 2 5 10 20 50 100 500 1000
100 10 1 0 10 5 10 5 2

80 9
1   2  5 10 20 50 100 500 1000
100 10 1 0  1  5  10   5   2

80 9
1   2  5 10 20 50 100 500 1000
100 10 1 0  1  0  10   5   2

80 8
   2  5 10 20 50 100 500 1000
 10 1 0  1  0  10   5   2

**/
