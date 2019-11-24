#include<bits/stdc++.h>
using namespace std;

int main()
{
    while(1)
    {
        string a,b; // have to convert a to b....how many ways are there
        cin>>a>>b;
        int sa = a.size(), sb = b.size();
        int dp[sb+1][sa+1];

        for(int i=0 ; i<=sb; i++)
        {

            bool yup=false;

            for(int j=0 ; j<=sa; j++)
            {

                if(!i) dp[i][j]=1;
                else if(!j) dp[i][j]=0;
                else
                {

                    if(b[i-1] == a[j-1])
                    {
                        dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                    }
                    else dp[i][j] = dp[i][j-1];
                }
                if(dp[i][j])yup=true;

            }
            if(!yup)
            {
                cout<<"Impossible\n";
                sa=-1;
                break;
            }
        }

        if(sa!=-1)cout<<dp[sb][sa]<<endl;
    }
    return 0;
}
