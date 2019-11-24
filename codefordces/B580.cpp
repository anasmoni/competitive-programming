#include<bits/stdc++.h>
using namespace std;

int n,d;
long long  mx=-1 , ans,m[100005],f;
pair<long long , long long>mp[100005];

int main()
{
    cin>>n>>d;

    for(int i=0 ; i<n ; i++){cin>>mp[i].first>>mp[i].second;}

    sort(mp,mp+n);


    for(int j=0,i=0 ; i<n ; )
    {
        if(mp[i].first-mp[j].first>=d)f -= mp[j++].second ;
        else f += mp[i++].second ;
        ans = max(ans,f);
    }

    cout<<ans;

    return 0;
}


