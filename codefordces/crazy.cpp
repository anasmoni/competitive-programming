#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,c,sum=1;
    cin>>n>>c;
    int a[n];
    for(int i=0 ; i<n ; i++)
    {
        cin>>a[i];
        if(i)
        {
            if(a[i]-a[i-1] > c)sum=1;
            else sum++;
        }
    }
    cout<<sum;

    return 0 ;
}
