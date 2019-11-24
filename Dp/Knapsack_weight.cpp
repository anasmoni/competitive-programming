#include<bits/stdc++.h>
using namespace std;

int ans;

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0)
                K[i][w] = 0;
            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w];
        }
    }

    ans=W;

    for( ; K[n][ans] == K[n][W] ; ans--);
    ++ans; /** thats the weight we actually taken but if K[n][W] == 0 then ans =0 */

    return K[n][W];
}

int main()
{
    while(true){
        int W,n;
        scanf("%d%d",&W,&n);

        if(!W && !n)break;

        int val[n] , wt[n];

        for(int i=0 ; i<n ; i++){
            scanf("%d%d",&wt[i],&val[i]);
        }
        int x =  knapSack(W, wt, val, n);
        if(!x)ans=0;
        printf("%d %d\n",ans , x);

        /**
            --------IT'S OKEY TOO-------but take more time

        int x = knapSack(W,n);
        int lo=0 , hi=W , mid;

        while(lo<hi){
            mid = (lo+hi)/2;
            if(knapSack(mid,n)<x)lo=mid+1;
            else  hi = mid;
        }

        printf("%d %d\n",lo , x);

        **/
    }
    return 0;
}
