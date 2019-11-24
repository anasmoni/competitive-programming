#include<bits/stdc++.h>
using namespace std;
long long int a,b,ans;
// a mod ans = b
int main()
{
    scanf("%I64d%I64dd",&a,&b);
    if(a==b){cout<<"infinity"; return 0;}
    if(a<b){cout<<0; return 0;}
    for(int i= 1 ; i*i<=(a-b) ; i++)ans += ((a-b)%i==0 && i>b) + ((a-b)%i==0 && (a-b)/i>b && i*i!=a-b);

    printf("%I64d\n",ans);




    return 0;
}
