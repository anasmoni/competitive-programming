#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,t;
    scanf("%d%d",&n,&t);
    char s[n+1];
    scanf("%s",s);

    for(i=0 ; s[i]; i++)
    {
        if(s[i]=='.')break;
    }

    for(++i ; s[i]; i++)
    {
        if(s[i]>='5')
        {
            s[i]='\0' ;
            break;
        }
    }

    if(i==n){cout<<s; return 0;}

    for(--i; i>=0 && t ; i--)
    {
        if(s[i]=='.')
        {
            s[i]='\0';
            if(s[i+1]>='5' || s[i+1]=='\0')
            {
                i--;
                if(s[i]<'9')s[i]++;
                else
                {
                    int nine=i;
                    while(s[i]=='9')i--;
                    if(i>=0){s[i]++;i++;}
                    else i=1,nine++,s[0]='1';
                    while(i<=nine){s[i]='0';i++;}
                }
            }
            cout<<s; return 0;
        }
        else if(s[i]<'5')
        {
            s[i]++; t-- ;
            if(s[i]>='5'&& t)s[i]='\0';
            else{cout<<s; return 0;}
        }

    }

    cout<<s;



    return 0;
}

