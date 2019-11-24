#include<bits/stdc++.h>
using namespace std;

int n,len,cnt,i,b;
char s[420];

bool ischar(char c){ return (c>='A'&&c<='Z')||(c<='z'&&c>='a');}

int main()
{
    cin>>n>>s+1 ;


    for(i=1 ; i<=n ; i++)
    {
        b += (s[i]=='(') ; b -= (s[i]==')') ;

        if(ischar(s[i]))
        {
            int k=i;
            for(;ischar(s[i]);i++);
            if(b)cnt++;
            else if(i-k>len)len=i-k;
            i--;
        }
    }

    cout<<len<<" "<<cnt;


    return 0;
}
