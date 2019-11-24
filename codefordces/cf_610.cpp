#include<bits/stdc++.h>

using namespace std;
long long int n,mn=2e15,idx,ans=0;
int main()
{
    scanf("%I64d",&n); long long int a[n];
    for(long long int i=0 ; i<n ; i++)
    {
        scanf("%I64d",&a[i]);
        if(mn>=a[i]){mn=a[i]; mn==a[i]?idx=i+1:idx=idx;}
    }
    //cout<<mn<<endl;
    int h;
    for(int i=0 ; i<n ; i++){if(a[i]==mn){h=i; break;}}
    if(idx==n)
    {
        for(int i=idx-1 ; i>=h ; i--){if(a[i]==mn){idx=i+1;break;}}
    }

    printf("%I64d",(mn*n+n-idx+h));

    return 0 ;
}

