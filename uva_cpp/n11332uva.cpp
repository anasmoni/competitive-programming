#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int sum=0 ;
        if(!n)break;
        while(1)
        {
            for(;n;n /= 10 )sum += n%10 ;
            if(sum<10){ cout<<sum<<endl; break ;}
            else n=sum , sum=0 ;
        }
    }
}
