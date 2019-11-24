#include<bits/stdc++.h>
using namespace std;
int n,h,v,V[420],H[420];
int main()
{
    cin>>n ;

    for(int i=1 ; i<=n*n ; i++)
    {
        cin>>h>>v;
        if(!H[h] && !V[v]){cout<<i<<" "; ++H[h], ++V[v];}

    }
    return 0;
}
