#include<bits/stdc++.h>

using namespace std;

/**http://www.lightoj.com/volume_showproblem.php?problem=1110**/

string s,t;
int m,n,len;
int dp[111][111];
string str[111][111];

void LCS()
{
    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ; j<=m ; ++j)
        {
            if(!i || !j)
            {
                dp[i][j]=0;
                str[i][j]="";
            }

            else if(s[i-1]==t[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                str[i][j] = str[i-1][j-1] + s[i-1];
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j];
                str[i][j]=str[i-1][j];
            }
            else if(dp[i][j-1]>dp[i-1][j])
            {
                dp[i][j]=dp[i][j-1];
                str[i][j]=str[i][j-1];
            }
            else
            {
                dp[i][j]=dp[i-1][j];
                str[i][j]=min(str[i-1][j],str[i][j-1]);
            }
        }
    }

    /* for(int i=0 ; i<=m ; i++)
    {
        for(int j=0 ; j<=n ; ++j)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/


    if(dp[n][m]==0)cout<<":(";
    else cout<<str[n][m];
    cout<<endl;
}


int main()
{

    int tt;
    scanf("%d",&tt);

    for(int tc=1 ; tc<=tt ; ++tc)
    {
        cin>>s>>t;
        n=s.size();
        m=t.size();

        printf("Case %d: ",tc);
        LCS();
    }
    return 0;

}
