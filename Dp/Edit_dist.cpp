#include<bits/stdc++.h>
using namespace std;

string s,make;
int t,ss,ms;
/// minimum number of operations needed to convert s to make
int edits()
{

    int dp[ss+1][ms+1];

    for(int i=0 ; i<=ss; i++)
    {

        for(int j=0; j<=ms; j++)
        {

            if(!i) dp[i][j] = j;   ///num of operations to convert empty string to (string of len j) = j

            else if(!j) dp[i][j] = i; ///num of operations to convert (string of len i) to empty string  = i

            else if(s[i-1]==make[j-1]) dp[i][j] = dp[i-1][j-1]; /// match found so no operation needed

            else dp[i][j] = 1+min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1]);

            /// add (dp[i][j-1]+1),delete( dp[i-1][j]+1 ),or replace ( dp[i-1][j-1]+1)
        }
    }

    return dp[ss][ms];
}


int main()
{
    scanf("%d",&t);

    while(t--)
    {
        cin>>ss>>ms;
        cin>>s>>make;

        cout<<edits()<<endl;
    }
    return 0;
}
