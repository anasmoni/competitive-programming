#include<bits/stdc++.h>
#include<cstdlib>
#include<map>

using namespace std;

char s[8000];
int a[250]={0};
int main()
{

    while(scanf("%s",s)==1)
    {

        string str; str=s;
        map<string,int>mp;

        int len=2,ans=0;
        for(int i='0' ; i<'z' ; a[i++]=0);

        for(int i=0 ; s[i] ; ++a[s[i++]]);

        for(int i='0' ; i<='z' ; i++){if(a[i])ans++;}
        //cout<<'0'<<endl;
        for(int i=0 ; s[i] ; i++)
        {
            for(int j=0 ;j+len<=strlen(s) ;j++)
            {
                string cc;
                cc = str.substr(j,len);
                reverse(cc.begin(),cc.end());

                if(str.substr(j,len)==cc){if(!mp[cc]){ans++;++mp[cc]; } }
            }

            if(len==strlen(s))break;
            len++;
        }
        cout<<"The string "<<s<<" contains "<<ans<<" palindromes.\n";


    }

    return 0;
}
