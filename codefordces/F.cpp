#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n ,ans=0 ; scanf("%I64d",&n) ;

    vector<long long int>v[n+1];

    for(long long int i=1 ; i<=n ; i++)
    {
        for(long long int j=i ; j<=n ; j+=i)v[j].push_back(i);
    }

    for(long long int i=6 ; i<=n ; i++)
    {
        if(v[i].size()==4)ans++;
    }

    printf("%I64d",ans);


    return 0;
}
