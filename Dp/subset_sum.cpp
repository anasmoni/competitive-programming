#include<bits/stdc++.h>
using namespace std;


int sub_sum(int sum , int n , int a[])
{

    int dp[n+1][sum+1];

    for(int i=0 ; i<=sum ; i++) dp[0][i] = 0;

    for(int i=0 ; i<=n ; i++) dp[i][0] = 1;

    for(int i=1 ; i<=n ; i++)
    {

        for(int k=1 ; k<=sum ; ++k)
        {

            if(a[i]>k) dp[i][k] = dp[i-1][k];

            else dp[i][k] = dp[i-1][k] || dp[i-1][k-a[i]];
        }
    }

    return dp[n][sum];

}


bool isSubsetSum(int set[], int n, int sum)
{
    // The value of subset[i][j] will be true if there is a
    // subset of set[0..j-1] with sum equal to i
    bool subset[n+1][sum+1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[i][0] = true;

    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[0][i] = false;

     // Fill the subset table in botton up manner
     for (int i = 1; i <= n; i++)
     {
       for (int j = 1; j <= sum; j++)
       {
         if(j<set[i-1])
         subset[i][j] = subset[i-1][j];
         if (j >= set[i-1])
           subset[i][j] = subset[i-1][j] ||
                                 subset[i - 1][j-set[i-1]];
       }
     }

     return subset[n][sum];
}

int main()
{

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        scanf("%d",&n);

        int a[n+1] , add=0 ;

        for(int i=0  ; i<n ; ++i)
        {
            scanf("%d",&a[i]);
            add += a[i];
        }
        if(add%2 || n==1)cout<<"NO\n";
        else if(isSubsetSum(a,n,add/2))cout<<"YES\n";
        else cout<<"NO";
    }


    return 0;
}

