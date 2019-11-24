#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

int main()
{
    char s[1000];
    while(gets(s))
    {
        if(atoi(s)==0)break;
        int sum=0 ;
        while(1)
        {
            for(int i=0 ; s[i] ; i++)
            {
                char x[1];
                x[0] = s[i];
                sum += atoi(x);
            }
            if(sum<10)
            {
                cout<<sum<<endl;
                break;
            }
            else
            {
                itoa(sum,s,10);
                sum=0 ;
            }
        }
    }
    return 0 ;

}
