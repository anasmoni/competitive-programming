#include<bits/stdc++.h>

using namespace std;


int main()
{
    char s[454574] ;
    int k , l , i=0,j ;

    while(gets(s))
    {
        for(i=0; s[i] ;)
        {
            k=i;
            while(s[i++]);
            if(!k)j=i-2;
            else j=i-1;
            if(s[i]=='\0' && k)cout<<" " ;
            if(s[i]=='\0' && !k)j = i-1 ;

            while(j>=k)cout<<s[j--];

        }

        cout<<endl;

    }

    return 0 ;
}
