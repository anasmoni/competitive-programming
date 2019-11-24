#include <bits/stdc++.h>

using namespace std;
int dp[27][100005];

///https://csacademy.com/contest/archive/task/max-substring/

/// u have to print substr with max freq with max len and lexicographically smallest.......
/// cabdab - ab
/// abcabdfdfg - ab
/// aass - aa
/// cadcac - c

int main()
{

    string s,ans;
    cin>>s;

    int a[27], cnt=0, n = s.size();

    for(int i=0; i<=26; i++)a[i]=0;

    for(int i=0; i<n; i++)
    {

        a[s[i]-'a'+1]++;

        cnt = max(cnt,a[s[i]-'a'+1]);  /// max freq == max freq char in s
    }

    int mx=-1, cc=0;

    for(int c=1; c<=26 ; c++)
    {

        if(a[c]<cnt)continue; /// c != 1st char of our ans

        int curr=0, flag=0;

        for(int x,i=0 ; i<n; i++)
        {

            x = s[i]-'a'+1;

            if(x == c)
            {
                flag++;
                if(curr)dp[c][curr]=-1 ; /// abcababc.....here should be  a -> b , -1
                curr=1;
            }

            else if(curr)
            {

                if(flag==1)dp[c][curr++] = x;

                else if(dp[c][curr]!=x) dp[c][curr]=-1;

                else curr++;
            }
        }

        dp[c][curr]=-1;

        if(curr > mx) /// curr = len
        {

            mx = curr;
            cc = c;

        }
    }


    ans += (char)('a'+cc-1);

    for(int i=1 ; dp[cc][i]>0 ; i++) ans += (char)('a'+dp[cc][i]-1);

    cout<<ans;

    return 0;
}
