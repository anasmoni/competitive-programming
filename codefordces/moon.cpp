#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n ; int a[n];

    for(int i=0 ; i<n ; i++)cin>>a[i];

    if(n>1)
    {
        if(a[n-1]>a[n-2])
        {
            if(a[n-1]==15)cout<<"DOWN";
            else cout<<"UP";
        }
        else
        {
            if(a[n-1])cout<<"DOWN";
            else cout<<"UP";
        }
    }
    else
    {
        if(!a[0])cout<<"UP";
        else if(a[0]==15)cout<<"DOWN";
        else cout<<"-1";
    }

    return 0;
}
