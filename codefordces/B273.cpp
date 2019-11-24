#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n , inb=0 , len=0 ,mark=0 , last=0 ;
    cin>>n ;
    char s[n+1] ;
    scanf("%s",s);

    for(int i=0 ; s[i] ; i++)
    {
        if(s[i]=='(')
        {
            int k=i;
            mark = i;
            for(++i ; s[i] ; i++)
            {
                if((s[i]=='_'||s[i]==')')){if(i-1!=k){inb++;} k = i;}
                if(s[i]==')' )
                {
                    last = i ;
                    break;
                }
            }
        }

        if(s[i]=='_'||(i==0 && s[i]!='(') || s[i]==')' && (mark<i || last<i))
        {
            int k=i ;
            for(++i ; s[i] ; i++)
            {
                if((s[i]=='_'||s[i]=='(') || i==strlen(s)-1 )
                {
                    if(len<i-k && (i-k)>1)
                    {
                        if(i!=strlen(s)-1 )len = i-k-1 ;
                        else len  = i-k;
                    }
                    k = i;
                }
                if(s[i]=='(' )
                {
                    i--;
                    break;
                }
            }
        }
    }
    int i;
    for(i=0 ; s[i] && s[i]!='_'&& s[i]!='(' ; i++);

    if(len<i)len=i ;

    for(i=strlen(s)-1 ; i>=0 && s[i]!='_' && s[i]!=')' ; i--);

    if(len<strlen(s)-1-i)len=strlen(s)-1-i;



    cout<<len<<" "<<inb;



    return 0;
}


