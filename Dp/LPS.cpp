#include<bits/stdc++.h>
using namespace std;

string s;
int dp[1000][1000];

inline bool cond(int i, int idx)
{

    return (s[i]==s[idx] && dp[i+1][idx-1] == idx-i-1);

    /**
    //longest pal subsequence....

     return (s[i]==s[idx]);
    */
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {//forgeeksskeegfor

        //cout<"x for exit....\n";

        cin>>s;
        //if(s=="x")break;
        int len=s.size();

        for(int l=1; l<=len; l++)
        {
            for(int i=0 ; (i+l)<=len; i++)
            {
                int idx = l+i-1;

                if(l==1)dp[i][i]=1;
                else
                {
                    //cout<<i<<" "<<idx<<" "<<l<<endl;
                    dp[i][idx] = max(dp[i][idx-1], dp[i+1][idx]);

                    dp[i][idx] = max(dp[i][idx] , dp[i+1][idx-1] + 2*cond(i,idx));
                }
            }
        }

       /* for(int i=0 ; i<len ; i++)
        {
            for(int j=0 ; j<len; cout<<dp[i][j++]<<" ");
            cout<<endl;
        }*/

        cout<<dp[0][len-1]<<endl; // len of lp substring/subseq


       //print lp substring ....
       string lp;

        if(dp[0][len-1]==1){cout<<s[0]<<endl;continue;}

        int ln=len-1;

        for(--len; len>0; len--){

            if(dp[0][len]!=dp[0][len-1]){
                lp = s.substr(len+1-dp[0][ln],dp[0][ln]);
                break;
            }
        }
        cout<<lp<<endl;

    }


    return 0;
}
