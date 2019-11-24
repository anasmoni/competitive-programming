#include<bits/stdc++.h>
using namespace std;
#define inf 10000009

int n,ox, nit ,tc, oxnit[1007][3] , dp[1007][25][83] , temp[1007][25][83];

/** http://www.spoj.com/problems/SCUBADIV/ **/

int fun(int i , int oxi , int nitro){

    if((oxi>= ox && nitro>=nit))return 0;
    if(i>n)return inf;

    if(oxi>=ox)oxi=ox;
    if(nitro>=nit)nitro=nit;

    if(temp[i][oxi][nitro]==tc)return dp[i][oxi][nitro];
    temp[i][oxi][nitro] = tc;

    return dp[i][oxi][nitro] = min( fun(i+1,oxi,nitro) , fun(i+1,oxi+oxnit[i][0] , nitro + oxnit[i][1]) + oxnit[i][2] );
}

/**
# 3D dp   using memset -> TLE...........take 3d temp array to handle it

# 2 base cases

(1)   if((oxi>= ox && nitro>=nit))return 0;

(2)   if(i>n)return inf; (1 indexing)

return dp[][][] = min( don't take ith , take ith )
**/

int main()
{
    int t;
    scanf("%d",&t);

    for( tc=1 ; tc<=t ; ++tc){

        scanf("%d%d%d",&ox,&nit,&n);

        for(int i=1 ; i<=n ; i++){
            scanf("%d%d%d",&oxnit[i][0],&oxnit[i][1] ,&oxnit[i][2]);
        }

        //memset(dp,-1,sizeof(dp));

        printf("%d\n",fun(1,0,0));
    }

    return 0;
}
