#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0) K[i][w] = 0;  ///maximum profit obtain with 0 items or 0 weight = 0

            else if (wt[i-1] <= w)
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]);
            else
                K[i][w] = K[i-1][w]; /// max profit obtain with i items and w weight (without taking ith item)
        }
    }

    /*for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            printf("%d ",K[i][w]);
        }
        puts("\n");
    }*/

    return K[n][W];
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {5, 10,15};
    int W = 20;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d", knapSack(W, wt, val, n));
    return 0;
}
