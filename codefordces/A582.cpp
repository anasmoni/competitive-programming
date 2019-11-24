#include<bits/stdc++.h>
using namespace std;
map<int,int>mp; int b[600];
int main()
{
    int n,mark=0 ;
    cin>>n ;
    int a[n*n];

    for(int i=0 ; i<n*n ; i++)
    {
        scanf("%d",&a[i]);
        mp[a[i]]++;
    }

    sort(a,a+n*n);


    //for(int i=0; i<n*n ; i++)cout<<a[i]<<" ";
    //cout<<endl;

    for(int i=n*n-1 ; i>=0 ; i--)
    {

        if(mp[a[i]]>0)
        {
            cout<<a[i]<<" ";

            for(int k=n*n-1 ; k>=i ; k--)mp[__gcd(a[i],a[k])]-=2;
            mp[a[i]]--;
        }
    }

    return 0;
}
