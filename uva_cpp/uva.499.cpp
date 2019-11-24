#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[125];
    while(gets(s))
    {
        int c=0 , mx=-1 , k=0 , mark=0 ;
        char x[55];
        for(int i=0 ; s[i] ; i++)
        {
            for(int j=0 ; s[j] ; j++)if(s[i]==s[j] && s[i]!=' ')c++;
            if(mx<=c)
            {
                if(mx<c)x[0]='\0' , k=0 ;
                mx = c;
                x[k++] = s[i];
            }
            c=0;
        }

        sort(x,x+k);
        for(int i=0 ; i<k && x[i]!=' ' ; i++)
        {
            if(!i)cout<<x[i];
            else if(x[i]!=x[i-1])cout<<x[i];
        }

        if(x[0]!=' ')cout<<" "<<mx<<endl ;
        else cout<<"0"<<endl;

    }
    return 0 ;
}
