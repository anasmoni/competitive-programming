#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[500];
    while(gets(s))
    {
        int ans=0 ;
        for(int i=0 ; s[i] ; i++)
        {
            if(s[i]<='z' && s[i]>='A')
            {
                while(s[i]<='z' && s[i]>='A')i++;
                ans++ ;
            }
        }

        cout<<ans<<endl;
    }
    return 0 ;
}
