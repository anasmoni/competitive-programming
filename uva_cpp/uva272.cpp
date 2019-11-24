#include<bits/stdc++.h>

using namespace std;

int main()
{
    char s[10000];
    int x=0 , d=0 ;

    while(gets(s))
    {
        for(int i=0 ; s[i] ; i++)
        {
            if(s[i]=='"')
            {
                if(!x)cout<<"``" , x = 1 , d=0 ;
                else if(!d)cout<<"''" , d=1 , x=0 ;
            }
            else printf("%c",s[i]) ;

        }
        cout<<endl;
    }



    return 0 ;
}
