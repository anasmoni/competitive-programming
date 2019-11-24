#include<bits/stdc++.h>
using namespace std;

#define mod 100000007

int n , K;
int dp[55][1004];
int coin[55];
int mtake[55];

int change (int i , int a)
{
    if (i >= n)
    {
        if (a == K) return 1;
        else return 0;
    }
    if (a > K) return 0;
    if (dp[i][a] != -1) return dp[i][a];
    int tt = 0;

    for (int ii = 1; ii <= mtake[i]; ii++)
    {
        if (a + coin[i] * ii <= K)tt += change (i + 1 , a + coin[i] * ii) % mod;
        else break;
    }
    tt += change (i + 1 , a) % mod;
    dp[i][a] = tt % mod;
    //cout<<a<<" aa\n";
    return dp[i][a];
}

int main ()
{
    int T;
    scanf ("%d" , &T);
    int i;
    for (i = 1; i <= T; i++)
    {
        memset (dp , -1 , sizeof (dp));
        scanf ("%d%d" , &n , &K);

        for (int ii = 0; ii < n; ii++)scanf ("%d" , coin + ii);
        for (int ii = 0; ii < n; ii++)scanf ("%d" , mtake + ii);

        printf ("Case %d: %d\n" , i , change (0 , 0) % mod);

    }
}
