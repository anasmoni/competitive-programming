#include<bits/stdc++.h>
using namespace std;
int b[12] , ans ;

int main()
{
    int n,m; cin>>n>>m; int a[n];

    for(int i=0 ; i<n ; i++){cin>>a[i] ; ++b[a[i]] ;}

    for(int i=1 ; i<11 ; i++)
    {
        ans += (n-b[i])*b[i]; n-= b[i];
    }

    cout<<ans;


    return 0;
}
