#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n , a[15] , mark=1 ,ans=0 ;
    while(scanf("%d",&n)==1)
    {
        if(!n)break;

        for(int i=1234  ; i*n<=98765 ; i++)
        {
            if(i*n < 10000 )continue;

            for(int k=0 ; k<=9 ; k++)a[k]=0 ;
            if(i<10000)++a[0];

            for(int j=i*n , m=i ; j ; j/=10 , m/=10 )
            {
                ++a[j%10];
                if(m)++a[m%10];
                if(a[m%10]>1 || a[j%10]>1)mark=0;
            }

            if(mark)
            {
                i<10000 ? cout<<(i*n)<<" / "<<"0"<<i<<" = "<<n<<endl : cout<<(i*n)<<" / "<<i<<" = "<<n<<endl;
                ans=1 ;
            }
            mark=1;
        }
        if(!ans)cout<<"There are no solutions for "<<n<<endl;
        ans=0 ;
    }

    return 0 ;
}
