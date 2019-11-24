#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0 ; i<n ; i++)cin>>a[i];

    sort(a,a+n);
    int len = unique(a,a+n) - a ; /** how many unique elements = len */
    //cout<<len;
    if(len<3)cout<<"YES";
    else if(len>3)cout<<"NO";
    else
    {
        sort(a,a+n);
        for(int i=0 ; i<n ; i++)
        {
            if(a[i]!=a[0] && a[i]!=a[n-1])
            {
                if(a[i]-a[0]==a[n-1]-a[i])cout<<"YES";
                else cout<<"NO";
                break;
            }
        }

    }


    return 0 ;
}
