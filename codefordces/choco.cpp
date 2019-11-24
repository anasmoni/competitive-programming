#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n  , idx=-1 ;
    cin>>n ;
    long long int ans = 0 ;
    for(int i=0 ; i<n ; i++)
    {
        int x;
        cin>>x;
        if(x)
        {
            if(idx<0)ans = 1 ;
            else ans *= i-idx ;
            idx=i ;
        }
    }
    cout<<ans;
    return 0 ;
}
