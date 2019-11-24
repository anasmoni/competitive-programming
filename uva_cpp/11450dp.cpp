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

int price[25][25], dp[211][25], ger, budget;

int shop(int money, int g){

    if(money<0) return -inf;

    if(g==ger) return budget - money;

    if(dp[money][g]!=-1) return dp[money][g];

    int ans=-1;

    for(int i=1 ; i<= price[g][0]; i++)
        ans = max(ans, shop(money-price[g][i],g+1) );

    return dp[money][g] = ans;
}

int main(){

    int t;
    scn(t);

    while(t--){

        int money, g;
        scn2(money,g);
        budget = money;
        ger=g;

        for(int i=0 ; i<g; i++){

            scn(price[i][0]);

            for(int j=1; j<= price[i][0]; j++) scn(price[i][j]);
        }

        fill(dp,-1);
        int x = shop(money,0);

        if(x<0)cout<<"no solution\n";
        else printf("%d\n",x);
    }



    return 0;
}
