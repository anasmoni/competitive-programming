#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n ,mx=-1 ; cin>>n ; int a[n][2];  if(n==1){cout<<"-1"; return 0;}

    for(int i=0 ; i<n ; i++)cin>>a[i][0]>>a[i][1];

    for(int i=0  ; i<n ; i++)
    {
        for(int j=i+1 ; j<n ; j++)
        {

            if((a[i][0]!=a[j][0]) && (a[i][1]!=a[j][1])){ mx = abs(a[i][0]-a[j][0])*abs(a[i][1]-a[j][1]);}

        }
    }


    cout<<mx;


    return 0;
}
