#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    int n  ;
    cin>>n;
    long long int a[n] , i ,d=7 ;
    for(i=0 ; i<n ; i++)scanf("%I64d",&a[i]);

    sort(a,a+n);

    if(a[n-1]==a[0] || (a[n-1]==a[0] && a[n-2]==a[1]))
    {
        cout<<"YES";
        return 0 ;
    }

    cout<<"NO";

    return 0 ;
}

