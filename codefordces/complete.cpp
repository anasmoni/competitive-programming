#include<bits/stdc++.h>
#include<algorithm>
#include<string>

using namespace std;
char s[500005] ;

int main()
{
    gets(s);

    for(int i=0 ; i+25<strlen(s) ; i++)
    {
        int a[26],mark=7 ;
        for(int d=0 ; d<26 ; a[d++]=0);

        for(int j=0 ; j<26; j++){ if(a[s[j+i]-'A']++ && s[j+i]!='?')mark=0; }

        if(mark)
        {
            for(int j=0 ; j<26 ; j++)
            {
                if(s[i+j]=='?') {for(int k=0 ; k<26 ; k++){ if(!a[k]++){ s[i+j]=k+'A' ; break ;} }}
            }
            for(i=0 ; s[i] ; i++){ s[i]!='?' ? cout<<s[i] : cout<<'A'; }
            return 0;
        }
    }
    cout<<"-1";
    return 0 ;
}
