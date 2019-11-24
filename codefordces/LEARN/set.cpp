#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0 ; i<n ; i++)cin>>a[i];

    set<int>s(a,a+n);
    int len = s.size();
    //cout<<len;
    sort(a,a+n);
    if(len<3)cout<<"YES";
    else if(len>3)cout<<"NO";
    else
    {
        set<int>::iterator it;
        it = s.upper_bound(a[0]);
        if(*it-a[0]==a[n-1]-*it)cout<<"YES";
        else cout<<"NO";

    }


    return 0 ;
}

