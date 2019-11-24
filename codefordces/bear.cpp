#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],sum=0 , limak;

    for(int i=0 ; i<n ; cin>>a[i++]);

    limak = a[0];

    sort(a,a+n);
    if(limak>=a[n-1] && limak>a[n-2]){cout<<"0"; return 0;}


    while(limak<=a[n-1]){ --a[n-1] ; sort(a,a+n); sum++ , limak++ ;}

    cout<<sum;

    return 0;
}
