#include<iostream>
#include<cstdio>
using namespace std ;
long long int a , b , i , ans , t  ;
long long int three_n(long long int c ,long long int n)
{
    while(n>1)
    {
        if(!(n%2))c++ ,  n /= 2 ;
        if(n==1)break;
        if(n%2)c++ , n = n*3 + 1;
    }
    return c ;
}


int main()
{
    while(1)
    {
        scanf("%I64d%I64d",&a,&b);
        for(i=a ; i<=b ; i++)
        {
            t = three_n(1,i);
            if(t>ans)ans = t ;

        }
        printf("%I64d %I64d %I64d\n",a,b,ans);
    }
    return 0 ;
}
