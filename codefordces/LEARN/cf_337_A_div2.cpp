#include<bits/stdc++.h>

using namespace std;

int main()
{
    double i,n ; scanf("%lf",&n);
    int ans=0;
    for(i=1 ; (n-2*i)/2 >0 && (n-2*i)/2 !=i ; i++)
    {
        int m=(n-2*i)/2;
        if(m == (n-2*i)/2.0)ans++;
    }

    cout<<ans;

    return 0 ;
}

