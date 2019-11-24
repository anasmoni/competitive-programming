#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,x,y,z;

    cin>>a>>b>>c>>x>>y>>z;

    a -= x , b -= y , c -= z ;

    int add = (a<0)*a + (b<0)*b + (c<0)*c ;

    int sum = (a>0)*a/2 + (b>0)*b/2 + (c>0)*c/2 ;

    add += sum ;

    if(add>=0)cout<<"YES";
    else cout<<"NO";

    return 0;
}
