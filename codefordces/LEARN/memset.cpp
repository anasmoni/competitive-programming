#include<bits/stdc++.h>
using namespace std;
char s[50000];
int main()
{
    int i,j,k,l,t[26],same ;

    scanf("%s",s);

    for(i=0 ; i+25<strlen(s) ; i++)
    {
        memset(t,0,sizeof(t)); same=7; /** learn */

        for(j=0 ; j<26 ; j++)if(s[i+j]!='?' && t[s[i+j]-'A']++)same=0;

        if(same)
        {
            for(j=0 ; j<26 ; j++)
            {
                if(s[i+j]=='?')
                {
                    for(k=0 ; k<26 ; k++)
                    {
                        if(!t[k]++){ s[i+j]=k+'A';break;}
                    }
                }
            }
            for(j=0 ; s[j] ; j++)s[j]!='?' ? cout<<s[j] : cout<<'A'; /** learn */
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}
