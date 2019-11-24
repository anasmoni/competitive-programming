#include<bits/stdc++.h>
#include<set>
#include<cstdlib>

using namespace std;

int main()
{
    int n,m=0 ;
    scanf("%d",&n);
    int a[n];

    for(int i=0 ; i<n ; i++)scanf("%d",&a[i]);

    set<int>s(a,a+n);
    multiset<int>ms(a,a+n);

    if(n==s.size())
    {
        cout<<"-1";
        return 0 ;
    }

    set<int>::iterator it;
    multiset<int>::iterator itm;
    int mx=0,val,ans[n];

    for(; itm != ms.end();itm++)
    {
        if(mx<ms.count(*itm))mx = ms.count(*itm) , val = *itm;
    }

    memset(ans,0,n);
    for(int i=0 ; i<n ; i++)
    {
        i//f(a[i]==a[i+1] && a[i]==mx);
        cout<<ans[i]<<" ";
    }


    return 0;
}
